#include <iostream>

int main() {
    // ���� ������ ���� int, float, unsigned short
    int nA;
    float fltB;
    unsigned short wC;

    // ���������� ������
    nA = 30679;
    fltB = 2.57e-4;
    wC = 2384;

    // ���� ������ ���� double, int, char
    double dblD;
    int nE;
    char chF;

    // ���������� ������ �� ��������� �������� ���������� ����
    dblD = nA;
    nE = static_cast<int>(fltB);
    chF = static_cast<char>(wC);

    // ���������� �� ��������� ������ ����������
    dblD = (double)nA;
    nE = (int)fltB;
    chF = (char)wC;

    // ����� ������ �������� ����� ���������
    void* pV;

    // ���������� � int �� double ����� ���������
    pV = &nA;
    double* pdblD = (double*)pV;
    dblD = *pdblD;

    // ���������� � float �� int ����� ���������
    pV = &fltB;
    int* pnE = (int*)pV;
    nE = *pnE;


    pV = &wC;
    char* pchF = (char*)pV;
    chF = *pchF;

    // ��������� �������
    std::cout << "nA = " << nA << std::endl;
    std::cout << "fltB = " << fltB << std::endl;
    std::cout << "wC = " << wC << std::endl;
    std::cout << "dblD = " << dblD << std::endl;
    std::cout << "nE = " << nE << std::endl;
    std::cout << "chF = " << chF << std::endl;

    return 0;
}