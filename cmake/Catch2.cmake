if(BUILD_TESTS)
    add_subdirectory(third_party/Catch2)
endif()

# Builds only when -DBUILD_TESTS=ON 