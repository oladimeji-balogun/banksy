cmake_minimum_required(VERSION 3.20)
project(banksy VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    src/account.cpp
    src/transaction.cpp
    src/bank.cpp
    src/file_store.cpp
    src/main.cpp
)

add_executable(banksy ${SOURCES})

target_include_directories(banksy PRIVATE include)