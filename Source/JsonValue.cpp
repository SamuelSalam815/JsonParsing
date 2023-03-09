#include"Headers/JsonValue.h"

void JsonValue::SetAllValueStoresToDefault()
{
	bool_value = bool();
	number_value = double();
	string_value = std::string();
	array_value = nullptr;
}
JsonValue::JsonValue()
{
	value_type = null;
	SetAllValueStoresToDefault();
}
JsonValue::JsonValue(bool bool_value)
{
	value_type = boolean;
	SetAllValueStoresToDefault();
	this->bool_value = bool_value;
}
JsonValue::JsonValue(double number_value)
{
	value_type = number;
	SetAllValueStoresToDefault();
	this->number_value = number_value;
}
JsonValue::JsonValue(std::string string_value)
{
	value_type = string;
	SetAllValueStoresToDefault();
	this->string_value = string_value;
}
JsonValue::JsonValue(shared_ptr<JsonArray> array_value)
{
	value_type = array;
	SetAllValueStoresToDefault();
	this->array_value = array_value;
	SetParent(shared_from_this(), array_value);
}