#include "../JsonParsingHeaders/JsonComponents.h"

JsonValue::JsonValue()
{
	this->bool_value = bool();
	this->number_value = double();
	this->value_type = null;
}
JsonValue::JsonValue(bool bool_value)
{
	this->bool_value = bool_value;
	this->number_value = double();
	this->value_type = boolean;
}
JsonValue::JsonValue(double number_value)
{
	this->bool_value = bool();
	this->number_value = number_value;
	this->value_type = number;
}

void JsonValue::PrintToStream(std::ostream& output)
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