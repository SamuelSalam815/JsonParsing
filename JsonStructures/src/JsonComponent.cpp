#include "..\include\JsonComponent.h"

void JsonComponent::SetParent(std::shared_ptr<JsonComponent> child)
{
	child->parent = this;
}

JsonComponent* JsonComponent::GetParent()
{
	return parent;
}