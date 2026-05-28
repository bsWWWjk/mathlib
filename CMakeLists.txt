cmake_minimum_required(VERSION 3.15)
project(mathlib VERSION 1.0.0)
 
# Говорим CMake что mathlib - это header-only библиотека (только .h файлы, нет .cpp)
# Она просто предоставляет заголовочные файлы
add_library(mathlib INTERFACE)
 
# Говорим компилятору где искать заголовочные файлы этой библиотеки
# Без этого #include <mathlib/math.h> выдаст ошибку "file not found"
target_include_directories(mathlib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
