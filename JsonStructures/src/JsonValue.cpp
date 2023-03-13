#include "..\include\JsonValue.h"

void JsonValue::SetAllValueStoresToDefault()
{
	bool_value = bool();
	number_value = double();
	string_value = std::string();
	array_value = nullptr;
}

JsonValue::JsonValue()
{
	SetAllValueStoresToDefault();
	value_type = null;
}

JsonValue::JsonValue(bool bool_value)
{
	SetAllValueStoresToDefault();
	value_type = boolean;
	this->bool_value = bool_value;
}

JsonValue::JsonValue(double number_value)
{
	SetAllValueStoresToDefault();
	value_type = number;
	this->number_value = number_value;
}

JsonValue::JsonValue(std::string string_value)
{
	SetAllValueStoresToDefault();
	value_type = string;
	this->string_value = string_value;
}

JsonValue::JsonValue(std::shared_ptr<JsonArray> array_value)
{
	SetAllValueStoresToDefault();
	value_type = array;
	this->array_value = array_value;
	SetParent(shared_from_this(), array_value);
}