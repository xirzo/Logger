cmake_minimum_required(VERSION 3.24.5)

project(logger VERSION 1.0.0 LANGUAGES C)

add_library(logger STATIC src/logger.c)

target_include_directories(logger PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS logger
    EXPORT logger-targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT logger-targets
    FILE logger-config.cmake
    NAMESPACE logger::
    DESTINATION lib/cmake/logger
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/logger-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/logger-config.cmake
    INSTALL_DESTINATION lib/cmake/logger
)

write_basic_package_version_file(
    logger-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/logger-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/logger-config-version.cmake
    DESTINATION lib/cmake/logger
)
