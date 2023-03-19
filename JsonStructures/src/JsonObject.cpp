#include "..\include\JsonObject.h"

JsonObject::JsonObject()
{
	children = std::make_unique<std::map<std::string, SharedJsonComponent>>();
}
void JsonObject::AddChild(std::string key, SharedJsonComponent value)
{
	children->emplace(key, value);
}
std::weak_ptr<JsonComponent> JsonObject::GetChild(std::string key)
{
	return (*children)[key];
}