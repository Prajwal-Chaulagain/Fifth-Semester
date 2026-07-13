// Write a c program to multiplicative inverse of given number using Extended Euclidean Algorithm.
#include <stdio.h>

int extendedGCD(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}
int main()
{
    int a, m;
    int x, y, gcd;

    printf("Enter the number: ");
    scanf("%d", &a);

    printf("Enter the modulo: ");
    scanf("%d", &m);

    gcd = extendedGCD(a, m, &x, &y);

    if (gcd != 1)
    {
        printf("Multiplicative inverse does not exist.\n");
    }
    else
    {
        int inverse = (x % m + m) % m; 
        printf("Multiplicative inverse of %d modulo %d is: %d\n", a, m, inverse);
    }
    return 0;
}

