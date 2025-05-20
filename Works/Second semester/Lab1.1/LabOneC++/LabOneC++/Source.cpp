#include <iostream>
#include "SectionClass.h"

using namespace std;

int main()
{
	Section Sect;
	cout << "Enter Section's Coordinates in particular order: Ax, Ay, Bx, By\n";
	cin >> Sect.StartX;
	cin >> Sect.StartY;
	cin >> Sect.EndX;
	cin >> Sect.EndY;

	float SectionLength = Sect.SectionLengthFormula();
	float SectionAngle = Sect.SectionAngleToAbscissa();

	cout << "The length of this Section is equals: ";
	cout << SectionLength;
	cout << "\nThe Angle of this Section relatively to Absciss is equals: ";
	cout << SectionAngle;

}