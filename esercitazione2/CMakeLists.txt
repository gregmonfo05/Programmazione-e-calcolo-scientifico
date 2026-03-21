cmake_minimum_required(VERSION 3.20)
project(esercitazione2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(esempio_1 esempio_1.cpp)
add_executable(esercizio_primi_algoritmi esercizio_primi_algoritmi.cpp) 
add_executable(esercizio_bubble_sort algoritmo_bubble_sort.cpp) 