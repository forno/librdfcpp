/*
raptor/resource/iostream.hpp

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

#ifndef RDFCPP_RAPTOR_RESOURCE_IOSTREAM_H
#define RDFCPP_RAPTOR_RESOURCE_IOSTREAM_H

/**
 * @file rdfcpp/raptor/resource/iostream.hpp
 * @brief The raptor iostream resource of librdf with RAII.
 */

#include <cstdio>
#include <memory>

#include <redland.h>

namespace rdf::raptor::resource
{

std::shared_ptr<raptor_iostream> new_iostream(
  const std::shared_ptr<raptor_world>& world,
  std::FILE* handle);

}

#include "detail/iostream.hpp"

#endif
