// Write a c program to find nth fibonacci number.
#include <stdio.h>
#include <time.h>

int main()
{
    int a = 0, b = 1, n, next;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    start = clock();

    while (n - 1)
    {
        next = a + b;
        a = b;
        b = next;
        n--;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Nth Fibonacci number is %d\n", a);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}