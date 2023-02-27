#include<JsonComponents/JsonComponent.h>
#include<vector>

struct JsonComposite : JsonComponent
{
	virtual std::vector<JsonComponent> GetChildren() = 0;
	virtual void AddChild(JsonComponent child) = 0;
};