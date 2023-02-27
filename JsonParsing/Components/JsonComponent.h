#ifndef JASONPARSING_COMPONENTS_COMPONENTS_H_
#define JASONPARSING_COMPONENTS_COMPONENTS_H_

#include<string>
#include<memory>
struct json_component
{
protected:
	std::shared_ptr<json_component> parent;
public:
	virtual std::string ToString() = 0;
	virtual std::shared_ptr<json_component> GetParent() = 0;
	virtual int GetNumChildren() = 0;
	virtual bool TryGetChildAtIndex(int index, std::shared_ptr<json_component> child) = 0;
	virtual bool TryAddChild(std::shared_ptr<json_component> child) = 0;
};

#endif // !JASONPARSING_COMPONENTS_COMPONENTS_H_