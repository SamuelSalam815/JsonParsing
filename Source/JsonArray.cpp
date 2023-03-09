#include "Headers\JsonArray.h"

JsonArray::JsonArray()
{
	children = unique_ptr<std::vector<SharedJsonComponent>>
		(
			new std::vector<SharedJsonComponent>()
		);
	numChildren = 0;
}

void JsonArray::AddChild(SharedJsonComponent child)
{
	SetParent(shared_from_this(), child);
	children->push_back(child);
}

int JsonArray::GetNumChildren()
{
	return children->size();
}

weak_ptr<JsonComponent> JsonArray::GetChildAt(int index)
{
	return (*children)[index];
}