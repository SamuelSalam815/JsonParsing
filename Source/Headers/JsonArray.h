#include "JsonComponent.h"
#include <vector>
#pragma once

struct JsonArray : JsonComponent
{
private:
	int numChildren;
	unique_ptr<std::vector<SharedJsonComponent>> children;
public:
	JsonArray();
	void AddChild(SharedJsonComponent child);
	int GetNumChildren();
	weak_ptr<JsonComponent> GetChildAt(int index);
};