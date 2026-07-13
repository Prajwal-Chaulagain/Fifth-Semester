// Write a c program to implement for Subset Construction Problem.
#include <stdio.h>
#include <time.h>
int set[20], subset[20];
int n;
void generateSubset(int i)
{
    if (i == n)
    {
        printf("{ ");
        for (int j = 0; j < n; j++)
        {
            if (subset[j] == 1)
                printf("%d ", set[j]);
        }
        printf("}\n");
        return;
    }
    subset[i] = 1;
    generateSubset(i + 1);
    subset[i] = 0;
    generateSubset(i + 1);
}
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);
    clock_t start = clock();
    printf("Subsets are:\n");
    generateSubset(0);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);
    return 0;
}
