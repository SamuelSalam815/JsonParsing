#include "JsonComponent.h"
#include <vector>
#pragma once

struct JsonArray : JsonComponent, std::enable_shared_from_this<JsonArray>
{
private:
	std::vector<SharedJsonComponent> children;
public:
	JsonArray();
	void AddChild(SharedJsonComponent child);
	size_t GetNumChildren();
	std::weak_ptr<JsonComponent> GetChildAt(int index);
};