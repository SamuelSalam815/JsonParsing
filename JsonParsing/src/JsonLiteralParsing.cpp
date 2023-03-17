#include "..\include\JsonLiteralParsing.h"
#include <vector>

JsonValueType NextExpectedValueType(char c)
{
	switch (c)
	{
	case '\"':
		return JsonValueType::string;
	case '-':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return JsonValueType::number;
	case '{':
		return JsonValueType::object;
	case '[':
		return JsonValueType::array;
	case 't':
		return JsonValueType::true_value;
	case 'f':
		return JsonValueType::false_value;
	case 'n':
		return JsonValueType::null;
	}

	return JsonValueType::undefined;
}

void SkipWhiteSpace(ParsingInputPtr context)
{
	while (context->good() && std::isspace(context->peek()))
	{
		context->get();
	}
}

void AssertStringIsNext(ParsingInputPtr context, std::string expectedString)
{
	for (int numCharsChecked = 0; numCharsChecked < expectedString.size(); numCharsChecked++)
	{
		if (context->get() != expectedString[numCharsChecked])
		{
			throw JsonParsingException("Expected '" + expectedString + "'", context);
		}
	}
}

double ParseNumber(ParsingInputPtr context)
{
	SkipWhiteSpace(context);
	switch (context->peek())
	{
	case '-':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		throw JsonParsingException("Expected number", context);
		break;
	}

	std::vector<char> charsRead = std::vector<char>();
	bool nextCharIsValid = true;
	while (context->good() && nextCharIsValid)
	{
		switch (context->peek())
		{
		case '-':
		case '+':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 'E':
		case 'e':
		case '.':
			charsRead.push_back(context->get());
			break;
		default:
			goto FinishedGettingChars;
		}
	}
	FinishedGettingChars:

	char* ptrToFirstElement = &(charsRead[0]);
	return std::atof(ptrToFirstElement);
}

std::string ParseString(ParsingInputPtr context)
{
	throw JsonParsingException("String parsing not supported yet!", context);
}