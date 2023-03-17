#include "..\include\ParsingInput.h"

void ParsingInput::ProcessCharacter(char character)
{
	if (character == '\n')
	{
		lineNumber++;
		charPos = -1;
		currentLine = "";
	}
	else
	{
		charPos++;
		currentLine += character;
	}
}

ParsingInput::ParsingInput(std::shared_ptr<std::istream> inputSource)
{
	this->inputSource = inputSource;
	this->currentLine = std::string();
	this->lineNumber = 0;
	this->charPos = -1;
	this->hasNextCharBeenPeeked = false;
}

bool ParsingInput::good() 
{
	return inputSource->good();
}
char ParsingInput::peek()
{
	char nextCharacter = inputSource->peek();
	if (!hasNextCharBeenPeeked)
	{
		hasNextCharBeenPeeked = true;
		ProcessCharacter(nextCharacter);
	}
	return nextCharacter;
}
char ParsingInput::get()
{
	char nextCharacter = inputSource->get();
	if (!hasNextCharBeenPeeked)
	{
		ProcessCharacter(nextCharacter);
	}
	hasNextCharBeenPeeked = false;
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