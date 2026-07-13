// Write a C program to implement the Kolmogorov-Smirnov Test.
#include <stdio.h>
#include <math.h>

void sort(float x[], int n)
{
    float temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    float x[100], d_plus = 0, d_minus = 0, d, d_crit;

    printf("Enter number of observations: ");
    scanf("%d", &n);

    printf("Enter the data (values between 0 and 1):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    sort(x, n);

    for (int i = 0; i < n; i++)
    {
        float d1 = ((float)(i + 1) / n) - x[i];
        float d2 = x[i] - ((float)i / n);

        if (d1 > d_plus)
            d_plus = d1;

        if (d2 > d_minus)
            d_minus = d2;
    }
    d = (d_plus > d_minus) ? d_plus : d_minus;
    d_crit = 1.36 / sqrt(n);
    printf("\nD+ = %f", d_plus);
    printf("\nD- = %f", d_minus);
    printf("\nD  = %f", d);
    printf("\nCritical Value = %f\n", d_crit);
    if (d < d_crit)
        printf("Result: Accept Null Hypothesis (Good fit)\n");
    else
        printf("Result: Reject Null Hypothesis (Not a good fit)\n");
    return 0;
}