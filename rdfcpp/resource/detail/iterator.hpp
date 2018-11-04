/*
resource/detail/iterator.hpp

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

#ifndef RDFCPP_RESOUCE_DETAIL_ITERATOR_H
#define RDFCPP_RESOUCE_DETAIL_ITERATOR_H

#include "../iterator.hpp"

inline std::shared_ptr<librdf_iterator> rdf::resource::get_targets(
  const std::shared_ptr<librdf_model>& model,
  const std::shared_ptr<librdf_node>& source,
  const std::shared_ptr<librdf_node>& arc)
{
  return {
    librdf_model_get_targets(model.get(), source.get(), arc.get()),
    [](auto p){librdf_free_iterator(p);}
  };
}

bool rdf::resource::end(std::shared_ptr<librdf_iterator> iterator) noexcept
{
  return librdf_iterator_end(iterator.get());
}

bool rdf::resource::next(std::shared_ptr<librdf_iterator> iterator) noexcept
{
  return librdf_iterator_next(iterator.get());
}

#endif
