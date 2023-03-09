#include "JsonValue.h"
#include "JsonArray.h"
#include <iostream>
#pragma once

void ParseJsonValue(std::istream& context, JsonValue* output);

struct JsonParsingException
{
	std::string errorMessage;
	JsonParsingException(std::string errorMessage)
	{
		this->errorMessage = errorMessage;
	}
};