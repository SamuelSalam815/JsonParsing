#include "JsonComponent.h"
#include <map>
#include <string>
#pragma once

struct JsonDictionary : JsonComponent
{
private:
	unique_ptr<std::map<std::string, SharedJsonComponent>> children;
public:
	JsonDictionary();
	void AddChild(std::string key, SharedJsonComponent value);
	weak_ptr<JsonComponent> GetChild(std::string key);
};