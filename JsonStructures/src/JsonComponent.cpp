#include "..\include\JsonComponent.h"

void JsonComponent::SetParent(std::shared_ptr<JsonComponent> parent, std::shared_ptr<JsonComponent> child)
{
	child->parent = parent;
}

std::weak_ptr<JsonComponent> JsonComponent::GetParent()
{
	return parent;
}