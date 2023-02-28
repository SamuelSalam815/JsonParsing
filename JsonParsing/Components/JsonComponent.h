#ifndef JASONPARSING_COMPONENTS_COMPONENTS_H_
#define JASONPARSING_COMPONENTS_COMPONENTS_H_

#include<string>
#include<memory>
#include<iostream>
struct JsonComponent
{
protected:
	std::shared_ptr<JsonComponent> parent;
public:
	virtual void PrintToStream(std::shared_ptr<std::ostream> output) = 0;
	virtual std::weak_ptr<JsonComponent> GetParent() = 0;
	virtual int GetNumChildren() = 0;
	virtual bool TryGetChild(std::string name, std::weak_ptr<JsonComponent> child) = 0;
	virtual bool TryAddChild(std::string name, std::shared_ptr<JsonComponent> child) = 0;
};
#endif // !JASONPARSING_COMPONENTS_COMPONENTS_H_