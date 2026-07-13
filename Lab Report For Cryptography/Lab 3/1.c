// Number Theory
// Write a c program to find totient of given number.
#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int n, count = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (gcd(n, i) == 1)
            count++;
    }
    printf("Totient of %d is: %d\n", n, count);
    return 0;
}
