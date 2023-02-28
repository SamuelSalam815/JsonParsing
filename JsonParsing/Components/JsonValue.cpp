#include "Components/JsonComponent.h"

struct JsonValue : JsonComponent
{

private:
	enum JsonValueType { null, boolean, string, number, component};

	std::shared_ptr<JsonComponent> child;
	JsonValueType value_type;
	bool bool_value;
	std::string string_value;
	double number_value;

public:
	JsonValue(std::shared_ptr<JsonComponent> parent)
	{
		this->parent = parent;
		value_type = null;
	}
	JsonValue(std::shared_ptr<JsonComponent> parent, bool bool_value)
	{
		this->parent = parent;
		this->bool_value = bool_value;
		value_type = boolean;
	}
	JsonValue(std::shared_ptr<JsonComponent> parent, std::string string)
	{
		this->parent = parent;
		this->string_value = string;
		value_type = string;
	}
	JsonValue(std::shared_ptr<JsonComponent> parent, double number)
	{
		this->parent = parent;
		this->number_value = number;
		value_type = number;
	}
	JsonValue(std::shared_ptr<JsonComponent> parent, std::shared_ptr<JsonComponent> child)
	{
		this->parent = parent;
		this->child = child;
		value_type = component;
	}
	
	// Inherited via JsonComponent
	virtual void PrintToStream(std::shared_ptr<std::ostream> output) override
	{
		switch (value_type)
		{
		case null:
			*output << "null";
			break;
		case boolean:
			*output << bool_value;
			break;
		case string:
			*output << "'" << string_value << "'";
			break;
		case number:
			*output << number_value;
			break;
		case component:
			child->PrintToStream(output);
			break;
		}
	}
	virtual std::weak_ptr<JsonComponent> GetParent() override
	{
		return this->parent;
	}
	virtual int GetNumChildren() override
	{
		if (value_type == component)
		{
			return 1;
		}

		return 0;
	}
	virtual bool TryGetChild(std::string name, std::weak_ptr<JsonComponent> child) override
	{
		if (value_type != component)
		{
			return false;
		}

		child = std::make_weak<JsonComponent>(this->child);

		return true;
	}
	virtual bool TryAddChild(std::string name, std::shared_ptr<JsonComponent> child) override
	{
		return false;
	}
};