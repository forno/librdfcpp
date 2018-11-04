add_executable(test_example_example1 example1.cpp)
target_include_directories(test_example_example1 PUBLIC /usr/include/raptor2 PUBLIC /usr/include/rasqal)
target_link_libraries(test_example_example1 gmock_main rdf raptor2)
add_test(NAME test_example_example1 COMMAND test_example_example1)
