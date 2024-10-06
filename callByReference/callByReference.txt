#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;	
}
int main(int argc, char *argv[]) {
	
	int a = 100, b = 200;		
	printf("A = %d, B = %d \n",a,b);
	swap(&a,&b);
	printf("A = %d, B = %d \n",a,b);
	
	
	return 0;
}


