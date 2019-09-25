cmake_minimum_required(VERSION 3.14)
project(binary_search_tree_fabriziofranco)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(mocker)
include_directories(tester)

add_executable(binary_search_tree_fabriziofranco
        mocker/mocker.cpp
        mocker/mocker.h
        tester/tester.cpp
        tester/tester.h
        bstree.h
        iterator.h main.cpp node.h)
