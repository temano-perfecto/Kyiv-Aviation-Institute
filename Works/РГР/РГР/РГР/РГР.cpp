#include <iostream>
#include <cctype>

using namespace std;

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isLetterInFirstRange(char c)
{
	return c >= 'A' && c <= 'E';
}

bool isLetterInSecondRange(char c)
{
	return c >= 'F' && c <= 'Z';
}


bool IsStringValid(const string& str)
{

	int LengthOfChain = str.length();

	if (LengthOfChain == 0 || str[0] != 'A')
	{
		return false;
	}

	int i = 0;
	for (i; i < LengthOfChain; i++)
	{
		char charr = str[i];


		if (charr == '_') {
			break;
			return i;
		}

	}

	if (str[i] == '_')
	{

		if (isLetterInFirstRange(str[i - 1]) && isLetterInSecondRange(str[i + 1]) || isDigit(str[i + 1]))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		return true;
	}


	return true;
}


int main()
{
	string input;

	cout << "Enter Chain: ";
	cin >> input;

	if (IsStringValid(input)) {
		cout << "Your String is Valid";
	}
	else
	{
		cout << "String is Invalid";
	}

}