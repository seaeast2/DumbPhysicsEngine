cmake_minimum_required(VERSION 3.10)
project(DumbPhysicsEngine LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands for IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---------------------------------------------------------------------------
# Output Directory Settings
# ---------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# ---------------------------------------------------------------------------
# Compiler Settings
# ---------------------------------------------------------------------------
if(MSVC)
    add_compile_options(/utf-8)
endif()

# ---------------------------------------------------------------------------
# Dependencies (glm, glfw3, glad)
# ---------------------------------------------------------------------------
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad CONFIG REQUIRED)

# ---------------------------------------------------------------------------
# 1. Physics Engine Static Library
# ---------------------------------------------------------------------------
file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp")

add_library(DumbPhysics STATIC ${ENGINE_SOURCES})

# Include directory
target_include_directories(DumbPhysics PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)

# Link math library
target_link_libraries(DumbPhysics PUBLIC glm::glm)

# ---------------------------------------------------------------------------
# 2. Samples (Individual executables for each .cpp in samples/)
# ---------------------------------------------------------------------------
file(GLOB SAMPLE_SOURCES "samples/*.cpp")

foreach(SOURCE_FILE ${SAMPLE_SOURCES})
    get_filename_component(SAMPLE_NAME ${SOURCE_FILE} NAME_WE)
    
    add_executable(${SAMPLE_NAME} ${SOURCE_FILE})
    
    target_link_libraries(${SAMPLE_NAME} PRIVATE 
        DumbPhysics 
        glfw
        glad::glad
    )
endforeach()
