add_executable(em_time_tests test.cpp)

add_executable(em_time_temp_tests test_temp.cpp)

target_include_directories(em_time_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}
)

target_include_directories(em_time_temp_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(em_time_tests
    PRIVATE
    ember
    Catch2::Catch2WithMain
)

target_link_libraries(em_time_temp_tests
    PRIVATE
    ember
    Catch2::Catch2WithMain
)

add_test(NAME em_time_tests COMMAND em_time_tests)

add_test(NAME em_time_temp_tests COMMAND em_time_temp_tests)