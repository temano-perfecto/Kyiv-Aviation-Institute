#pragma once
#include <iostream>

using namespace std;

class DigitString
{
public:

	string Value;

	string SetValue()
	{
		string tmpValue;
		cout << "Set the Value: ";
		cin >> tmpValue;

		Value = tmpValue;
		return Value;
	}

	DigitString()
	{
		Value = "0";
	}

	DigitString(string ValueToSection)
	{
		Value = ValueToSection;
	}

	int CalculateSum()
	{
		int sum = 0;
		char c;
		for (auto c : Value)
		{
			sum += c - '0';
		}
		return sum;
	}

};