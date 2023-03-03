// Main.cpp : Defines the entry point for the application.

#include "../JsonParsingHeaders/JsonParsing.h"

int main()
{
	std::cout << "Hello CMake." << std::endl;

	/*std::ifstream filereader;
	filereader.open("input.json");
	for (char c = filereader.get(); filereader.good(); c = filereader.get())
	{
		std::cout << c;
	}*/

	JsonValue jsonValuePtr;
	if (TryParseJsonValue(std::cin, &jsonValuePtr))
	{
		std::cout << std::endl << "Parsed : ";
		jsonValuePtr.PrintToStream(std::cout);
		std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl << "Failed to parse!" << std::endl;
	}
	return 0;
}