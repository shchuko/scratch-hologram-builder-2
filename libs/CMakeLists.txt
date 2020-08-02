# simple-svg library https://github.com/adishavit/simple-svg
file(GLOB SimpleSVG_SOURCES simple_svg/simple_svg_1.0.0.hpp)
if (LIBS_ENABLE_STATIC_LINKING)
    add_library(lib_simple_svg STATIC ${SimpleSVG_SOURCES})
else (LIBS_ENABLE_STATIC_LINKING)
    add_library(lib_simple_svg SHARED ${SimpleSVG_SOURCES})
endif (LIBS_ENABLE_STATIC_LINKING)
set_target_properties(lib_simple_svg PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(lib_simple_svg PUBLIC ./simple_svg)

set_target_properties(lib_simple_svg
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )


# tinyobjloader library https://github.com/tinyobjloader/tinyobjloader
file(GLOB TinyObjLoader_SOURCES tiny_obj_loader/tiny_obj_loader.h)
if (LIBS_ENABLE_STATIC_LINKING)
    add_library(lib_tiny_obj_loader STATIC ${TinyObjLoader_SOURCES})
else (LIBS_ENABLE_STATIC_LINKING)
    add_library(lib_tiny_obj_loader SHARED ${TinyObjLoader_SOURCES})
endif (LIBS_ENABLE_STATIC_LINKING)
set_target_properties(lib_tiny_obj_loader PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(lib_tiny_obj_loader PUBLIC ./tiny_obj_loader)

set_target_properties(lib_tiny_obj_loader
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_subdirectory(glui)
