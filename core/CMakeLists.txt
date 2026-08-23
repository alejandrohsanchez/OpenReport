add_library(openreport_core INTERFACE)

target_include_directories(
    openreport_core
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(openreport_core INTERFACE cxx_std_20)