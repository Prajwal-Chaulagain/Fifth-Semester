// Write a c program to implement for Selection Sort.
#include <stdio.h>
#include <time.h>

int main(){
    int arr[100], i, j, min_idx, temp, n;
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
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // swap arr[i] and arr[min_idx]
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
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