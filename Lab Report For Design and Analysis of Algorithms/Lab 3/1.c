// Write a c program to implement for Fractional Knapsack Problem.
#include <stdio.h>
#include <time.h>

struct Item
{
    int value;
    int weight;
    float ratio;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

float fractionalKnapsack(int capacity, struct Item arr[], int n)
{
    sortItems(arr, n);
    float totalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (capacity >= arr[i].weight)
        {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        }
        else
        {
            totalValue += arr[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main()
{
    int n, capacity;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].weight, &arr[i].value);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    start = clock();
    float maxValue = fractionalKnapsack(capacity, arr, n);
    end = clock();
    printf("Maximum value = %.2f\n", maxValue);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
