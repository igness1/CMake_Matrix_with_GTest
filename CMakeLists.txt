cmake_minimum_required (VERSION 3.8)

project ("Matrix")

project(${THIS} C CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
	CMake_MatrixClass.cpp
)
set(Sources
	CMake_MatrixClass.hpp
)

add_library(${This} STATIC ${Sources} ${Headers})

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (Matrix   "CMake_MatrixClass.cpp" "CMake_MatrixClass.hpp" "main.cpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
