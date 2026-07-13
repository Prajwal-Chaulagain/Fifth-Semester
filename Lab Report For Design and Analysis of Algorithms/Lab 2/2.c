// Write a c program to implement for Min Max Finding.
#include <stdio.h>
#include <time.h>

void findMinMax(int arr[], int low, int high, int *min, int *max)
{
    if (low == high)
    {
        *min = arr[low];
        *max = arr[low];
        return;
    }
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    int minLeft, maxLeft, minRight, maxRight;
    findMinMax(arr, low, mid, &minLeft, &maxLeft);
    findMinMax(arr, mid + 1, high, &minRight, &maxRight);
    *min = (minLeft < minRight) ? minLeft : minRight;
    *max = (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main()
{
    int arr[100], n;
    clock_t start, end;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min, max;
    start = clock();
    findMinMax(arr, 0, n - 1, &min, &max);
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Minimum element = %d\n", min);
    printf("Maximum element = %d\n", max);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
