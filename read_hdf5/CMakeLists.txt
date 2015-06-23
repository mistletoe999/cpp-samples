cmake_minimum_required(VERSION 3.1)
project(read_hdf5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)


message("Finding HDF5 libraries...")


include_directories(/usr/local/include)

add_executable(read_hdf5 ${SOURCE_FILES})

target_link_libraries(read_hdf5 -lhdf5_cpp -lhdf5)