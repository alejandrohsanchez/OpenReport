add_executable(openreport_core_tests core_types_tests.cpp)
target_link_libraries(openreport_core_tests PRIVATE openreport_core)

add_test(
    NAME openreport_core_tests
    COMMAND openreport_core_tests
)