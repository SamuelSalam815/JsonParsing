#include<iostream>

#pragma once

struct JsonComponent
{
	virtual void PrintToStream(std::ostream& output) = 0;
};
