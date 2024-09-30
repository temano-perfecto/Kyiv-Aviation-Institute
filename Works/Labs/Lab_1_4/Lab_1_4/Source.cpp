#include <stdio.h>

int main() {
    unsigned short us_var = 1400;
    int int_var = -386;
    float float_var = 4.4525;
    double double_var = -7.3e23;

    unsigned short* us_ptr;
    int* int_ptr;
    float* float_ptr;
    double* double_ptr;

    void* void_ptr;

    us_ptr = &us_var;
    int_ptr = &int_var;
    float_ptr = &float_var;
    double_ptr = &double_var;

    void_ptr = &us_var;

    printf("Unsigned short value: %hu\n", *us_ptr);
    printf("Int value: %d\n", *int_ptr);
    printf("Float value: %f\n", *float_ptr);
    printf("Double value: %e\n", *double_ptr);

    void_ptr = &int_var;
    printf("Void pointer now points to int value: %d\n", *(int*)void_ptr);

    return 0;
}
