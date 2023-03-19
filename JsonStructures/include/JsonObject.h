#include "JsonComponent.h"
#include <map>
#include <string>
#pragma once

struct JsonObject : JsonComponent
{
private:
	std::unique_ptr<std::map<std::string, SharedJsonComponent>> children;
public:
	JsonObject();
	void AddChild(std::string key, SharedJsonComponent value);
	std::weak_ptr<JsonComponent> GetChild(std::string key);
};