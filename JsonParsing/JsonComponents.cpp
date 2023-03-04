#include "../JsonParsingHeaders/JsonComponents.h"


// ==== JsonValue ====
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

// ==== JsonArray ====

JsonArray::JsonArray()
{
	children = std::vector<JsonComponent*>();
}

void JsonArray::AddChild(JsonComponent* child)
{
	children.push_back(child);
}

JsonComponent* JsonArray::GetChild(int index)
{
	return children[index];
}

void JsonArray::PrintToStream(std::ostream& output)
{
	output << '[';
	std::vector<JsonComponent*>::iterator iterator;
	for (iterator = children.begin(); iterator != children.end(); iterator++)
	{
		(*iterator)->PrintToStream(output);
		output << ',';
	}
	output << ']';
}