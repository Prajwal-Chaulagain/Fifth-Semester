// Write a c program to find primitive roots of given number.

#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int powerMod(int a, int b, int n)
{
    int result = 1;
    a = a % n;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % n;
        a = (a * a) % n;
        b /= 2;
    }
    return result;
}
int main()
{
    int n, r, phi, flag = 1;
    printf("Enter the number (prime): ");
    scanf("%d", &n);
    printf("Enter the number to check: ");
    scanf("%d", &r);
    if (gcd(r, n) != 1)
    {
        printf("%d is not a primitive root of %d.\n", r, n);
        return 0;
    }
    phi = n - 1;  
    for (int k = 1; k < phi; k++)
    {
        if (powerMod(r, k, n) == 1)
        {
            flag = 0;
            break;
        }
    }
    if (flag && powerMod(r, phi, n) == 1)
        printf("%d is a primitive root of %d.\n", r, n);
    else
        printf("%d is not a primitive root of %d.\n", r, n);
    return 0;
}