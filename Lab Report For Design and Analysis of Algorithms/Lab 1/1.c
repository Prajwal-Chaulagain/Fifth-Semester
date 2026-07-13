// Write a c program to find gcd of two numbers.
#include <stdio.h>
#include <time.h>

int main()
{
    int a, b, temp;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    start = clock();
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("GCD is %d\n", a);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}