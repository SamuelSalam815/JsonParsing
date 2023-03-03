// JsonParsing.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <stdexcept>
#include "JsonComponents.h"

bool TryParseJsonValue(std::istream& context, JsonValue* output);
