// Write a c program to implement for Insertion Sort.
#include <stdio.h>
#include <time.h>

int main()
{
    int arr[100], i, j, key, n;
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

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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