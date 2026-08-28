add_executable(openreport_core_tests core_types_tests.cpp)
target_link_libraries(openreport_core_tests PRIVATE openreport_core)

add_test(
    NAME openreport_core_tests
    COMMAND openreport_core_tests
)

if (MINGW)
    get_filename_component(
        OPENREPORT_MINGW_RUNTIME_DIRECTORY
        "${CMAKE_CXX_COMPILER}"
        DIRECTORY
    )

    set_tests_properties(
        openreport_core_tests
        PROPERTIES
            ENVIRONMENT_MODIFICATION
                "PATH=path_list_prepend:${OPENREPORT_MINGW_RUNTIME_DIRECTORY}"
    )
endif()

configure_file(
    data/measurements.csv
    data/measurements.csv
    COPYONLY
)