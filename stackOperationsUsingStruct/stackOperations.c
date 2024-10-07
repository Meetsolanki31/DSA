#include <stdio.h>
#include <stdlib.h>

struct stack {
	int size;
	int top;
	int *arr;
};

int isEmpty(struct stack *ptr){
	if(ptr->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct stack* ptr){
	if(ptr->top == ptr->size-1){
		return 1;
	}
	else{
		return 0; 
	}
}

void push(struct stack* ptr,int val){
	if(isFull(ptr)){
		printf("Stack Overflow! You can not push %d into the stack. \n",val);
	}
	else
	{	
		ptr->top++;
		ptr->arr[ptr->top]=val;
	}
}

int pop(struct stack* ptr)
{
	if(isEmpty(ptr)){
		printf("Stack Underflow! \n");
//		return -1;
	}
	else{
		int val = ptr->arr[ptr->top];
		ptr->top--;
		return val;
	} 
}

int peek(struct stack* sp, int i){
	// here i have specified code for holding the position of array of stack so that we can return any index value we want from stack.
	int arrIndex = sp->top-i+1; // formula to get specific index to return
	if(arrIndex < 0 ){
		printf("Invalid position for the stack.");
		return -1;
	}
	else{
		return sp->arr[arrIndex];
	}
	
}
int main(int argc, char *argv[]) {
	
	struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
	
	sp->size = 40;
	sp->top = -1;
	sp->arr = (int *) malloc (sp->size *sizeof(int));
	
//	printf("Before pushing into stack,full :%d \n",isFull(sp));	
//	printf("Before pushing into stack,empty :%d \n",isEmpty(sp));
	
	// sp is passed below so that push fucntion can use the data members(sp->size,sp->top,sp->arr) of structure
	push(sp,1); // 1
	push(sp,2); // 2
	push(sp,3); // 3
	push(sp,4); // 4
//	printf("After pushing into stack,full :%d \n",isFull(sp));	
//	printf("After pushing into stack,empty :%d \n",isEmpty(sp));
	
//	printf("Popped %d from the stack \n",pop(sp));
//	printf("Popped %d from the stack \n",pop(sp));
//	printf("Popped %d from the stack \n",pop(sp));

	for(int j =1; j <= sp->top+1; j++){
		printf("The value at index %d is %d \n",j ,peek(sp, j));
	}
	    
	// here we have begun for loop from 1 just because of we are returning position not index.
	// index starts with 0. whereas, position starts with 1.
	// we have given position formula(sp->top i + 1) to access particular items of stack
	
	return 0;
}







