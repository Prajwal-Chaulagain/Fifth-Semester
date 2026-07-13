// Write a c program to implement for Zero One Knapsack.
#include <stdio.h>
#include <time.h>
// Function to return maximum value that can be put in knapsack
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int n, W, i;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &val[i]);
    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &wt[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    clock_t start, end;
    start = clock();
    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);
    return 0;
}
