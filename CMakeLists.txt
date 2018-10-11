# Project Definition
#
cmake_minimum_required(VERSION 3.8.2)
project(OSDevTools)

# Exported Library
#
add_library(OSDevTools STATIC
    src/OSTools.cpp
    src/env.cpp
    include/OSTools.h
    include/env.h
)

target_compile_features(OSDevTools PUBLIC cxx_std_17)

target_link_libraries(OSDevTools PUBLIC stdc++fs)

target_include_directories(OSDevTools PUBLIC
    $<BUILD_INTERFACE:${OSDevTools_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set_property(TARGET OSDevTools PROPERTY PUBLIC_HEADER
    ${OSDevTools_SOURCE_DIR}/include/env.h
    ${OSDevTools_SOURCE_DIR}/include/OSTools.h
)


#
# Instructions for installing the build output
#
install(TARGETS OSDevTools EXPORT OSDevToolsTargets
    ARCHIVE       DESTINATION lib
    INCLUDES      DESTINATION include
    PUBLIC_HEADER DESTINATION include
)

#
# Generate a Targets file which will capture the
# INTERFACE requirements of the library for linking
#
install (EXPORT OSDevToolsTargets
    FILE        OSDevToolsTargets.cmake
    NAMESPACE   OSDevTools::
    DESTINATION lib/cmake/OSDevTools
)

#
# Define our package version
#
include(CMakePackageConfigHelpers)
write_basic_package_version_file("OSDevToolsConfigVersion.cmake"
    VERSION       0.1
    COMPATIBILITY SameMajorVersion
)
install (
    FILES       ${OSDevTools_BINARY_DIR}/OSDevToolsConfigVersion.cmake
    DESTINATION lib/cmake/OSDevTools
)

#
# Finally export the Config which CMake will use
# when looking for matching libraries to link against.
#
install (
    FILES       OSDevToolsConfig.cmake
    DESTINATION lib/cmake/OSDevTools
)
