// Main.cpp : Defines the entry point for the application.

#include "Headers/JsonParsing.h"
#include <sstream>
#include <fstream>

void printArguments(int argc, char** argv)
{
	std::cout << "Arguments Received :" << std::endl;
	for (int argumentsPrinted = 0; argumentsPrinted < argc; argumentsPrinted++)
	{
		std::cout 
			<< "Argument " << argumentsPrinted << " : " 
			<< argv[argumentsPrinted] << std::endl;
	}
	std::cout << std::endl;
}

void printInputFile(std::string inputFilePath)
{
	std::cout << "Reading File '" << inputFilePath << "' :" << std::endl;

	std::ifstream filereader;
	filereader.open(inputFilePath);
	for (char c = filereader.get(); filereader.good(); c = filereader.get())
	{
		std::cout << c;
	}
	std::cout << std::endl << std::endl;
	filereader.close();
}

void printErrorContext(JsonParsingException exception)
{
	int charPos = exception.context->CurrentCharacterPosition();
	std::cout << "Error occurred on line "
		<< exception.context->CurrentLineNumber()
		<< " Position " << charPos << std::endl << std::endl;

	std::cout << exception.context->CurrentLine() << std::endl;

	for (int segmentsPrinted = 0; segmentsPrinted < charPos; segmentsPrinted++)
	{
		std::cout << '~';
	}
	std::cout << '^' << std::endl << std::endl;
	std::cout << exception.errorMessage << std::endl;

}

void attemptToParseInputFile(std::string inputFilePath)
{
	std::cout << "Parsing File '" << inputFilePath << "' :" << std::endl;

	shared_ptr<std::ifstream> inputSourcePtr = std::make_shared<std::ifstream>();
	inputSourcePtr->open(inputFilePath);
	ParsingInputPtr wrappedInputSource = std::make_shared<ParsingInput>(inputSourcePtr);
	shared_ptr<JsonValue> jsonValue = std::make_shared<JsonValue>();
	try
	{
		ParseJsonValue(wrappedInputSource, jsonValue);
		std::cout << "Json successfully parsed!" << std::endl;
	}
	catch (JsonParsingException exception)
	{
		std::cout << "Json parsing failed !" << std::endl;
		printErrorContext(exception);
	}
}

int main(int argc, char** argv)
{
	printArguments(argc, argv);

	std::string inputFile = "simpleInput.json";
	printInputFile(inputFile);
	attemptToParseInputFile(inputFile);
	
	return 0;
}