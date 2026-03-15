cmake_minimum_required(VERSION 3.10)
project(BankomatSimulator)

set(CMAKE_CXX_STANDARD 17)

# Include papkasini qo'shish
include_directories(include)

# Source fayllarni topish
file(GLOB SOURCES "src/*.cpp")

# Executable yaratish
add_executable(bankomat ${SOURCES})

# Windows da konsol tozalash uchun
if (WIN32)
    target_compile_definitions(bankomat PRIVATE _WIN32)
endif()
