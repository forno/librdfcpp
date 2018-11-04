/*
resource/detail/node.hpp

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

#ifndef RDFCPP_RESOUCE_DETAIL_NODE_H
#define RDFCPP_RESOUCE_DETAIL_NODE_H

#include "../node.hpp"

std::shared_ptr<librdf_node> rdf::resource::new_node(
  const std::shared_ptr<librdf_world>& world,
  const std::string& uri_string)
{
  return {
    librdf_new_node_from_uri_string(world.get(), reinterpret_cast<const unsigned char*>(uri_string.data())),
    [](auto){}
  };
}

std::shared_ptr<librdf_node> rdf::resource::new_node(
  const std::shared_ptr<librdf_world>& world,
  const std::string& string,
  const std::string& xml_language,
  bool is_wf_xml)
{
  return {
    librdf_new_node_from_literal(
      world.get(),
      reinterpret_cast<const unsigned char*>(string.data()),
      xml_language.empty() ? nullptr : xml_language.data(),
      static_cast<int>(is_wf_xml)),
    [](auto){}
  };
}

std::shared_ptr<librdf_node> rdf::resource::get_node(const std::shared_ptr<librdf_iterator>& iterator)
{
  return {
    static_cast<librdf_node*>(librdf_iterator_get_object(iterator.get())),
    [](auto){}
  };
}

void rdf::resource::print(
  const std::shared_ptr<librdf_node>& node,
  std::FILE* fd) noexcept
{
  librdf_node_print(node.get(), fd);
}

#endif
