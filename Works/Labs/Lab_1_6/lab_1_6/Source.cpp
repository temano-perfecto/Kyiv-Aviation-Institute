#include <iostream>

int main() {
    // Опис змінних типів int, float, unsigned short
    int nA;
    float fltB;
    unsigned short wC;

    // Ініціювання змінних
    nA = 30679;
    fltB = 2.57e-4;
    wC = 2384;

    // Опис змінних типів double, int, char
    double dblD;
    int nE;
    char chF;

    // Ініціювання змінних за допомогою неявного приведення типів
    dblD = nA;
    nE = static_cast<int>(fltB);
    chF = static_cast<char>(wC);

    // Ініціювання за допомогою явного приведення
    dblD = (double)nA;
    nE = (int)fltB;
    chF = (char)wC;

    // Обхід суворої типізації через вказівники
    void* pV;

    // Приведення з int до double через вказівники
    pV = &nA;
    double* pdblD = (double*)pV;
    dblD = *pdblD;

    // Приведення з float до int через вказівники
    pV = &fltB;
    int* pnE = (int*)pV;
    nE = *pnE;


    pV = &wC;
    char* pchF = (char*)pV;
    chF = *pchF;

    // Виведення значень
    std::cout << "nA = " << nA << std::endl;
    std::cout << "fltB = " << fltB << std::endl;
    std::cout << "wC = " << wC << std::endl;
    std::cout << "dblD = " << dblD << std::endl;
    std::cout << "nE = " << nE << std::endl;
    std::cout << "chF = " << chF << std::endl;

    return 0;
}