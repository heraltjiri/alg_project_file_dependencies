cmake_minimum_required(VERSION 3.21)
project(ALG2_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(ALG2_project main.cpp src/DataImporter.cpp src/DataImporter.h src/Graph.cpp src/Graph.h src/GraphNode.cpp src/GraphNode.h)
