#include "Components/JsonComponent.h"
#include<map>

struct JsonObject : JsonComponent
{
private:
	std::map<std::string, std::shared_ptr<JsonComponent>> childMap;
	std::shared_ptr<JsonComponent> parent;
public:
	JsonObject()
	{
		parent = nullptr;
	}

	JsonObject(std::shared_ptr<JsonComponent> parent)
	{
		this->parent = parent;
	}

	// Inherited via JsonComponent
	virtual void PrintToStream(std::shared_ptr<std::ostream> output) override
	{
		*output << "{";
		std::map<std::string, std::shared_ptr<JsonComponent>>::iterator iterator;
		for (iterator = childMap.begin(); iterator != childMap.end(); iterator++)
		{
			*output << iterator->first << ":";
			iterator->second->PrintToStream(output);
			*output << ",";
		}
		*output << "}";
	}

	virtual std::weak_ptr<JsonComponent> GetParent() override
	{
		return std::weak_ptr<JsonComponent>(parent);
	}

	virtual int GetNumChildren() override
	{
		return childMap.size();
	}

	virtual bool TryGetChild(std::string name, std::weak_ptr<JsonComponent> child) override
	{
		std::map<std::string, std::shared_ptr<JsonComponent>>::iterator iterator = childMap.find(name);
		if (iterator == childMap.end())
		{
			return false;
		}
		child = iterator->second;
		return true;
	}

	virtual bool TryAddChild(std::string name, std::shared_ptr<JsonComponent> child) override
	{
		childMap.emplace(name, child);
		return true;
	}

};