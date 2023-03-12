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
		lineNumber = 0;
		charPos = 0;
		currentLine = "";
	}
	else
	{
		charPos++;
		currentLine += nextCharacter;
	}

	return nextCharacter;
}