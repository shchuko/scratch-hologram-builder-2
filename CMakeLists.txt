cmake_minimum_required(VERSION 3.15)

project(scratch-hologram-builder-2 VERSION 0.0.1)
set(PROJECT_LIB_NAME ${PROJECT_NAME}_LIB)

# Uncomment to use
#option(LIBS_ENABLE_STATIC_LINKING "Static linking enabled" ON)
#option(DISABLE_TESTING "Tests compiling disabled" ON)

if (DISABLE_TESTING)
    message(STATUS "Tests compiling disabled")
else (DISABLE_TESTING)
    message(STATUS "Tests compiling enabled")
    enable_testing()
endif (DISABLE_TESTING)

set(CMAKE_INSTALL_PATH "$ORIGIN")
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(SEP "\\")
else ()
    set(SEP "/")
endif()

add_compile_definitions(PROJECT_SOURCE_DIR_DEF="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions(PROJECT_VERSION_DEF="${PROJECT_VERSION}")
add_compile_definitions(TEST_RESOURCES_DIR_DEF="${CMAKE_CURRENT_SOURCE_DIR}/test_resources")


# Creating global library
file(GLOB All_SOURCES source/*.cpp source/*.hpp)
add_library(${PROJECT_LIB_NAME} ${All_SOURCES})
target_include_directories(${PROJECT_LIB_NAME} PUBLIC source)

# Importing required packages
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_LIB_NAME} ${CMAKE_THREAD_LIBS_INIT})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_LIB_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

find_package(Boost 1.40 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_LIB_NAME} ${Boost_LIBRARIES})

# Adding libraries
add_subdirectory(external)
add_subdirectory(libs)

target_link_libraries(${PROJECT_LIB_NAME} lib_simple_svg)
target_link_libraries(${PROJECT_LIB_NAME} lib_tiny_obj_loader)
target_link_libraries(${PROJECT_LIB_NAME} glui_static)

# Creating executable
add_executable(${PROJECT_NAME} source/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIB_NAME})


if (NOT DISABLE_TESTING)
    add_subdirectory(test)
endif (NOT DISABLE_TESTING)
