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

	std::string input;
	std::cin >> input;
	std::stringstream stringStream;
	stringStream << input;
	try 
	{
		JsonValue jsonValuePtr;
		ParseJsonValue(stringStream, &jsonValuePtr);
		std::cout << std::endl << "Parsed : ";
		jsonValuePtr.PrintToStream(std::cout);
		std::cout << std::endl;
	}
	catch(JsonParsingExcption exception)
	{
		stringStream.clear();
		stringStream << input;
		
		for (int numCharsSkipped = 0; numCharsSkipped < exception.streamPosition; numCharsSkipped++)
		{
			stringStream.get();
		}
		std::string remainingInput;
		stringStream >> remainingInput;
		std::cerr
			<< exception.message << std::endl
			<< "Encountered at :" << std::endl
			<< remainingInput;

	}
	return 0;
}