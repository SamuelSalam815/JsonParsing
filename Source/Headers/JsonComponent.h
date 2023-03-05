#include<iostream>

#pragma once

using std::weak_ptr;
using std::shared_ptr;
using std::unique_ptr;

struct JsonComponent
{
public:
	virtual void PrintToStream(std::ostream& output) = 0;
	virtual ~JsonComponent() = 0;

protected:
	weak_ptr<JsonComponent> parent;
};