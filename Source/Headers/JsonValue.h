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
		array
	}value_type;

	bool bool_value;
	double number_value;
	std::string string_value;
	shared_ptr<JsonArray> array_value;

	void SetAllValueStoresToDefault()
	{
		bool_value = bool();
		number_value = double();
		string_value = std::string();
		array_value = nullptr;
	}

public:
	JsonValue()
	{
		value_type = null;
		SetAllValueStoresToDefault();
	}
	JsonValue(bool bool_value)
	{
		value_type = boolean;
		SetAllValueStoresToDefault();
		this->bool_value = bool_value;
	}
	JsonValue(double number_value)
	{
		value_type = number;
		SetAllValueStoresToDefault();
		this->number_value = number_value;
	}
	JsonValue(std::string string_value)
	{
		value_type = string;
		SetAllValueStoresToDefault();
		this->string_value = string_value;
	}
	JsonValue(shared_ptr<JsonArray> array_value)
	{
		value_type = array;
		SetAllValueStoresToDefault();
		this->array_value = array_value;
		array_value->
	}
	JsonValue(shared_ptr<JsonValue> array_value)
	{
		value_type = array;
		SetAllValueStoresToDefault();
		this->array_value = array_value;
		array_value->SetParent
	}
};