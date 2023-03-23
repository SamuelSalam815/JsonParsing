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

struct ParseState
{
	virtual std::shared_ptr<ParseState> Transition(char input) = 0;
};

typedef std::shared_ptr<ParseState> ParseStatePtr;

namespace NumberParseState
{
	// Pre declare states and their transition methods
	struct Error : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct Initial : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct FirstDigit : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct DigitsBeforeDecimalPoint : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct DecimalPoint : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct DigitsAfterDecimalPoint : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct ExponentMarker : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct ExponentSign : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct ExponentDigits : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	struct Success : ParseState
	{
		ParseStatePtr Transition(char input);
	};

	bool IsCharDigit(char c)
	{
		return '0' <= c && c <= '9';
	}

	// Implement transition methods

	ParseStatePtr Error::Transition(char input)
	{
		return std::make_shared<Error>();
	}

	ParseStatePtr Initial::Transition(char input)
	{
		switch (input)
		{
		case '-':
			return std::make_shared<FirstDigit>();
		case '0':
			return std::make_shared<DecimalPoint>();
		}

		if (IsCharDigit(input))
		{
			return std::make_shared<DigitsBeforeDecimalPoint>();
		}
		return std::make_shared<Error>();
	}

	ParseStatePtr FirstDigit::Transition(char input)
	{
		if (input == '0')
		{
			return std::make_shared<DecimalPoint>();
		}
		if (IsCharDigit(input))
		{
			return std::make_shared<DigitsBeforeDecimalPoint>();
		}
		return std::make_shared<Error>();
	}

	ParseStatePtr DigitsBeforeDecimalPoint::Transition(char input)
	{
		if (IsCharDigit(input))
		{
			return std::make_shared<DigitsBeforeDecimalPoint>();
		}
		switch (input)
		{
		case '.':
			return std::make_shared<DigitsAfterDecimalPoint>();
		case 'E':
		case 'e':
			return std::make_shared<ExponentSign>();
		default:
			return std::make_shared<Success>();
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
	return result;
}

std::string GetExcapedSequence(ParsingInputPtr context)
{
	while (context->good())
	{
		char nextCharacter = context->get();
		std::string unicodeDigits;
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
	char nextChar = context->get();
	if(nextChar != '\"')
	{
		std::string msg = "Expected start of string ('\"')! Got : '";
		msg += nextChar;
		msg += "'!";
		throw JsonParsingException(msg, context);
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