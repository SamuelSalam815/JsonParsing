#include "Headers/JsonParsing.h"
#include "Headers/JsonLiteralParsing.h"

void AssertStringIsNext(std::istream& context, std::string expectedString)
{
	if (!IsExpectedStringNext(context, expectedString))
	{
		throw JsonParsingException("Expected '" + expectedString + "'");
	}
}

void ParseJsonValue(std::istream& context, JsonValue* output)
{
	SkipWhiteSpace(context);
	switch (context.peek())
	{
	case 'n':
		AssertStringIsNext("null");
		*output = JsonValue();
		break;
	case 't':
		AssertStringIsNext("true");
		*output = JsonValue(true);
		break;
	case 'f':
		AssertStringIsNext("false");
		*output = JsonValue(false);
		break;
	case '\'':
		ParseString(context, output);
	default:
		ParseNumber(context, output);
	}

	throw JsonParsingException("Expected a number, 'null', 'true' or 'false'.");
}

void ParseJsonArray(std::istream& context, JsonArray* output)
{
	SkipWhiteSpace(context);
	int beginPosition = context.tellg();
	if (context.get() != '[')
	{
		throw JsonParsingExcption("Expected '['.");
	}
	JsonArray result;
	
}