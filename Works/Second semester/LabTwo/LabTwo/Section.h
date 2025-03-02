#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Section
{
public:

   

    Section() {}

    Section(float OneX, float OneY, float TwoX, float TwoY) : StartX(OneX), StartY(OneY), EndX(TwoX), EndY(TwoY) {}

    float StartX{ 0 };
    float StartY{ 0 };
    float EndX{ 0 };
    float EndY{ 0 };

    ~Section()
    {
    }

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
        float Angle = atan2(DeltaY, DeltaX);
        float AngleInDegrees = Angle * (180 / 3.14);

        return AngleInDegrees;
    }
};