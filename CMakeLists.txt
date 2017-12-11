cmake_minimum_required(VERSION 3.6)
project(Sightings)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c observers.h sightings.h file_management.h file_management.c observers.c sightings.c)
add_executable(Sightings ${SOURCE_FILES})