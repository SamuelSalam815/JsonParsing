#include "..\include\JsonParsingException.h"

JsonParsingException::JsonParsingException(std::string errorMessage, ParsingInputPtr context)
{
	this->errorMessage = errorMessage;
	this->context = context;
}