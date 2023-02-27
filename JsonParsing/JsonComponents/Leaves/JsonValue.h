#include<JsonComponents/Composites/JsonComposite.h>
#include<JsonComponents/Leaves/JsonString.h>
#include<JsonComponents/Leaves/JsonNumber.h>
#include<JsonComponents/Composites/JsonObject.h>
#include<JsonComponents/Composites/JsonArray.h>


class JsonValue : JsonComponent
{
private:
	bool isString;
	bool isNumber;
	bool isObject;
	bool isArray;
	bool isBool;
	bool isNull;
	JsonString string;
	JsonNumber number;
	JsonObject object;
	JsonArray array;
	bool boolValue;
public:
	JsonValue(JsonComponent parent);

	bool TryGetJsonString(JsonString* output);
	bool TryGetJsonNumber(JsonNumber* output);
	bool TryGetJsonObject(JsonObject* output);
	bool TryGetJsonArray(JsonArray* output);
	bool TryGetBoolValue(bool* output);
	bool IsNull();
};