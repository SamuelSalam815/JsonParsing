// JsonParsing.cpp : Defines the entry point for the application.
//

#include "JsonParsing.h"

int main()
{
	std::cout << "Hello CMake." << std::endl;
	
	std::ifstream filereader;
	filereader.open("input.txt");
	for (char c = filereader.get(); filereader.good(); c = filereader.get())
	{
		std::cout << c;
	}
	return 0;
}
