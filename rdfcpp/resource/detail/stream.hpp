/*
resource/detail/stream.hpp

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

#ifndef RDFCPP_RESOUCE_DETAIL_STREAM_H
#define RDFCPP_RESOUCE_DETAIL_STREAM_H

#include "../stream.hpp"

inline std::shared_ptr<librdf_stream> rdf::resource::find_statements(
  const std::shared_ptr<librdf_model>& model,
  const std::shared_ptr<librdf_statement>& statement)
{
  return {
    librdf_model_find_statements(model.get(), statement.get()),
    [](auto p){librdf_free_stream(p);}
  };
}

bool rdf::resource::end(const std::shared_ptr<librdf_stream>& stream) noexcept
{
  return librdf_stream_end(stream.get());
}

bool rdf::resource::next(const std::shared_ptr<librdf_stream>& stream) noexcept
{
  return librdf_stream_next(stream.get());
}

#endif
