#include <memory>

#pragma once

// Intended to be a family of singletons
// Smart pointers not needed
struct ParseState
{
public:
	virtual ParseState* Transition(char input) = 0;

	// Delete copy constructor
	ParseState(ParseState const&) = delete;
	// Delete assignment
	void operator=(ParseState const&) = delete;

protected:
	ParseState() {};
};

namespace ParseNumberState
{
	struct Error : ParseState
	{
	public:
		static Error* GetInstance();
		ParseState* Transition(char input);
	private:
		Error() {}
	};

	struct Initial : ParseState
	{
	public:
		static Initial* GetInstance();
		ParseState* Transition(char input);
	private:
		Initial() {}
	};

	struct FirstDigit : ParseState
	{
	public:
		static FirstDigit* GetInstance();
		ParseState* Transition(char input);
	private:
		FirstDigit() {}
	};

	struct DigitsBeforeDecimalPoint : ParseState
	{
	public:
		static DigitsBeforeDecimalPoint* GetInstance();
		ParseState* Transition(char input);
	private:
		DigitsBeforeDecimalPoint() {}
	};

	struct DecimalPoint : ParseState
	{
	public:
		static DecimalPoint* GetInstance();
		ParseState* Transition(char input);
	private:
		DecimalPoint() {}
	};

	struct DigitsAfterDecimalPoint : ParseState
	{
	public:
		static DigitsAfterDecimalPoint* GetInstance();
		ParseState* Transition(char input);
	private:
		DigitsAfterDecimalPoint() {}
	};

	struct ExponentMarker : ParseState
	{
	public:
		static ExponentMarker* GetInstance();
		ParseState* Transition(char input);
	private:
		ExponentMarker() {}
	};

	struct ExponentSign : ParseState
	{
	public:
		static ExponentSign* GetInstance();
		ParseState* Transition(char input);
	private:
		ExponentSign() {}
	};

	struct FirstExponentDigit : ParseState
	{
	public:
		static FirstExponentDigit* GetInstance();
		ParseState* Transition(char input);
	private:
		FirstExponentDigit() {}
	};

	struct ExponentDigits : ParseState
	{
	public:
		static ExponentDigits* GetInstance();
		ParseState* Transition(char input);
	private:
		ExponentDigits() {}
	};

	struct Success : ParseState
	{
	public:
		static Success* GetInstance();
		ParseState* Transition(char input);
	private:
		Success() {}
	};
}

