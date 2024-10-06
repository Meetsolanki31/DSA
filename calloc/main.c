#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	
	int* ptr;
	int n,i;

	printf("Enter the size of array you want to create:\n");
	scanf("%d",&n);
	
	//we have made changes here over malloc, '*' --> ','
	// add calloc keyword
	ptr = (int *) calloc(n , sizeof(int));
	for(i=0; i<n; i++)
	{
		printf("Enter the value no %d of this array\n",i);
		scanf("%d",&ptr[i]);
	}
	
	for(i=0; i<n; i++)
	{
		printf("the value of %d of this array is %d \n",i,ptr[i]);
	}
	free(ptr);
	return 0;
}
