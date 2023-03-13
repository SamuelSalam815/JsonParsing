#include "JsonComponent.h"
#include <map>
#include <string>
#pragma once

struct JsonDictionary : JsonComponent
{
private:
	std::unique_ptr<std::map<std::string, SharedJsonComponent>> children;
public:
	JsonDictionary();
	void AddChild(std::string key, SharedJsonComponent value);
	std::weak_ptr<JsonComponent> GetChild(std::string key);
};