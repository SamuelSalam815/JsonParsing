#include "JsonValue.h"
#include "JsonArray.h"
#include "JsonParsingException.h"
#include <iostream>
#pragma once

void ParseJsonValue(ParsingInputPtr context, shared_ptr<JsonValue> output);
void ParseJsonArray(ParsingInputPtr context, shared_ptr<JsonArray> output);
