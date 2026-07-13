// Write a c program to implement for Bubble Sort.
#include <stdio.h>
#include <time.h>

int main()
{
    int arr[100], i, j, temp, n;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter %d integers: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);

    return 0;
}