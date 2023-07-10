cmake_minimum_required(VERSION 3.18)
project(libjsc VERSION 0.0.1 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32)
  # Fix warning about default DOWNLOAD_EXTRACT_TIMESTAMP in CMake >=3.24
  if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
  endif()
  include(FetchContent)
  # TODO: We only fetch this huge package because of ICU
  # Ideally, we can vendor and build ICU...
  set(WEBKIT_REQUIREMENTS_BASE_URL "https://github.com/WebKitForWindows/WebKitRequirements/releases/download")
  set(WEBKIT_REQUIREMENTS_URL "${WEBKIT_REQUIREMENTS_BASE_URL}/v2023.06.14/WebKitRequirementsWin64.zip")
  set(WEBKIT_REQUIREMENTS_HASH_MD5 "3c2e07bfc5675ac1e2f0c8c1d6562508")
  FetchContent_Declare(webkit_windows_requirements
    URL "${WEBKIT_REQUIREMENTS_URL}"
    URL_HASH "MD5=${WEBKIT_REQUIREMENTS_HASH_MD5}"
    TLS_VERIFY true)
  message(STATUS "Fetching ${WEBKIT_REQUIREMENTS_URL}")
  FetchContent_MakeAvailable(webkit_windows_requirements)
  set(WEBKIT_LIBRARIES_DIR "${webkit_windows_requirements_SOURCE_DIR}" CACHE STRING "WebKit dependencies")
endif()

set(WEBKIT_DIRECTORY "${PROJECT_SOURCE_DIR}/vendor/webkit")
set(WTF_DIR "${WEBKIT_DIRECTORY}/Source/WTF" CACHE STRING "WTF directory")
set(JAVASCRIPTCORE_DIR "${WEBKIT_DIRECTORY}/Source/JavaScriptCore" CACHE STRING "JSC directory")
set(PORT "JSCOnly" CACHE STRING "build only JSC")
if(WIN32)
  set(ENABLE_FTL_JIT OFF CACHE BOOL "disable JIT")
  set(ENABLE_WEBASSEMBLY OFF CACHE BOOL "disable WebAssembly")
  set(ENABLE_WEBASSEMBLY_B3JIT OFF CACHE BOOL "disable WebAssembly B3JIT")
  set(ENABLE_WEBASSEMBLY_BBQJIT OFF CACHE BOOL "disable WebAssembly BBQJIT")
else()
  set(ENABLE_FTL_JIT ON CACHE BOOL "enable JIT")
endif()
set(ENABLE_TOOLS OFF CACHE BOOL "disable WebKit tools")
set(ENABLE_STATIC_JSC ON CACHE BOOL "build JSC as a static library")
set(USE_SYSTEM_MALLOC ON CACHE BOOL "use system malloc on JSC")
add_subdirectory(vendor/webkit)

add_executable(jsc_test test.cc)
target_link_libraries(jsc_test PRIVATE JavaScriptCore)
