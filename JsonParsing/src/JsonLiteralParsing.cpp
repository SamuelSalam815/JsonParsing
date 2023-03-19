#include "..\include\JsonLiteralParsing.h"
#include <vector>

std::string EOF_Error_Message = "Unexpected end of input!";
template<class T>
bool vector_contains(std::vector<T> searchSpace, T target)
{
	std::vector<T>::iterator iterator;
	for (iterator = searchSpace.begin(); iterator != searchSpace.end(); iterator++)
	{
		if (*iterator == target)
		{
			return true;
		}
	}
	return false;
}

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
	
	std::vector<char> validFirstCharacters = { '-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	if (!vector_contains(validFirstCharacters, context->peek()))
	{
		throw JsonParsingException("Expected number", context);
	}

	std::vector<char> charsRead = std::vector<char>();
	std::vector<char> allowedCharacters = { '-', '+', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'E', 'e', '.' };
	bool nextCharIsValid = true;
	while (context->good() && nextCharIsValid)
	{
		if (vector_contains(allowedCharacters, context->peek()))
		{
			charsRead.push_back(context->get());
		}
		else
		{
			char* ptrToFirstElement = &(charsRead[0]);
			return std::atof(ptrToFirstElement);
		}
	}
}

std::string GetUnicodeSequence(ParsingInputPtr context)
{
	std::string result = "";
	std::vector<char> validHexDigits =
	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
	  'A', 'B', 'C', 'D', 'E', 'F',
	  'a', 'b', 'c', 'd', 'e', 'f' };
	for (int charactersParsed = 0; charactersParsed < 4; charactersParsed++)
	{
		if (!context->good())
		{
			throw JsonParsingException(EOF_Error_Message, context);
		}
		char nextCharacter = context->get();
		if (vector_contains(validHexDigits, nextCharacter))
		{
			result += nextCharacter;
		}
		else
		{
			throw JsonParsingException("Expected Valid Hex digit!", context);
		}
	}
}

std::string GetExcapedSequence(ParsingInputPtr context)
{
	while (context->good())
	{
		char nextCharacter = context->get();
		switch (nextCharacter)
		{
		case '\\':
		case '/':
		case 'b':
		case 'f':
		case 'n':
		case 'r':
		case 't':
			return "" + nextCharacter;
		case 'u':
			return "u" + GetUnicodeSequence(context);
		default:
			throw JsonParsingException("Expected valid control sequence ('\\', '/', 'b', 'f', 'n', 'r', 't' or 'u' + 4 hex digits) !", context);
		}
	}
	throw JsonParsingException(EOF_Error_Message, context);
}

std::string ParseString(ParsingInputPtr context)
{
	if(context->get() != '\"')
	{
		throw JsonParsingException("Expected \"!", context);
	}
	std::string result = "";
	while(context->good())
	{
		char currentCharacter;
		switch(currentCharacter = context->get())
		{
			case '\\':
				result += "\\" + GetExcapedSequence(context);
				break;
			case '\"':
				return result;
			default:
				result += currentCharacter;
		}
	}
	throw JsonParsingException(EOF_Error_Message, context);
}