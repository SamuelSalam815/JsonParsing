#include <string>
#include "ParsingInput.h"
#pragma once

struct JsonParsingException
{
	std::string errorMessage;
	ParsingInputPtr context;
	JsonParsingException(std::string errorMessage, ParsingInputPtr context);
};