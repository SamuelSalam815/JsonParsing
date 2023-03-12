#include <iostream>
#include <memory>

#pragma once

// Purpose :
// Wrap an istream object in order to provide input to json parsing functions.
// When parsing errors occur, also provides the line, line number and character position of where the error occurred.
struct ParsingInput
{
private:
	std::shared_ptr<std::istream> inputSource;
	std::string currentLine;
	int lineNumber;
	int charPos;
public:
	ParsingInput(std::shared_ptr<std::istream> inputSource);
	bool good();
	char peek();
	char get();
};

typedef std::shared_ptr<ParsingInput> ParsingInputPtr;