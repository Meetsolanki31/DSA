#include <stdio.h>
#include <stdlib.h>


void swap(int x, int y)
{
	int temp;
	
	temp = x;
	x = y;
	y = temp;
	printf("X = %d, Y = %d \n",x,y);
}


int main(int argc, char *argv[]) {
	
	int a = 10, b = 20;
	swap(10,20);
	printf("A = %d , B = %d \n",a,b);
	
	return 0;
}
