#include "JsonComponent.h"
#include "JsonArray.h"
#include <string>
#pragma once

struct JsonValue : JsonComponent
{
private:
	enum value_type
	{
		null,
		boolean,
		number,
		string,
		array,
		dictionary // TODO : support json dictionaries
	}value_type;

	bool bool_value;
	double number_value;
	std::string string_value;
	std::shared_ptr<JsonArray> array_value;

	JsonValue() // TODO : try to define outside of header file
	{
		bool_value = bool();
		number_value = double();
		string_value = std::string();
		array_value = nullptr;
	}
public:
	static std::shared_ptr<JsonValue> CreateJsonValue();
	static std::shared_ptr<JsonValue> CreateJsonValue(bool bool_value);
	static std::shared_ptr<JsonValue> CreateJsonValue(double number_value);
	static std::shared_ptr<JsonValue> CreateJsonValue(std::string string_value);
	static std::shared_ptr<JsonValue> CreateJsonValue(std::shared_ptr<JsonArray> array_value);
};