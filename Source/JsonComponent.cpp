#include "Headers\JsonComponent.h"

void JsonComponent::SetParent(shared_ptr<JsonComponent> parent, shared_ptr<JsonComponent> child)
{
	child->parent = parent;
}

weak_ptr<JsonComponent> JsonComponent::GetParent()
{
	return parent;
}