/*
resource/storage.hpp

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

#ifndef RDFCPP_RESOUCE_STORAGE_H
#define RDFCPP_RESOUCE_STORAGE_H

/**
 * @file rdfcpp/resource/storage.hpp
 * @brief The storage resource of librdf with RAII.
 */

#include <memory>
#include <string>

#include <redland.h>

namespace rdf::resource
{

std::shared_ptr<librdf_storage> new_storage(
  const std::shared_ptr<librdf_world>& world,
  const std::string& storage_name,
  const std::string& name,
  const std::string& options_string);

}

#include "detail/storage.hpp"

#endif
