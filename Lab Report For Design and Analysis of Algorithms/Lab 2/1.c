// Write a c program to implement for Binary Search.
#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearch(arr, mid + 1, high, key);
    else
        return binarySearch(arr, low, mid - 1, key);
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    clock_t start, end;
    printf("Enter element to search: ");
    scanf("%d", &key);
    start = clock();
    int result = binarySearch(arr, 0, size - 1, key);
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
