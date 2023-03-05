add_executable (JsonParsing "JsonParsing.cpp"   "Main.cpp" "Headers/JsonComponent.h" "JsonValue.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JsonParsing PROPERTY CXX_STANDARD 17)
endif()

add_custom_command(
    TARGET JsonParsing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/../Data/input.json
            ${CMAKE_CURRENT_BINARY_DIR}/input.json
)