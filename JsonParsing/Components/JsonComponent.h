#ifndef JASONPARSING_COMPONENTS_COMPONENTS_H_
#define JASONPARSING_COMPONENTS_COMPONENTS_H_

#include<string>
#include<memory>
#include<iostream>
struct JsonComponent
{
public:
	virtual void PrintToStream(std::ostream& output) = 0;
	virtual const JsonComponent& GetParent() = 0;
	virtual JsonComponent& Parse(std::istream& context) = 0;
};
#endif // !JASONPARSING_COMPONENTS_COMPONENTS_H_