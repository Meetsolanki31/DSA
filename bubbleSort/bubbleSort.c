#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n)
{
    int temp;
    // for number of passes
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++) // for comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(A) / sizeof(int);

    printArray(A, n); // function to print array before sorting

    bubbleSort(A, n); // function to sorting array

    printArray(A, n); // print element after sorting

    return 0;
}
