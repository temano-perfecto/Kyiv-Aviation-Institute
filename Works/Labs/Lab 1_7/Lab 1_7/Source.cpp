#include <iostream>
using namespace std;

//1. Блочна структура програм

//void blockFunction1() {
//    int a = 10;
//    cout << "Block 1, a = " << a << endl;
//
//    // Вкладений блок
//    {
//        int b = 20;
//        cout << "Nested Block in Block 1, b = " << b << endl;
//    }
//}
//
//void blockFunction2() {
//    int c = 30;
//    cout << "Block 2, c = " << c << endl;
//}
//
//int main() {
//    cout << "Main Block" << endl;
//    blockFunction1();
//    blockFunction2();
//
//    // Вкладений блок
//    {
//        int d = 40;
//        cout << "Nested Block in Main, d = " << d << endl;
//    }
//
//    return 0;
//}

//2. Статичний розподіл пам'яті

//static int globalStaticVar = 100;  // Статична змінна поза main
//
//void functionWithStaticVar() {
//    static int staticVar = 0;  // Статична змінна всередині блоку
//    staticVar++;
//    cout << "Static Var in function: " << staticVar << endl;
//}
//
//int main() {
//    cout << "Global Static Variable: " << globalStaticVar << endl;
//
//    int localVar = 50;
//    cout << "Local Variable: " << localVar << endl;
//
//    functionWithStaticVar();
//    functionWithStaticVar();
//
//    return 0;
//}

//3. Динамічний розподіл пам'яті

//int main() {
//    int* dynamicVar1 = new int(5);  // Динамічний розподіл в main
//    cout << "Dynamic Variable 1: " << *dynamicVar1 << endl;
//
//    // Вкладений блок
//    {
//        int* dynamicVar2 = new int(10);
//        cout << "Dynamic Variable 2: " << *dynamicVar2 << endl;
//        delete dynamicVar2;  // Звільнення пам'яті
//    }
//
//    delete dynamicVar1;  // Звільнення пам'яті
//    return 0;
//}
//
////4. Операція глобального дозволу видимості імен
//
//int var = 10;  // Глобальна змінна
//
//void testFunction() {
//    int var = 20;  // Локальна змінна
//    cout << "Local var: " << var << endl;
//    cout << "Global var using scope resolution: " << ::var << endl;  // Використання глобального імені
//}
//
//int main() {
//    testFunction();
//    return 0;
//}

//5. Динамічний розподіл пам'яті в "купі"

int main() {
    // Перший вказівник
    int* heapVar1 = new int(15);
    cout << "Heap Variable 1: " << *heapVar1 << endl;

    // Другий вказівник
    int* heapVar2 = new int(25);
    cout << "Heap Variable 2: " << *heapVar2 << endl;

    // Звільнення пам'яті
    delete heapVar1;
    heapVar1 = nullptr;  // Щоб уникнути утворення сміття

    // Не звільняємо пам'ять для heapVar2 для демонстрації сміття
    // delete heapVar2;

    return 0;
}