#include "JsonParsingException.h"
#include <iostream>
#include <string>
#include <bitset>
#pragma once

enum JsonValueType
{
	string,
	number,
	object,
	array,
	true_value,
	false_value,
	null,
	undefined
};

JsonValueType NextExpectedValueType(char c);
void SkipWhiteSpace(ParsingInputPtr context);
void AssertStringIsNext(ParsingInputPtr context, std::string expectedString);
double ParseNumber(ParsingInputPtr context);
//std::string ParseString(ParsingInputPtr context);