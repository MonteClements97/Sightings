cmake_minimum_required(VERSION 3.6)
project(Sightings)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c observers.h sightings.h file_management.h file_management.c observers.c sightings.c conversion_using_math.h conversion_using_math.c)
add_executable(Sightings ${SOURCE_FILES})
target_link_libraries(Sightings m)