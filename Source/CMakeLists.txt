add_executable (JsonParsing "Main.cpp"  "Headers/JsonValue.h" "Headers/JsonParsing.h" "Headers/JsonArray.h" "JsonValue.cpp" "JsonComponent.cpp" "JsonArray.cpp" "Headers/JsonDictionary.h" "JsonLiteralParsing.cpp" "Headers/JsonLiteralParsing.h" "Headers/JsonParsingException.h"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JsonParsing PROPERTY CXX_STANDARD 17)
endif()

add_custom_command(
    TARGET JsonParsing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/../Data/input.json
            ${CMAKE_CURRENT_BINARY_DIR}/input.json
)