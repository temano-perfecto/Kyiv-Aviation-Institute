#include <iostream>
#include "StringDigits.h"

using namespace std;

int main()
{
	DigitString String;


	DigitString cOne;
	DigitString cTwo = { "12345" };
	DigitString cThreeCopy(cTwo);


	cout << "C1 " << cOne.Value << " Sum " << String.CalculateSum() << endl;
	cout << "C2 " << cTwo.Value << " Sum " << String.CalculateSum() << endl;
	cout << "C3 " << cThreeCopy.Value << " Sum " << String.CalculateSum() << endl;


	return 0;
}