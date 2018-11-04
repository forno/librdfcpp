/*
resource/detail/uri.hpp

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

#ifndef RDFCPP_RESOUCE_DETAIL_URI_H
#define RDFCPP_RESOUCE_DETAIL_URI_H

#include "../uri.hpp"

inline std::shared_ptr<librdf_uri> rdf::resource::new_uri(
  const std::shared_ptr<librdf_world>& world,
  const std::string& uri)
{
  return {
    librdf_new_uri(world.get(), reinterpret_cast<const unsigned char*>(uri.data())),
    [](auto p){librdf_free_uri(p);}
  };
}

std::string rdf::resource::to_string(const std::shared_ptr<librdf_uri>& uri)
{
  return reinterpret_cast<const char*>(librdf_uri_as_string(uri.get()));
}

#endif
