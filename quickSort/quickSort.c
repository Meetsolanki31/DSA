#include <stdio.h>

// int arr[] and int *arr are equivalent of each other.
// we can declare any of above if we wanna create an array.
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; 
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot )
        {
            j--;
        }   

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i < j);

    // Arr[low] --> pivot elements
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] =temp;
    return j;
    // above code swap pivot elments Arr[low] with Arr[j]
} 

void quickSort(int arr[],int low,int high)
{
    if(low < high)
    {
    int partitionIndex; // index of pivot after partition

    partitionIndex = partition(arr,low,high);
    printArray(arr,9); 

    // below code the array into two part first part left sub array and right sub array
    // consider we have array[3, 5, 2, 13, 12, 7, 1, 8, 4]
    // we took 3(first element) as pivot and set it like that every lesser element
    // remain left side of pivot and every greater element remain right side of pivot
    // in the result, we got array like below  
    // 2 1 3 13 12 7 5 8 4 

    quickSort(arr, low, partitionIndex - 1); // sort left sub array
    // (arr[2,1,3,13,12,7,5,8,4], 0, 2-1)
        // arr[0]=2 
        // arr[1]=1
        // arr[2]=3
        // arr[3]=13 
        // arr[4]= 12
        // arr[5]= 7
        // arr[6]= 5
        // arr[7]= 8
        // arr[8]= 4
    // final array for sorting would be from index 0 to 1 -->{2,1}

    quickSort(arr, partitionIndex + 1, high);  // sort right sub array
    // (arr[2,1,3,13,12,7,5,8,4], 2+1, 8)
        // arr[0]=2 
        // arr[1]=1
        // arr[2]=3
        // arr[3]=13 
        // arr[4]= 12
        // arr[5]= 7
        // arr[6]= 5
        // arr[7]= 8
        // arr[8]= 4
    // so final array for sortinh would be from index 3 to 8 --> {13,12,7,5,8,4}
    }
}

int main()
{

    int arr[] = {3, 5, 2, 13, 12, 7, 1, 8, 4};
    int n = sizeof(arr)/sizeof(int);
    // int n = sizeof(A)/sizeof(int);

    printArray(arr, n);
    quickSort(arr, 0,n - 1);
    printf("Sorted Array :");
    printArray(arr, n);
    return 0;
}
