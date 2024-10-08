int fibonacci(int N) 
{
    int fib1 = 1;
    int fib2 = 2;
    int fibN;
    int i = 2;
    if (i >= N) {
        fibN = 1;
    }
    else {
        do {
            fibN = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibN;
            ++i;
        } while (i != N);
    }
    return fibN;
}

int main() {
    int x = fibonacci(4);
    return 0;
}
