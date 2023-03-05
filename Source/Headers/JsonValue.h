#include "JsonComponent.h"
#include "JsonArray.h"

#pragma once

struct JsonValue : JsonComponent
{
public:
	JsonValue();
	JsonValue(bool bool_value);
	JsonValue(double number_value);
	JsonValue(shared_ptr<JsonArray> array_value);

	// Inherited from JsonComponent
	void PrintToStream(std::ostream& output);


private:
	bool bool_value;
	double number_value;
	shared_ptr<JsonComponent> component_value;
	
	enum value_type
	{
		null,
		boolean,
		number,
		component
	}value_type;
};