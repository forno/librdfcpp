#include <iostream>

#include <rdfcpp/resource/iterator.hpp>
#include <rdfcpp/resource/model.hpp>
#include <rdfcpp/resource/node.hpp>
#include <rdfcpp/resource/parser.hpp>
#include <rdfcpp/resource/statement.hpp>
#include <rdfcpp/resource/storage.hpp>
#include <rdfcpp/resource/stream.hpp>
#include <rdfcpp/resource/uri.hpp>
#include <rdfcpp/resource/world.hpp>
#include <rdfcpp/raptor/resource/iostream.hpp>
#include <rdfcpp/raptor/resource/world.hpp>

int main(int argc, char** argv)
{
  auto program {argv[0]};

  auto uri_name {argc >= 2 ? argv[1] : "http://ja.dbpedia.org/data/%E3%83%AD%E3%82%A4%E3%83%84%E3%83%9E%E3%83%BB%E3%82%AC%E3%83%BC%E3%83%AB.rdf"};
  auto parser_name {argc >= 3 ? argv[2] : ""};

  auto world {rdf::resource::new_world()};
  rdf::resource::open(world);
  auto raptor_world_ptr {rdf::raptor::resource::get_raptor(world)};

  auto uri {rdf::resource::new_uri(world, uri_name)};
  if (!uri) {
    std::cerr << program << ": Failed to create URI\n";
    return 1;
  }

  auto storage {rdf::resource::new_storage(world, "memory", "test", "")};
  if (!storage) {
    std::cerr << program << ": Failed to create new storage\n";
    return 1;
  }

  auto model {rdf::resource::new_model(world, storage, "")};
  if (!model) {
    std::cerr << program << ": Failed to create model\n";
    return 1;
  }

  {
    auto parser {rdf::resource::new_parser(world, parser_name, "", nullptr)};
    if (!parser) {
      std::cerr << program << ": Failed to create new parser\n";
      return 1;
    }

    /* PARSE the URI as RDF/XML*/
    std::cout << program << ": Parsing URI " << rdf::resource::to_string(uri) << '\n';
    if (rdf::resource::parse(parser, uri, uri, model)) {
      std::cerr << program << ": Failed to parse RDF into model\n";
      return 1;
    }
  }

  {
    auto statement2 {rdf::resource::new_statement(
      world,
      rdf::resource::new_node(world, "http://www.dajobe.org/"),
      rdf::resource::new_node(world, "http://purl.org/dc/elements/1.1/title"),
      rdf::resource::new_node(world, "My Home Page", "", false))};
    rdf::resource::add_statement(model, statement2);
  }

  /* Print out the model*/
  std::cout << program << ": Resulting model is:\n";
  {
    auto iostr {rdf::raptor::resource::new_iostream(raptor_world_ptr, stdout)};
    rdf::resource::write(model, iostr);
  }


  /* Construct the query predicate (arc) and object (target) 
   * and partial statement bits
   */
  auto subject {rdf::resource::new_node(world, "http://www.dajobe.org/")};
  auto predicate {rdf::resource::new_node(world, "http://purl.org/dc/elements/1.1/title")};
  if (!subject || !predicate) {
    std::cerr << program << ": Failed to create nodes for searching\n";
    return 1;
  }

  auto partial_statement {rdf::resource::new_statement(world)};
  rdf::resource::set_subject(partial_statement, subject);
  rdf::resource::set_predicate(partial_statement, predicate);


  /* QUERY TEST 1 - use find_statements to match */

  std::cout << program << ": Trying to find_statements\n";
  if (auto stream {rdf::resource::find_statements(model, partial_statement)}; !stream) {
    std::cerr << program << ": librdf_model_find_statements returned nullptr stream\n";
  } else {
    auto count {0};
    while (!rdf::resource::end(stream)) {
      auto statement {rdf::resource::get_object(stream)};
      if (!statement) {
        std::cerr << program << ": librdf_stream_next returned nullptr\n";
        break;
      }

      std::cout << "  Matched statement: \n";
      rdf::resource::print(statement, stdout);
      std::cout.put('\n');

      rdf::resource::next(stream);
      ++count;
    }
    std::cerr << program << ": got " << count << " matching statements\n";
  }


  /* QUERY TEST 2 - use get_targets to do match */
  std::cout << program << ": Trying to get targets\n";
  {
    auto iterator {rdf::resource::get_targets(model, subject, predicate)};
    if (!iterator) {
      std::cerr << program << ": librdf_model_get_targets failed to return iterator for searching\n";
      return 1;
    }

    auto count {0u};
    while(!rdf::resource::end(iterator)) {
      auto target {rdf::resource::get_node(iterator)};
      if (!target) {
        std::cerr << program << ": librdf_iterator_get_object returned nullptr\n";
        break;
      }

      fputs("  Matched target: ", stdout);
      rdf::resource::print(target, stdout);
      fputc('\n', stdout);

      count++;
      rdf::resource::next(iterator);
    }
    std::cerr << program << ": got " << count << " target nodes\n";
  }

  return 0;
}
