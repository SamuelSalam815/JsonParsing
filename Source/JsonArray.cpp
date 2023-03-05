#include "Headers/JsonArray.h"

JsonArray::JsonArray()
{
	children = std::vector<shared_ptr<JsonComponent>>();
}

void JsonArray::AddChild(shared_ptr<JsonComponent> child)
{
	child->parent = std::make_shared(this);
	children.push_back(child);
}

JsonComponent JsonArray::GetChild(int index)
{
	return *(children[index]);
}

void JsonArray::PrintToStream(std::ostream& output)
{
	output << '[';
	std::vector<shared_ptr<JsonComponent>>::iterator iterator;
	for (iterator = children.begin(); iterator != children.end(); iterator++)
	{
		(*iterator)->PrintToStream(output);
		output << ',';
	}
	output << ']';
}