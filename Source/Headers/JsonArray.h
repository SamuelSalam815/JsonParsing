#include "JsonComponent.h"
#include <vector>
#pragma once

struct JsonArray : JsonComponent
{
private:
	std::vector<SharedJsonComponent> children;
public:
	JsonArray();
	void AddChild(SharedJsonComponent child);
	size_t GetNumChildren();
	weak_ptr<JsonComponent> GetChildAt(int index);
};