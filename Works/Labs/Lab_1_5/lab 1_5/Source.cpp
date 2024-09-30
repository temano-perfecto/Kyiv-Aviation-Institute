#include <iostream>

int main() {
    // qwerty_1
    float fA = 5.8, fB = 39.1;
    int nC = 70, nD = 42;

    bool bRes1 = !(static_cast<int>(fA == fB) ^ -(nC < nD));

    int nA = 57, nB = -12 ;
    float fC = 4.4, fD = 51;

    bool bRes2 = !((nA == nB) ^ -(fC < fD));

    // qwerty_2
    const int A = 4;
    int B = -65, D = 13, E = 2;

    int C;
    int* pC;
    pC = &C;
    *pC = 23;

    bool rez = ((A ^ (C - B)) - *pC) >= (D + (E << sizeof(long)));

    return 0;
}