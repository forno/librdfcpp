find_package(Doxygen)

if(DOXYGEN_FOUND)
  set(DOXYGEN_EXCLUDE_PATTERNS "*/detail/*")

  doxygen_add_docs(doc
    rdfcpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()
