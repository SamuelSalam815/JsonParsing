#include "..\include\JsonArray.h"

JsonArray::JsonArray()
{
	children = std::vector<SharedJsonComponent>();
}

void JsonArray::AddChild(SharedJsonComponent child)
{
	SetParent(shared_from_this(), child);
	children.push_back(child);
}

size_t JsonArray::GetNumChildren()
{
	return children.size();
}

std::weak_ptr<JsonComponent> JsonArray::GetChildAt(int index)
{
	return children[index];
}