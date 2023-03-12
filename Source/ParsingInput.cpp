#include "Headers/ParsingInput.h"

ParsingInput::ParsingInput(std::shared_ptr<std::istream> inputSource)
{
	this->inputSource = inputSource;
	this->currentLine = std::string();
	this->lineNumber = 0;
	this->charPos = 0;
}

bool ParsingInput::good() 
{
	return inputSource->good();
}
char ParsingInput::peek()
{
	return inputSource->peek();
}
char ParsingInput::get()
{
	char nextCharacter = inputSource->get();
	if(nextCharacter == '\n')
	{
		lineNumber++;
		charPos = 0;
		currentLine = inputSource->peek();
	}
	else
	{
		charPos++;
		currentLine += inputSource->peek();
	}

	return nextCharacter;
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