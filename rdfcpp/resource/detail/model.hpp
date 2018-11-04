/*
resource/detail/model.hpp

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

#ifndef RDFCPP_RESOUCE_DETAIL_MODEL_H
#define RDFCPP_RESOUCE_DETAIL_MODEL_H

#include "../model.hpp"

inline std::shared_ptr<librdf_model> rdf::resource::new_model(
  const std::shared_ptr<librdf_world>& world,
  const std::shared_ptr<librdf_storage>& storage,
  const std::string& options_string)
{
  return {
    librdf_new_model(world.get(), storage.get(), options_string.data()),
    [](auto p){librdf_free_model(p);}
  };
}

inline bool rdf::resource::write(
  const std::shared_ptr<librdf_model>& model,
  const std::shared_ptr<raptor_iostream>& iostream) noexcept
{
  return librdf_model_write(model.get(), iostream.get());
}

inline bool rdf::resource::add_statement(
  const std::shared_ptr<librdf_model>& model,
  const std::shared_ptr<librdf_statement>& statement) noexcept
{
  return librdf_model_add_statement(model.get(), statement.get());
}

#endif
