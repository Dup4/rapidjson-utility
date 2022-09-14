option(RAPIDJSON_UTILITY_BUILD_TESTS "Build all of rapidjson-utility's own tests." OFF)

cmake_minimum_required(VERSION 3.14)

project(rapidjson-utility VERSION 0.0.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

include(FetchContent)

FetchContent_Declare(
    rapidjson
    GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
    GIT_TAG v1.1.0
)

FetchContent_Declare(
    result_cpp
    GIT_REPOSITORY https://github.com/Dup4/result-cpp.git
    GIT_TAG v0.0.14
)

set(RAPIDJSON_BUILD_DOC OFF CACHE INTERNAL "")
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(RAPIDJSON_BUILD_TESTS OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(rapidjson result_cpp)
FetchContent_GetProperties(rapidjson result_cpp)
set(RAPIDJSON_INCLUDE_DIR ${rapidjson_SOURCE_DIR}/include)
set(RESULT_CPP_INCLUDE_DIR ${result_cpp_SOURCE_DIR}/include)

include_directories(
    ${PROJECT_SOURCE_DIR}/include/
    ${RAPIDJSON_INCLUDE_DIR}
    ${RESULT_CPP_INCLUDE_DIR}
)

add_library(rapidjson-utility INTERFACE)
target_include_directories(rapidjson-utility INTERFACE
    ${PROJECT_SOURCE_DIR}/include/
    ${RAPIDJSON_INCLUDE_DIR}
    ${RESULT_CPP_INCLUDE_DIR}
)

if(RAPIDJSON_UTILITY_BUILD_TESTS)
    enable_testing()

    add_subdirectory(test/)
endif()
