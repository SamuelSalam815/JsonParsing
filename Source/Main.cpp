// Main.cpp : Defines the entry point for the application.

#include "Headers/JsonParsing.h"
#include <sstream>
#include <fstream>

int main()
{
	//std::cout << "Hello CMake." << std::endl;
	std::string inputFilePath = "simpleinput.json";
	std::ifstream filereader;
	filereader.open(inputFilePath);
	for (char c = filereader.get(); filereader.good(); c = filereader.get())
	{
		std::cout << c;
	}
	std::cout << std::endl;
	filereader.close();
	filereader.open(inputFilePath);
	JsonValue jsonValue;
	ParseJsonValue(filereader, &jsonValue);
	std::cout << "Json successfully parsed!" << std::endl;
	return 0;
}