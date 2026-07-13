// Write a c program to illustrate functioning of S-box of DES.
#include <stdio.h>
#include <string.h>
#include <math.h>

int S1[4][16] = {
    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};
int binaryToDecimal(char bin[], int start, int end)
{
    int decimal = 0;
    int power = 0;
    for (int i = end; i >= start; i--)
    {
        decimal += (bin[i] - '0') * pow(2, power);
        power++;
    }
    return decimal;
}
void decimalToBinary(int num)
{
    int binary[4];
    for (int i = 3; i >= 0; i--)
    {
        binary[i] = num % 2;
        num = num / 2;
    }
    printf("Output (4-bit): ");
    for (int i = 0; i < 4; i++)
        printf("%d", binary[i]);
}
int main()
{
    char input[7];
    printf("Enter 6-bit input: ");
    scanf("%s", input);
    char rowBits[3];
    rowBits[0] = input[0];
    rowBits[1] = input[5];
    rowBits[2] = '\0';

    int row = binaryToDecimal(rowBits, 0, 1);
    int col = binaryToDecimal(input, 1, 4);

    printf("Row: %d\n", row);
    printf("Column: %d\n", col);

    int value = S1[row][col];

    printf("S-Box Value (Decimal): %d\n", value);
    decimalToBinary(value);
    return 0;
}

