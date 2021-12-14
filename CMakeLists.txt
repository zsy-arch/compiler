cmake_minimum_required(VERSION 3.21)
project(compiler_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(compiler_1 main.cpp Compiler.Lexer.cpp Compiler.Lexer.h)
