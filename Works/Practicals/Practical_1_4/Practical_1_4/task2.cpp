#include <iostream>
using namespace std;

float calculateAverage()
{
    int sum = 0;
    int count = 0;
    int I = 1;

    while (I <= 10)
    { 
        // ������ 10 �� ����������� ��������, �� � ��������� �� ��������� ������� "to do"
        sum += 1;
        count += 1;
        I += 2;
    }

    return static_cast<float>(sum) / count;
}

int main2() 
{
    float result = calculateAverage();
    cout << "Result: " << result << endl;
    return 0;
}
