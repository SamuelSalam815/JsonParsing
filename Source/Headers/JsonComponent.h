#include <memory>

#pragma once

using std::weak_ptr;
using std::shared_ptr;
using std::unique_ptr;

struct JsonComponent : public std::enable_shared_from_this< JsonComponent >
{
protected:
	weak_ptr<JsonComponent> parent;
	static void SetParent(shared_ptr<JsonComponent> parent, shared_ptr<JsonComponent> child)
	{
		child->parent = parent;
	}
public :
	weak_ptr<JsonComponent> GetParent()
	{
		return parent;
	}
};