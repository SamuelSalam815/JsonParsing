#include "..\include\ParsingInput.h"

std::string GetLine(std::shared_ptr<std::istream> inputSource)
{
	std::string result = "";
	char currentChar;
	while (inputSource->good())
	{
		currentChar = inputSource->get();
		result += currentChar;
		if (currentChar == '\n')
		{
			return result;
		}
	}
	return result;
}

ParsingInput::ParsingInput(std::shared_ptr<std::istream> inputSource)
{
	this->inputSource = inputSource;
	this->currentLine = GetLine(inputSource);
	this->lineNumber = 0;
	this->charPos = 0;
}

bool ParsingInput::good() 
{
	return inputSource->good();
}
char ParsingInput::peek()
{
	if (charPos == currentLine.length())
	{
		return inputSource->peek();
	}
	return currentLine[charPos];
}
char ParsingInput::get()
{
	if (charPos == currentLine.length())
	{
		lineNumber++;
		charPos = 0;
		currentLine = GetLine(inputSource);
	}
	char currentChar = currentLine[charPos];
	charPos++;
	return currentChar;
}

int ParsingInput::CurrentLineNumber()
{
	return lineNumber;
}

int ParsingInput::CurrentCharacterPosition()
{
	return charPos;
}

std::string ParsingInput::CurrentLine()
{
	return currentLine;
}