#include "..\include\ParseNumberState.h"

namespace ParseNumberState
{
	bool IsCharDigit(char c)
	{
		return '0' <= c && c <= '9';
	}

	Error* Error::GetInstance()
	{
		static Error instance;
		return &instance;
	}

	ParseState* Error::Transition(char input)
	{
		return Error::GetInstance();
	}

	Initial* Initial::GetInstance()
	{
		static Initial instance;
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

	FirstDigit* FirstDigit::GetInstance()
	{
		static FirstDigit instance;
		return &instance;
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

	DigitsBeforeDecimalPoint* DigitsBeforeDecimalPoint::GetInstance()
	{
		static DigitsBeforeDecimalPoint instance;
		return &instance;
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

	DecimalPoint* DecimalPoint::GetInstance()
	{
		static DecimalPoint instance;
		return &instance;
	}

	ParseState* DecimalPoint::Transition(char input)
	{
		if (input == '.')
		{
			return DigitsAfterDecimalPoint::GetInstance();
		}

		return Error::GetInstance();
	}

	DigitsAfterDecimalPoint* DigitsAfterDecimalPoint::GetInstance()
	{
		static DigitsAfterDecimalPoint instance;
		return &instance;
	}

	ParseState* DigitsAfterDecimalPoint::Transition(char input)
	{
		if (IsCharDigit(input))
		{
			return DigitsAfterDecimalPoint::GetInstance();
		}
		if (input == 'E' || input == 'e')
		{
			return ExponentSign::GetInstance();
		}

		return Success::GetInstance();
	}

	ExponentMarker* ExponentMarker::GetInstance()
	{
		static ExponentMarker instance;
		return &instance;
	}

	ParseState* ExponentMarker::Transition(char input)
	{
		if (input == 'E' || input == 'e')
		{
			return ExponentSign::GetInstance();
		}
		return Error::GetInstance();
	}

	ExponentSign* ExponentSign::GetInstance()
	{
		static ExponentSign instance;
		return &instance;
	}

	ParseState* ExponentSign::Transition(char input)
	{
		if (IsCharDigit(input) || input == '+' || input == '-')
		{
			return FirstExponentDigit::GetInstance();
		}
		return Error::GetInstance();
	}

	FirstExponentDigit* FirstExponentDigit::GetInstance()
	{
		static FirstExponentDigit instance;
		return &instance;
	}

	ParseState* FirstExponentDigit::Transition(char input)
	{
		if (IsCharDigit(input))
		{
			return ExponentDigits::GetInstance();
		}

		return Error::GetInstance();
	}

	ExponentDigits* ExponentDigits::GetInstance()
	{
		static ExponentDigits instance;
		return &instance;
	}

	ParseState* ExponentDigits::Transition(char input)
	{
		if (IsCharDigit(input))
		{
			return ExponentDigits::GetInstance();
		}

		return Success::GetInstance();
	}

	Success* Success::GetInstance()
	{
		static Success instance;
		return &instance;
	}

	ParseState* Success::Transition(char input)
	{
		return Error::GetInstance();
	}
}