#include <memory>

#pragma once

using std::weak_ptr;
using std::shared_ptr;
using std::unique_ptr;

struct JsonComponent 
{
protected:
	weak_ptr<JsonComponent> parent;
	void SetParent(shared_ptr<JsonComponent> parent)
	{
		this->parent = parent;
	}
public :
	weak_ptr<JsonComponent> GetParent()
	{
		return parent;
	}
};