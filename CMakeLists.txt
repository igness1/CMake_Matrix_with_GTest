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

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests tests.cc)

target_link_libraries(
	tests
	gtest_main
)

add_test(
	NAME MatrixTest
	COMMAND tests
)

add_library(${This} STATIC ${Sources} ${Headers})

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (Matrix   "CMake_MatrixClass.cpp" "CMake_MatrixClass.hpp" "main.cpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
