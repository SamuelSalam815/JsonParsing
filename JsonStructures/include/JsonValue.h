#include "JsonComponent.h"
#include "JsonArray.h"
#include "JsonObject.h"
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
		object
	}value_type;

	bool bool_value;
	double number_value;
	std::string string_value;
	std::shared_ptr<JsonArray> array_value;
	std::shared_ptr<JsonObject> object_value;

	JsonValue();
public:
	static std::shared_ptr<JsonValue> CreateJsonValue();
	static std::shared_ptr<JsonValue> CreateJsonValue(bool bool_value);
	static std::shared_ptr<JsonValue> CreateJsonValue(double number_value);
	static std::shared_ptr<JsonValue> CreateJsonValue(std::string string_value);
	static std::shared_ptr<JsonValue> CreateJsonValue(std::shared_ptr<JsonArray> array_value);
	static std::shared_ptr<JsonValue> CreateJsonValue(std::shared_ptr<JsonObject> array_value);
};