/*
resource/node.hpp

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

#ifndef RDFCPP_RESOUCE_NODE_H
#define RDFCPP_RESOUCE_NODE_H

/**
 * @file rdfcpp/resource/node.hpp
 * @brief The node resource of librdf with RAII.
 */

#include <cstdio>
#include <memory>
#include <string>

#include <redland.h>

namespace rdf::resource
{

std::shared_ptr<librdf_node> new_node(
  const std::shared_ptr<librdf_world>& world,
  const std::string& uri_string);

std::shared_ptr<librdf_node> new_node(
  const std::shared_ptr<librdf_world>& world,
  const std::string& string,
  const std::string& xml_language,
  bool is_wf_xml);

std::shared_ptr<librdf_node> get_node(const std::shared_ptr<librdf_iterator>& iterator);

void print(
  const std::shared_ptr<librdf_node>& node,
  std::FILE* fd) noexcept;

}

#include "detail/node.hpp"

#endif
