#testing
add_executable(calculator_test_runner calculator_test.cpp)
target_link_libraries(calculator_test_runner PRIVATE calculator gtest_main)

add_executable(scientific_test_runner scientific_test.cpp)
target_link_libraries(scientific_test_runner PRIVATE scientific gtest_main)


# _TESTS
gtest_discover_tests(calculator_test_runner)
gtest_discover_tests(scientific_test_runner)

set_property(DIRECTORY APPEND PROPERTY
    TEST_INCLUDE_FILES ${CMAKE_CURRENT_LIST_DIR}/add_properties.cmake
)
