// Write a c program to check if given number is prime or not using traditional method.
#include <stdio.h>

int main()
{
    int n, i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 1)
    {
        flag = 1;
    }
    else
    {
        for (i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
        printf("%d is a Prime number.\n", n);
    else
        printf("%d is not a Prime number.\n", n);
    return 0;
}
