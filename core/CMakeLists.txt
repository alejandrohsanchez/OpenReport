add_library(
    openreport_core
    STATIC
        src/actions/LoadCsvAction.cpp    
)

target_include_directories(
    openreport_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(openreport_core PUBLIC cxx_std_20)