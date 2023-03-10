#include <string>
#pragma once

struct JsonParsingException
{
	std::string errorMessage;
	JsonParsingException(std::string errorMessage)
	{
		this->errorMessage = errorMessage;
	}
};