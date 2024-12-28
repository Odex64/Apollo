cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

# Enable experimental standard modules
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

# Project name
project("Apollo" LANGUAGES CXX)

# Set language attributes
set(CMAKE_CXX_STANDARD 23) # Set C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure standard
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler specific language extensions
set(CMAKE_CXX_MODULE_STD ON) # Enable experimental standard modules

# Add sources
add_executable(${PROJECT_NAME})
file(GLOB_RECURSE SOURCES "src/*.ixx")
target_sources(${PROJECT_NAME} PRIVATE FILE_SET CXX_MODULES FILES ${SOURCES})

# Windows setup
if (WIN32)
    # Enable Hot Reload for MSVC compilers if supported.
    if (POLICY CMP0141)
        cmake_policy(SET CMP0141 NEW)
        set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
    endif ()

    # Path containing all dependencies
    set(DEPS "deps")

    # Add headers
    target_include_directories(${PROJECT_NAME} PRIVATE "${DEPS}/include")

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        # Set static debug and add debug libraries
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
        target_link_directories(${PROJECT_NAME} PRIVATE "${DEPS}/debug/lib")
    else ()
        # Set static and add release libraries
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
        target_link_directories(${PROJECT_NAME} PRIVATE "${DEPS}/lib")
    endif ()

    # Link libraries
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_link_libraries(${PROJECT_NAME} PRIVATE raylib winmm)
    else ()
        target_link_libraries(${PROJECT_NAME} PRIVATE raylib winmm)
    endif ()
endif ()