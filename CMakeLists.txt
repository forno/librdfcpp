cmake_minimum_required(VERSION 3.13)
project(rdfcpp
  VERSION 0.0.1
  DESCRIPTION "The c++ library for RDF operations."
  HOMEPAGE_URL https://github.com/forno/librdfcpp
  LANGUAGES CXX)
set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type for only meaningful to single-configuration generators")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS RelWithDebInfo Release Debug MinSizeRel)

option(ENABLE_TEST "Add build target for gtest" OFF)

if(ENABLE_TEST)
  include_directories(.)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
  enable_testing()
  add_subdirectory(test)
endif()

add_subdirectory(doxygen)

install(DIRECTORY "${PROJECT_NAME}" DESTINATION include)
