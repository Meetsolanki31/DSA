#include <stdio.h>

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[]= {1,3,5,6,7,9,2,0};
    int size = sizeof(arr)/sizeof(int);
    int target = 4;
    int searchIndex = linearSearch(arr,size,target);

    if(searchIndex != -1)
    {
        printf("The element found at index %d. \n",searchIndex);
    }
    else
    {
        printf("Element not found in the array.");
    }

    return 0;
}
