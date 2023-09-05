cmake_minimum_required(VERSION 3.26)
project(compiler C)

set(CMAKE_C_STANDARD 11)
include_directories("C:\\Users\\udbe3\\AppData\\Local\\Programs\\CLion\\bin\\mingw\\x86_64-w64-mingw32\\include\\string.h")
add_executable(compiler src/main.c
        src/Lexer.h
        src/Lexer.c)
