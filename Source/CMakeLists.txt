add_executable (JsonParsing 
"JsonArray.cpp" 
"JsonComponent.cpp" 
"JsonLiteralParsing.cpp" 
"JsonParsing.cpp"
"JsonValue.cpp" 
"Main.cpp"  
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JsonParsing PROPERTY CXX_STANDARD 17)
endif()

add_custom_command(
    TARGET JsonParsing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/../Data/input.json
            ${CMAKE_CURRENT_BINARY_DIR}/input.json
)

add_custom_command(
    TARGET JsonParsing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/../Data/simpleinput.json
            ${CMAKE_CURRENT_BINARY_DIR}/simpleinput.json
)