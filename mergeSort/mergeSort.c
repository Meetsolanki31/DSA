#include <stdio.h>

// int arr[] and int *arr are equivalent of each other.
// This function is used to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int merge(int A[], int low, int mid, int high)
{

    int i, j, k, B[high - low + 1];
    i = low;     // this is for original array start sorting from beginning of the array
    j = mid + 1; // this is for original array for sorting partition
    k = low;

    // i iterates till mid and j iterates till end
    while (i <= mid && j <= high)
    {
        // if a[i] < a[j] then print lower means a[i] into the array b[k]
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    // this while loops for remaining element to be copied from a[i] to b[k]
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    // this while loops for remaining element to be copied from a[j] to b[k]
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    // whatsoever elements array B[i] holds copies into A[i]
    // iteration of whole array low to high so that array can be copied and print from b[i] to a[i]
    for (i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid); // sorting from low to mid
        mergeSort(A, mid + 1, high); // sorting from mid + 1 to high(last element)
        merge(A, low, mid, high); // merge whole array 
        
    }
}

int main()
{
    int A[] = {9, 14, 4, 8, 7, 5, 6};
    int n = sizeof(A) / sizeof(int);

    printf("Original Array: ");
    printArray(A, n);

    mergeSort(A, 0, n - 1);
    printf("Sorted array :");
    printArray(A, n);

    return 0;
}
