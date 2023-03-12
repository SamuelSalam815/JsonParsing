#include "JsonParsingException.h"
#include <iostream>
#include <string>
#pragma once

bool IsExpectedStringNext(ParsingInputPtr context, std::string expectedString);
void SkipWhiteSpace(ParsingInputPtr context);
double ParseNumber(ParsingInputPtr context);
//std::string ParseString(ParsingInputPtr context);