    
    target_compile_options(ember PRIVATE
        -Werror
        -Wconversion
        -Wfloat-conversion
    )

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(ember PRIVATE
            -Wno-write-strings
            -Wno-sign-compare
            -O0
            -ggdb
            -g
            -Wall
            -fanalyzer
            -DDEBUG
        )
    endif()

    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(ember PRIVATE
            -Wno-write-strings
            -Wno-sign-compare
            -O3
        )
    endif()

