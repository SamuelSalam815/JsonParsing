#include <iostream>

struct JsonComponent
{
	virtual void PrintToStream(std::ostream& output) = 0;
};

struct JsonValue : JsonComponent
{
public:
	JsonValue();
	JsonValue(bool bool_value);
	JsonValue(double number_value);
	
	// Inherited from JsonComponent
	void PrintToStream(std::ostream& output);

private:
	bool bool_value;
	double number_value;

	enum value_type
	{
		null,
		boolean,
		number
	}value_type;
};