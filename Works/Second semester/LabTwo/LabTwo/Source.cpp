#include <iostream>
#include "Section.h"

using namespace std;

int main()
{


    Section sect1{ 10, 14, 47, 53 };

    float SectionLength = sect1.SectionLengthFormula();
    float SectionAngle = sect1.SectionAngleToAbscissa();

    cout << "The length of this Section is equals: ";
    cout << SectionLength;
    cout << "\nThe Angle of this Section relatively to Absciss is equals: ";
    cout << SectionAngle;

}