// Write a c program to implement for N-Queen Problem.  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int board[MAX], n;

int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    return 1;
}

void printSolution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%s ", board[i] == j ? "1" : "0");
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int row)
{
    if (row == n)
    {
        printSolution();
        return;
    }
    for (int col = 0; col < n; col++)
        if (isSafe(row, col))
        {
            board[row] = col;
            solveNQueens(row + 1);
        }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);
    clock_t start = clock();
    solveNQueens(0);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);
    return 0;
}
