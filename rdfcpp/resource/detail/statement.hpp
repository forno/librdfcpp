/*
resource/detail/statement.hpp

Copylight 2018 Doi Yusuke

This file is part of rdfcpp.

rdfcpp is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

rdfcpp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with rdfcpp.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef RDFCPP_RESOUCE_DETAIL_STATEMENT_H
#define RDFCPP_RESOUCE_DETAIL_STATEMENT_H

#include "../statement.hpp"

inline std::shared_ptr<librdf_statement> rdf::resource::new_statement(const std::shared_ptr<librdf_world>& world)
{
  return {
    librdf_new_statement(world.get()),
    [](auto p){librdf_free_statement(p);}
  };
}

inline std::shared_ptr<librdf_statement> rdf::resource::new_statement(
  const std::shared_ptr<librdf_world>& world,
  const std::shared_ptr<librdf_node>& subject,
  const std::shared_ptr<librdf_node>& predicate,
  const std::shared_ptr<librdf_node>& object)
{
  return {
    librdf_new_statement_from_nodes(world.get(), subject.get(), predicate.get(), object.get()),
    [](auto p){librdf_free_statement(p);}
  };
}

inline std::shared_ptr<librdf_statement> rdf::resource::get_object(const std::shared_ptr<librdf_stream>& stream)
{
  return {
    librdf_stream_get_object(stream.get()),
    [](auto){}
  };
}

void rdf::resource::set_subject(
  const std::shared_ptr<librdf_statement>& statement,
  const std::shared_ptr<librdf_node>& subject) noexcept
{
  librdf_statement_set_subject(statement.get(), subject.get());
}

void rdf::resource::set_predicate(
  const std::shared_ptr<librdf_statement>& statement,
  const std::shared_ptr<librdf_node>& predicate) noexcept
{
  librdf_statement_set_predicate(statement.get(), predicate.get());
}

void rdf::resource::print(
  const std::shared_ptr<librdf_statement>& statement,
  std::FILE* handle) noexcept
{
  librdf_statement_print(statement.get(), handle);
}

#endif
