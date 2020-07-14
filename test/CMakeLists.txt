file(GLOB PROJECT_LIB_TEST_SOURCES ./*.cpp)

if (PROJECT_LIB_TEST_SOURCES)
    add_executable(ProjectLibTests ${PROJECT_LIB_TEST_SOURCES})
    target_include_directories(ProjectLibTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    target_link_libraries(ProjectLibTests gtest gtest_main ${PROJECT_LIB_NAME})

    set_target_properties(ProjectLibTests
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
            )

    add_test(
            NAME
            ProjectLibTests
            COMMAND
            ${CMAKE_BINARY_DIR}/bin/ProjectLibTests
    )
endif (PROJECT_LIB_TEST_SOURCES)