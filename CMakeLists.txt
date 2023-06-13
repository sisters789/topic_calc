cmake_minimum_required(VERSION 3.22)
project(Calculator)

# include to use gtest_discover_tests() and gtest_add_tests()
include(GoogleTest)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_subdirectory(src)
add_subdirectory(test)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE calculator scientific)
# target_include_directories(main PRIVATE "${PROJECT_BINARY_DIR}")

# need to place this on top-level directory of project
enable_testing()