#include "Headers/JsonParsing.h"
#include "Headers/JsonLiteralParsing.h"

void AssertStringIsNext(ParsingInputPtr context, std::string expectedString)
{
	if (!IsExpectedStringNext(context, expectedString))
	{
		throw JsonParsingException("Expected '" + expectedString + "'", context);
	}
}

void ParseJsonValue(ParsingInputPtr context, shared_ptr<JsonValue> output)
{
	SkipWhiteSpace(context);
	std::string parsedString;
	double parsedNumber;
	shared_ptr<JsonArray> parsedJsonArray;
	switch (context->peek())
	{
	case 'n':
		AssertStringIsNext(context, "null");
		*output = JsonValue();
		return;
	case 't':
		AssertStringIsNext(context, "true");
		*output = JsonValue(true);
		return;
	case 'f':
		AssertStringIsNext(context, "false");
		*output = JsonValue(false);
		return;
	case '\'':
		//ParseString(context, &parsedString);
		*output = JsonValue(parsedString);
		return;
	case '[':
		parsedJsonArray = std::make_shared<JsonArray>();
		ParseJsonArray(context, parsedJsonArray);
		*output = JsonValue(parsedJsonArray);
		return;
	default:
		parsedNumber = ParseNumber(context);
		*output = JsonValue(parsedNumber);
		return;
	}

	throw JsonParsingException("Expected a string, a number, '[', 'null', 'true' or 'false'.", context);
}

void ParseJsonArray(ParsingInputPtr context, shared_ptr<JsonArray> output)
{
	SkipWhiteSpace(context);
	if (context->get() != '[')
	{
		throw JsonParsingException("Expected '['.", context);
	}

	shared_ptr<JsonValue> currentValue;
	SkipWhiteSpace(context);
	bool isFirstElement = true;
	while (context->peek() != ']')
	{
		if (!isFirstElement)
		{
			AssertStringIsNext(context, ",");
		}
		isFirstElement = false;
		currentValue = std::make_shared<JsonValue>();
		ParseJsonValue(context, currentValue);
		output->AddChild(currentValue);
		SkipWhiteSpace(context);
	}
	context->get(); // discard closing bracket
}