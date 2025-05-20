#include <iostream>
#include "Lines.h"

using std::cout;

int main()
{
    Inherited inh;

    inh.LineLength(inh.line);
    inh.SortingBy();

    cout << inh.line << std::endl;
    cout << inh.i << std::endl;
    return 0;
}