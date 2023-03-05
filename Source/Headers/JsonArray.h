#include "JsonComponent.h"
#include <vector>

#pragma once

struct JsonArray : JsonComponent
{
public:
	JsonArray();

	JsonComponent GetChild(int index);
	void AddChild(shared_ptr<JsonComponent> child);

	// Inherited from JsonComponent
	void PrintToStream(std::ostream& output);

private:
	std::vector<shared_ptr<JsonComponent>> children;
};