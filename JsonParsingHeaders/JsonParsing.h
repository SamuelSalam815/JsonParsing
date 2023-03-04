// JsonParsing.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <sstream>
#include "JsonComponents.h"

struct JsonParsingExcption {
	
	std::string message;
	int streamPosition;

	JsonParsingExcption(std::string message, int streamPosition)
	{
		this->message = message;
		this->streamPosition = streamPosition;
	}
};

void ParseJsonValue(std::istream& context, JsonValue* output);

void ParseJsonArray(std::istream& context, JsonValue* output);
