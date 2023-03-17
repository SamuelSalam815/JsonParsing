#include "..\include\JsonParsing.h"
#include "..\include\JsonLiteralParsing.h"

std::shared_ptr<JsonValue> ParseJsonValue(ParsingInputPtr context)
{
	SkipWhiteSpace(context);

	switch (NextExpectedValueType(context->peek()))
	{
	case string:
		return JsonValue::CreateJsonValue(ParseString(context));
	case number:
		return JsonValue::CreateJsonValue(ParseNumber(context));
	case array:
		return JsonValue::CreateJsonValue(ParseJsonArray(context));
	case true_value:
		AssertStringIsNext(context, "true");
		return JsonValue::CreateJsonValue(true);
	case false_value:
		AssertStringIsNext(context, "false");
		return JsonValue::CreateJsonValue(false);
	case null:
		AssertStringIsNext(context, "null");
		return JsonValue::CreateJsonValue();
	}

	throw JsonParsingException("Expected a string ('\"'), a number ('-' or digit), an array ('['), 'null', 'true' or 'false'.", context);
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
	return output;
}