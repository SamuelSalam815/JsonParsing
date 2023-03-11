#include "JsonValue.h"
#include "JsonArray.h"
#include "JsonParsingException.h"
#include <iostream>
#pragma once

void ParseJsonValue(std::istream& context, JsonValue* output);
void ParseJsonArray(std::istream& context, JsonArray* output);
