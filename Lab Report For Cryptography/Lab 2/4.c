// Write a c program to find additive inverse of given number.
#include <stdio.h>

int main()
{
    int a, mod, additive_inverse;
    printf("Enter an integer and the modulus to find its additive inverse: ");
    scanf("%d %d", &a, &mod);
    additive_inverse = (mod - (a % mod)) % mod;

    printf("Additive inverse of %d mod %d is: %d\n", a, mod, additive_inverse);

    return 0;
}

