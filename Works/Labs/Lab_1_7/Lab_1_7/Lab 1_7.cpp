#include <iostream>
using namespace std;

int main() {
    {
        int nA = 5;
    }

    {
        int nB = 4;
        {
            nB = 7;
            int nC = 2;
        }
    }

    static int A = 10;
    static int B;

    B = 20;
    {
        static int E = 5;
        int C;
        C = A * 12; 
        E = C + B;
    }

    A += 10;
    B++;

    float K = 20;
    int L = 0;

    for (int i = 0; i < 5; i++) {
        static int F = 0;
        F++;
        int S = 0;
        S++;
        L++;
    }

    char cA = '!';
    {
        char cA = '?';
        int Q = 1;
        {
            char cA = '@';
            int Q = 2;
            int M = 6;
        }
        Q = Q + 5;
        Q++;
    }

    for (int i = 0; i < 5; i++) {
        static int iA = 0;
        int iB = 0;
        iA = iA + 1;
        iB = iB + 1;
    }

    int* I;
    I = new int;
    *I = 25;

    int* W;
    W = new int;
    *W = 10;
    W = I;
    delete W;

    return 0;
}
