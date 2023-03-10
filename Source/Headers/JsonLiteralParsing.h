#include "JsonParsingException.h"
#include <iostream>
#include <string>
#pragma once

bool IsExpectedStringNext(std::istream& context, std::string expectedString);
void SkipWhiteSpace(std::istream& context);
void ParseNumber(std::istream& context, double* output);
void ParseString(std::istream& context, std::string* output);