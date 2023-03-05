#include "JsonComponent.h"
#include <vector>

#pragma once

struct JsonArray : JsonComponent
{
public:
	JsonArray();

	JsonComponent* GetChild(int index);
	void AddChild(JsonComponent* child);

	// Inherited from JsonComponent
	void PrintToStream(std::ostream& output);

private:
	std::vector<JsonComponent*> children;
};