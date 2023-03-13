#include "..\..\JsonStructures\include\JsonArray.h"
#include "..\..\JsonStructures\include\JsonValue.h"
#include "JsonParsingException.h"
#include <iostream>
#pragma once

std::shared_ptr<JsonArray> ParseJsonArray(ParsingInputPtr context);
std::shared_ptr<JsonValue> ParseJsonValue(ParsingInputPtr context);
