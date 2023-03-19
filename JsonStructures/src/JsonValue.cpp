#include "..\include\JsonValue.h"

JsonValue::JsonValue()
{
	bool_value = bool();
	number_value = double();
	string_value = std::string();
	array_value = nullptr;
	object_value = nullptr;
}
std::shared_ptr<JsonValue> JsonValue::CreateJsonValue()
{
	std::shared_ptr<JsonValue> instance(new JsonValue());
	instance->value_type = null;
	return instance;
}
std::shared_ptr<JsonValue> JsonValue::CreateJsonValue(bool bool_value)
{
	std::shared_ptr<JsonValue> instance(new JsonValue());
	instance->bool_value = bool_value;
	instance->value_type = boolean;
	return instance;
}
std::shared_ptr<JsonValue> JsonValue::CreateJsonValue(double number_value)
{
	std::shared_ptr<JsonValue> instance(new JsonValue());
	instance->number_value = number_value;
	instance->value_type = number;
	return instance;
}
std::shared_ptr<JsonValue> JsonValue::CreateJsonValue(std::string string_value)
{
	std::shared_ptr<JsonValue> instance(new JsonValue());
	instance->string_value = string_value;
	instance->value_type = string;
	return instance;
}
std::shared_ptr<JsonValue> JsonValue::CreateJsonValue(std::shared_ptr<JsonArray> array_value)
{
	std::shared_ptr<JsonValue> instance(new JsonValue());
	instance->array_value = array_value;
	instance->value_type = array;
	AdoptComponent(instance, array_value);
	return instance;
}

std::shared_ptr<JsonValue> JsonValue::CreateJsonValue(std::shared_ptr<JsonObject> object_value)
{
	std::shared_ptr<JsonValue> instance(new JsonValue());
	instance->object_value = object_value;
	instance->value_type = object;
	AdoptComponent(instance, object_value);
	return instance;
}