// JsonParsing.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include<string>
#include"JsonValue.h"
#include"JsonArray.h"

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

void ParseJsonArray(std::istream& context, JsonArray* output);
