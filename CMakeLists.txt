# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
cmake_minimum_required (VERSION 3.8)

project ("JsonParsing")

add_executable (JsonParsing 

"JsonStructures/src/JsonArray.cpp" 
"JsonStructures/src/JsonComponent.cpp" 
"JsonStructures/src/JsonValue.cpp" 

"JsonParsing/src/JsonLiteralParsing.cpp" 
"JsonParsing/src/JsonParsing.cpp"
"JsonParsing/src/JsonParsingException.cpp"
"JsonParsing/src/ParsingInput.cpp"

"Main.cpp"  "JsonStructures/src/JsonObject.cpp"  "JsonParsing/include/ParseNumberState.h" "JsonParsing/src/ParseNumberState.cpp")

set_property(TARGET JsonParsing PROPERTY CXX_STANDARD 17)


add_custom_command(
    TARGET JsonParsing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/Data/input.json
            ${CMAKE_CURRENT_BINARY_DIR}/input.json
)

add_custom_command(
    TARGET JsonParsing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/Data/simpleinput.json
            ${CMAKE_CURRENT_BINARY_DIR}/simpleinput.json
)