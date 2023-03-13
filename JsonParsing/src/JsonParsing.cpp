#include "..\include\JsonParsing.h"
#include "..\include\JsonLiteralParsing.h"

std::shared_ptr<JsonValue> ParseJsonValue(ParsingInputPtr context)
{
	SkipWhiteSpace(context);
	switch (context->peek())
	{
	case 'n':
		AssertStringIsNext(context, "null");
		return std::make_shared<JsonValue>();
	case 't':
		AssertStringIsNext(context, "true");
		return std::make_shared<JsonValue>(true);
	case 'f':
		AssertStringIsNext(context, "false");
		return std::make_shared<JsonValue>(false);
	//case '\'':
	//	  return std::make_shared<JsonValue>(ParseString(context));
	case '[':
		return std::make_shared<JsonValue>(ParseJsonArray(context));
	default:
		return std::make_shared<JsonValue>(ParseNumber(context));
	}

	throw JsonParsingException("Expected a string, a number, '[', 'null', 'true' or 'false'.", context);
}

std::shared_ptr<JsonArray> ParseJsonArray(ParsingInputPtr context)
{
	SkipWhiteSpace(context);
	if (context->get() != '[')
	{
		throw JsonParsingException("Expected '['.", context);
	}

	std::shared_ptr<JsonArray> output = std::make_shared<JsonArray>();
	bool isFirstElement = true;
	SkipWhiteSpace(context);
	while (context->peek() != ']')
	{
		if (!isFirstElement)
		{
			AssertStringIsNext(context, ",");
		}
		isFirstElement = false;
		output->AddChild(ParseJsonValue(context));
		SkipWhiteSpace(context);
	}
	context->get(); // discard closing bracket
}