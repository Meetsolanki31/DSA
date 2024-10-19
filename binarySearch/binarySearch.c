#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // int arr[]= {1,3,5,6,7,9,2,0}; // array index always starts with 0.
    int arr[] = {1, 3, 4, 6, 8, 9, 11, 15};
    int size = sizeof(arr) / sizeof(int);           // formula to calculate size of array size = 8 / 4(integer takes 4 bits)
    int target = 1;                                   // value we want to search from the array
    int searchIndex = binarySearch(arr, size, target); // function calling by passing argument

    if (searchIndex != -1)
    {
        printf("The element found at index %d. \n", searchIndex); // return value where arr[i] == target
    }
    else
    {
        printf("Element not found in the array.");
    }

    return 0;
}
