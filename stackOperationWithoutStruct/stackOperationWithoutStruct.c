#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow! You cannot push %d into the stack.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow! You cannot pop from the stack.\n");
    } else {
        printf("%d popped from the stack\n", stack[top]);
        top--;
    }
}

void peep() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("The top element is %d.\n", stack[top]);
    }
}

int peek(int pos) {
    int arrIndex = top - pos + 1;
    if (arrIndex < 0) {
        printf("Invalid position for stack.\n");
        return -1;
    } else {
        return stack[arrIndex];
    }
}

void change(int pos, int newValue) {
    int arrIndex = top - pos + 1;
    if (arrIndex < 0 || pos <= 0) {
        printf("Invalid position.\n");
    } else {
        stack[arrIndex] = newValue;
        printf("Value at position %d changed to %d.\n", pos, newValue);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value, position;

    while (1) {  // Infinite loop until user chooses to exit
        printf("\nStack Operations:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. PEEK\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement inside the loop to handle the operations based on user input
        switch (choice) {
            case 1:  // Push
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:  // Pop
                pop();
                break;
            case 3:  // Peep
                peep();
                break;
            case 4:  // Change
                printf("Enter the position from top to change: ");
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &value);
                change(position, value);
                break;
            case 5:  // Display
                display();
                break;
            case 6:  // Peek
                printf("Enter the position from top to PEEK: ");
                scanf("%d", &position);
                value = peek(position);
                if (value != -1) {
                    printf("Element at position %d is %d\n", position, value);
                }
                break;
            case 7:  // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}