#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
    }

    for (i = 0; i < n; i++) {
        ptr[i] = i + 1; 
    }

    printf("Stored values are::\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    printf("Enter the new size of array you want to create : ");
    scanf("%d",&n);

    ptr = (int*) realloc(ptr,n*sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory Allocation Failed");
    }
    else
    {
        for(i = 0; i<n;i++)
        {
            ptr[i]=i+1;
        }

        printf("Stored value are:");
        for(i=0;i<n;i++)
        {
            printf("%d ",ptr[i]);
        }
    }

    free(ptr);
    return 0;
}
