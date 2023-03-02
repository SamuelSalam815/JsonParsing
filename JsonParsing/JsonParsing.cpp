// JsonParsing.cpp : Defines the entry point for the application.
//

#include "JsonParsing.h"

struct JsonValue
{
private:
	bool bool_value;
	double number_value;
	
	enum value_type
	{
		null,
		boolean,
		number
	}value_type;
public:
	JsonValue()
	{
		value_type = null;
	}
	JsonValue(bool bool_value)
	{
		this->bool_value = bool_value;
		value_type = boolean;
	}
	JsonValue(double number_value)
	{
		this->number_value = number_value;
		value_type = number;
	}

	void ToStream(std::ostream& output)
	{
		switch (value_type)
		{
		case null:
			output << "null";
			break;
		case boolean:
			output << (bool_value ? "true" : "false");
			break;
		case number:
			output << number_value;
			break;
		}
	}
};

bool IsExpectedStringNext(std::string expectedString, std::istream& context)
{
	for (int numCharsChecked = 0; numCharsChecked < expectedString.size(); numCharsChecked++)
	{
		if (context.get() != expectedString[numCharsChecked])
		{
			return false;
		}
	}
	return true;
}

bool TryParseJsonValue(std::istream& context, JsonValue* output)
{
	bool success = false;
	switch (context.peek())
	{
	case 'n':
		if (success = IsExpectedStringNext("null", context))
		{
			*output = JsonValue();
		}
		break;
	case 't':
		if (success = IsExpectedStringNext("true", context))
		{
			*output = JsonValue(true);
		}
		break;
	case 'f':
		if (success = IsExpectedStringNext("false", context))
		{
			*output = JsonValue(false);
		}
		break;
	default:
		std::string nextString;
		context >> nextString;
		try 
		{
			double valueParsed = std::stod(nextString.c_str(), nullptr);
			success = true;
			*output = JsonValue(valueParsed);
		}
		catch (const std::invalid_argument& invalidArgumentException)
		{
		}
	}

	return success;
}




int main()
{
	std::cout << "Hello CMake." << std::endl;

	/*std::ifstream filereader;
	filereader.open("input.txt");
	for (char c = filereader.get(); filereader.good(); c = filereader.get())
	{
		std::cout << c;
	}*/

	JsonValue jsonValuePtr;
	if (TryParseJsonValue(std::cin, &jsonValuePtr))
	{
		std::cout << std::endl << "Parsed : ";
		jsonValuePtr.ToStream(std::cout);
		std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl << "Failed to parse!" << std::endl;
	}
	return 0;
}