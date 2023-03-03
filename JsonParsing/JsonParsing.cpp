#include "../JsonParsingHeaders/JsonParsing.h"

bool IsExpectedStringNext(std::string expectedString, std::istream& context)
{
	for (int numCharsChecked = 0; numCharsChecked < expectedString.size(); numCharsChecked++)
	{
		if (context.get() != expectedString[numCharsChecked])
		{
			return false;
		}
	}
	return true;
}

void SkipWhiteSpace(std::istream& context)
{
	while (context.good() && std::isspace(context.peek()))
	{
		context.get();
	}
}

bool TryParseJsonValue(std::istream& context, JsonValue* output)
{
	SkipWhiteSpace(context);
	bool success = false;
	switch (context.peek())
	{
	case 'n':
		if (success = IsExpectedStringNext("null", context))
		{
			*output = JsonValue();
		}
		break;
	case 't':
		if (success = IsExpectedStringNext("true", context))
		{
			*output = JsonValue(true);
		}
		break;
	case 'f':
		if (success = IsExpectedStringNext("false", context))
		{
			*output = JsonValue(false);
		}
		break;
	default:
		std::string nextString;
		context >> nextString;
		try
		{
			double valueParsed = std::stod(nextString.c_str(), nullptr);
			success = true;
			*output = JsonValue(valueParsed);
		}
		catch (const std::invalid_argument& invalidArgumentException)
		{
		}
	}

	return success;
}