
    include(CMakePackageConfigHelpers)

    export(
        TARGETS ember
        NAMESPACE ember::
        FILE "${CMAKE_CURRENT_BINARY_DIR}/emberTargets.cmake"
    )

    configure_package_config_file(
        "${CMAKE_CURRENT_LIST_DIR}/emberConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/emberConfig.cmake"
        INSTALL_DESTINATION "."
        NO_SET_AND_CHECK_MACRO
        NO_CHECK_REQUIRED_COMPONENTS_MACRO
    )

    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/emberConfigVersion.cmake"
        VERSION "${PROJECT_VERSION}"
        COMPATIBILITY SameMajorVersion
    )
