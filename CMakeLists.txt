cmake_minimum_required(VERSION 3.0)
project(bead)

set(CMAKE_CXX_STANDARD 14)

add_executable(bead main.cpp colony.h cAnimals.h reader.h tundra.h)
