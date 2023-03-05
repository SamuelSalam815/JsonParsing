#include "Headers/JsonArray.h"

JsonArray::JsonArray()
{
	children = std::vector<JsonComponent*>();
}

void JsonArray::AddChild(JsonComponent* child)
{
	children.push_back(child);
}

JsonComponent* JsonArray::GetChild(int index)
{
	return children[index];
}

void JsonArray::PrintToStream(std::ostream& output)
{
	output << '[';
	std::vector<JsonComponent*>::iterator iterator;
	for (iterator = children.begin(); iterator != children.end(); iterator++)
	{
		(*iterator)->PrintToStream(output);
		output << ',';
	}
	output << ']';
}