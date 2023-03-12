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

void attemptToParseInputFile(std::string inputFilePath)
{
	std::cout << "Parsing File '" << inputFilePath << "' :" << std::endl;

	std::ifstream filereader;
	filereader.open(inputFilePath);
	JsonValue jsonValue;
	try
	{
		ParseJsonValue(filereader, &jsonValue);
		std::cout << "Json successfully parsed!" << std::endl;
	}
	catch (JsonParsingException exception)
	{
		std::cout << "Json parsing failed !" << std::endl;
		std::cout << exception.errorMessage << std::endl;
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