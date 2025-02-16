#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Section
{
public:
	float StartX, StartY;
	float EndX, EndY;


	float SectionLengthFormula()
	{
		float firstSquare = pow(EndX - StartX, 2);
		float secondSquare = pow(EndY - StartY, 2);
		float Length = sqrt(firstSquare + secondSquare);

		return Length;
	}

	float SectionAngleToAbscissa()
	{
		float DeltaY = EndY - StartY;
		float DeltaX = EndX - StartX;
		float Angle = atan(DeltaY / DeltaX);
		float AngleInDegrees = Angle * (180 / 3, 14);

		return AngleInDegrees;
	}
};

