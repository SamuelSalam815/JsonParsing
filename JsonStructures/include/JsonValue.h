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

	void SetAllValueStoresToDefault();

public:
	JsonValue();
	JsonValue(bool bool_value);
	JsonValue(double number_value);
	JsonValue(std::string string_value);
	JsonValue(std::shared_ptr<JsonArray> array_value);
};