# CMakeList.txt: projekt CMake dla elementu Matrix, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("Matrix")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (Matrix   "CMake_MatrixClass.cpp" "CMake_MatrixClass.hpp" "main.cpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
