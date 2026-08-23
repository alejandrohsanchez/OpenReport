cmake_minimum_required(VERSION 3.25)

project(
    OpenReport
    VERSION 0.1.0
    DESCRIPTION "Local-first manufacturing quality report generator"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(OPENREPORT_BUILD_TESTS "Build OpenReport tests" ON)

add_subdirectory(core)
add_subdirectory(app)

if (OPENREPORT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()