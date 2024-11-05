#include <stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr, n, i;

    printf("Enter the no of array you want to create :");
    scanf("%d", &n);

    ptr = (int* )calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory Allocation Failed");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            ptr[i]=i+1;
        }

        printf("Stored values are:");
        for (i=0;i<n;i++)
        {
            printf("%d ",ptr[i]);
        }

    }
        free(ptr);
    return 0;
}
