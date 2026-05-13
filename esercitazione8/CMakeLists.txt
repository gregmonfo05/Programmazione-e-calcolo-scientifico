cmake_minimum_required(VERSION 3.20)
project(esercitazione8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


add_executable(unidirected_edge_test unidirected_edge_test.cpp)
add_test(NAME unidirected_edge COMMAND unidirected_edge_test)


add_executable(unidirected_graph_test unidirected_graph_test.cpp)
add_test(NAME unidirected_graph COMMAND unidirected_graph_test)

enable_testing()
