set(TARGET_NAME GraphLabEditor)

file(GLOB src_files
        "${CMAKE_CURRENT_SOURCE_DIR}/component/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/component/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/resource/GraphLabEditor.rc"
        main.cpp)

add_executable(${TARGET_NAME} ${src_files})

add_compile_definitions("LAB_ROOT_DIR=${BINARY_ROOT_DIR}")

target_include_directories(
        ${TARGET_NAME}
        PUBLIC $<BUILD_INTERFACE:${THIRD_PARTY_DIR}/stb>
)

# Link dependencies
target_link_libraries(${TARGET_NAME} PUBLIC assimp)
target_link_libraries(${TARGET_NAME} PUBLIC stb)
target_link_libraries(${TARGET_NAME} PUBLIC glfw)
target_link_libraries(${TARGET_NAME} PUBLIC imgui)
target_link_libraries(${TARGET_NAME} PUBLIC glm)
target_link_libraries(${TARGET_NAME} PUBLIC glad)

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME "GraphLabEditor")

set(POST_BUILD_COMMANDS
        COMMAND ${CMAKE_COMMAND} -E make_directory "${BINARY_ROOT_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/resource" "${BINARY_ROOT_DIR}/resource"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:${TARGET_NAME}>/" "${BINARY_ROOT_DIR}"
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${BINARY_ROOT_DIR}/${LAB_ASSET_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${LAB_ROOT_DIR}/${LAB_ASSET_DIR}" "${BINARY_ROOT_DIR}/${LAB_ASSET_DIR}"
        )

add_custom_command(TARGET ${TARGET_NAME} ${POST_BUILD_COMMANDS})
