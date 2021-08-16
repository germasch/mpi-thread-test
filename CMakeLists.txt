cmake_minimum_required(VERSION 3.18)

project(mpi-thread LANGUAGES CXX)

find_package(MPI)

add_executable(test test.cxx)
target_compile_features(test PRIVATE cxx_std_11)
target_link_libraries(test PRIVATE MPI::MPI_CXX)
