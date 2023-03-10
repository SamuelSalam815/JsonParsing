#include "Headers/JsonLiteralParsing.h"
#include <vector>

bool IsCharValidToAppearInNumber(char c)
{

	switch (c)
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
		return true;
	}
	return false;
}

// ==== Public Methods ====

bool IsExpectedStringNext(std::istream& context, std::string expectedString)
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

void ParseNumber(std::istream& context, double* output)
{
	SkipWhiteSpace(context);
	switch (context.peek())
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
		throw JsonParsingException("Expected '-' or digit");
		break;
	}

	std::vector<char> charsRead = std::vector<char>();
	while (context.good())
	{
		if (IsCharValidToAppearInNumber(context.peek()))
		{
			charsRead.push_back(context.get());
		}
		else
		{
			break;
		}
	}

	char* ptrToFirstElement = &(charsRead[0]);
	*output = std::atof(ptrToFirstElement);
}