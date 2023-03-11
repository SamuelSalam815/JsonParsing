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
	std::string parsedString;
	double parsedNumber;
	shared_ptr<JsonArray> parsedJsonArray;
	switch (context.peek())
	{
	case 'n':
		AssertStringIsNext(context, "null");
		*output = JsonValue();
		break;
	case 't':
		AssertStringIsNext(context, "true");
		*output = JsonValue(true);
		break;
	case 'f':
		AssertStringIsNext(context, "false");
		*output = JsonValue(false);
		break;
	case '\'':
		ParseString(context, &parsedString);
		*output = JsonValue(parsedString);
		break;
	case '[':
		parsedJsonArray = std::make_shared<JsonArray>(new JsonArray());
		ParseJsonArray(context, parsedJsonArray.get());
		*output = JsonValue(parsedJsonArray);
		break;
	default:
		ParseNumber(context, &parsedNumber);
		*output = JsonValue(parsedNumber);
		break;
	}

	throw JsonParsingException("Expected a string, a number, '[', 'null', 'true' or 'false'.");
}

void ParseJsonArray(std::istream& context, JsonArray* output)
{
	SkipWhiteSpace(context);
	int beginPosition = context.tellg();
	if (context.get() != '[')
	{
		throw JsonParsingException("Expected '['.");
	}

	shared_ptr<JsonValue> currentValue;
	SkipWhiteSpace(context);
	while (context.peek() != ']')
	{
		currentValue = std::make_shared<JsonValue>(new JsonValue());
		ParseJsonValue(context, currentValue.get());
		output->AddChild(currentValue);
		SkipWhiteSpace(context);
	}
	context.get(); // discard closing bracket
}