#include "..\include\ParseNumberState.h"

namespace ParseNumberState
{
	bool IsCharDigit(char c)
	{
		return '0' <= c && c <= '9';
	}

	ParseState* Error::Transition(char input)
	{
		return Error::GetInstance();
	}

	Error* Error::GetInstance()
	{
		static Error instance;
		return &instance;
	}

	ParseState* Initial::Transition(char input)
	{
		switch (input)
		{
		case '-':
			return FirstDigit::GetInstance();
		case '0':
			return DecimalPoint::GetInstance();
		}

		if (IsCharDigit(input))
		{
			return DigitsBeforeDecimalPoint::GetInstance();
		}
		return Error::GetInstance();
	}

	ParseState* FirstDigit::Transition(char input)
	{
		if (input == '0')
		{
			return DecimalPoint::GetInstance();
		}
		if (IsCharDigit(input))
		{
			return DigitsBeforeDecimalPoint::GetInstance();
		}
		return Error::GetInstance();
	}

	ParseState* DigitsBeforeDecimalPoint::Transition(char input)
	{
		if (IsCharDigit(input))
		{
			return DigitsBeforeDecimalPoint::GetInstance();
		}
		switch (input)
		{
		case '.':
			return DigitsAfterDecimalPoint::GetInstance();
		case 'E':
		case 'e':
			return ExponentSign::GetInstance();
		default:
			return Success::GetInstance();
		}

	}
}