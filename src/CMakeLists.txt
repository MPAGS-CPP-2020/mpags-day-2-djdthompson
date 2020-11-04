#- Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

#want all command lines to be outputted as default when generating makefiles  (equiv to VERBOSE=1)
set(CMAKE_VERBOSE_MAKEFILE ON)

#set the standard C++ library
#set(CMAKE_CXX_STANDARD 11)

# Declare how the main program for mpags-cipher is built, including program file and executable name
add_executable(mpags-cipher mpags-cipher.cpp MPAGSCipher/transformChar.cpp MPAGSCipher/transformChar.hpp MPAGSCipher/processCmdLine.hpp MPAGSCipher/processCmdLine.cpp MPAGSCipher/runCaesarCipher.hpp MPAGSCipher/runCaesarCipher.cpp)

target_include_directories(mpags-cipher PRIVATE MPAGSCipher)

set(CMAKE_CXX_EXTENSIONS OFF)
#set the flags for compiler

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
    )
