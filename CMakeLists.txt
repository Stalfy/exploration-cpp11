# #############################################################################
# Set the CMAKE requirements
# #############################################################################
cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

# #############################################################################
# Set the build variables
# #############################################################################
set(PROJECT_COMPILE_NAME exploration)
set(COMPILER_FLAGS project_compiler_flags)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER "C:\\ProgramData\\mingw64\\mingw64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\ProgramData\\mingw64\\mingw64\\bin\\g++.exe")
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

project(${PROJECT_COMPILE_NAME})

# #############################################################################
# Add the libraries
# #############################################################################
add_library(${COMPILER_FLAGS} INTERFACE)

# #############################################################################
# Compile the project
# #############################################################################
add_subdirectory(sources)
