// Write a c program to check if the given two number is co-prime or not.(Relatively Prime).
#include <stdio.h>

int main()
{
    int a, b, temp, gcd;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Find GCD using Euclidean Algorithm
    int x = a, y = b;
    while (y != 0)
    {
        temp = y;
        y = x % y;
        x = temp;
    }
    gcd = x;
    if (gcd == 1)
        printf("%d and %d are Co-Prime numbers.\n", a, b);
    else
        printf("%d and %d are NOT Co-Prime numbers.\n", a, b);
    return 0;
}

