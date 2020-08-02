project(glui)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

SET(GLUI_SRCS
 src/algebra3.cpp
 src/arcball.cpp
 src/glui_add_controls.cpp
 src/glui_bitmaps.cpp
 src/glui_button.cpp
 src/glui_checkbox.cpp
 src/glui_column.cpp
 src/glui_commandline.cpp
 src/glui_control.cpp
 src/glui.cpp
 src/glui_edittext.cpp
 src/glui_filebrowser.cpp
 src/glui_listbox.cpp
 src/glui_list.cpp
 src/glui_mouse_iaction.cpp
 src/glui_node.cpp
 src/glui_panel.cpp
 src/glui_radio.cpp
 src/glui_rollout.cpp
 src/glui_rotation.cpp
 src/glui_scrollbar.cpp
 src/glui_separator.cpp
 src/glui_spinner.cpp
 src/glui_statictext.cpp
 src/glui_textbox.cpp
 src/glui_translation.cpp
 src/glui_tree.cpp
 src/glui_treepanel.cpp
 src/glui_window.cpp
 src/quaternion.cpp
 src/viewmodel.cpp
)

add_library(glui_obj OBJECT ${GLUI_SRCS})
target_include_directories(glui_obj
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        ${OPENGL_INCLUDE_DIR}
        ${GLUT_INCLUDE_DIR})
# we need to enable -fPIC this so that the same object code can be used to
# create static *and* shared libraries without double compilation
set_target_properties(glui_obj PROPERTIES POSITION_INDEPENDENT_CODE 1)

add_library(glui SHARED $<TARGET_OBJECTS:glui_obj>)
target_include_directories(glui
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
        ${OPENGL_INCLUDE_DIR}
        ${GLUT_INCLUDE_DIR})
target_link_libraries(glui PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
set_target_properties(glui PROPERTIES
        DEBUG_POSTFIX "d"
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION})

add_library(glui_static STATIC $<TARGET_OBJECTS:glui_obj>)
target_include_directories(glui_static
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
        ${OPENGL_INCLUDE_DIR}
        ${GLUT_INCLUDE_DIR})
target_link_libraries(glui_static PUBLIC ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
set_target_properties(glui_static PROPERTIES DEBUG_POSTFIX "d")