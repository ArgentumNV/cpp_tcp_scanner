cmake_minimum_required(VERSION 3.20)
project(cpp_tcp_scanner)


if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    message(STATUS "Тип сборки не задан, используется Debug")
endif()

add_executable(scanner src/main.cpp)

target_compile_options(scanner PRIVATE -Wall -Wextra -std=c++17)

message(STATUS "Сборка завершена")