# CMakeList.txt : CMake project for JsonParsing, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (JsonParsing "JsonParsing.cpp"  "JsonComponents.cpp" "Main.cpp" "../JsonParsingHeaders/JsonComponents.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JsonParsing PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
add_custom_command(
    TARGET JsonParsing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/../Data/input.json
            ${CMAKE_CURRENT_BINARY_DIR}/input.json
)
