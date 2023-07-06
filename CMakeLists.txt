cmake_minimum_required(VERSION 3.18)
project(libjsc VERSION 0.0.1 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(WEBKIT_DIRECTORY "${PROJECT_SOURCE_DIR}/vendor/webkit")
set(WTF_DIR "${WEBKIT_DIRECTORY}/Source/WTF" CACHE STRING "WTF directory")
set(JAVASCRIPTCORE_DIR "${WEBKIT_DIRECTORY}/Source/JavaScriptCore" CACHE STRING "JSC directory")
set(PORT "JSCOnly" CACHE STRING "build only JSC")
set(ENABLE_FTL_JIT ON CACHE BOOL "enable JIT")
set(ENABLE_TOOLS OFF CACHE BOOL "disable WebKit tools")
set(ENABLE_STATIC_JSC ON CACHE BOOL "build JSC as a static library")
set(USE_SYSTEM_MALLOC ON CACHE BOOL "use system malloc on JSC")
add_subdirectory(vendor/webkit)

add_executable(jsc_test test.cc)
target_link_libraries(jsc_test PRIVATE JavaScriptCore)
