file(GLOB_RECURSE TETRIS_SOURCES src/*.cpp)
add_executable(tetris ${TETRIS_SOURCES})
target_include_directories(tetris PRIVATE include)
target_link_libraries(tetris PRIVATE raylib)

set_target_properties(tetris PROPERTIES CXX_STANDARD 17)


if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/assets)
    add_custom_command(TARGET tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:tetris>/assets
    )
endif()
