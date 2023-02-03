cmake_minimum_required(VERSION 3.10)
project(LinkedListTest)

include(GoogleTest)
add_subdirectory(googletest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(LinkedListTest test_LinkedList.cpp)
target_link_libraries(LinkedListTest gtest gtest_main)

# Add test target
enable_testing()
gtest_discover_tests(LinkedListTest)
