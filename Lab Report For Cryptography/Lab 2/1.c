// Write a c program to find GCD of two given number using Euclidean Algorithm.
#include <stdio.h>

int main()
{
    int a, b, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Euclidean Algorithm
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("GCD of the given numbers is: %d\n", a);
    return 0;
}

