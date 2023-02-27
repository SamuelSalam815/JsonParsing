#include<string>

struct JsonComponent
{
	virtual std::string ToString() = 0;
	virtual bool TryGetParent(JsonComponent* parent) = 0;
};