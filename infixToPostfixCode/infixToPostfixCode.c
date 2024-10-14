#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Here we have created char array named stack which size is 20.
//  Data can be store upto 20(0 to 19)
char stack[20];

// initial position of stack.
// it means there is no elements in stack.
int top = -1;

void push(char x)
{
    // if stack intial position is -1 then first ++top then store value of x into the top of stack.
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        // as we know in pop function,
        // first we display top which is being popped from the stack and then we decrement the top pointer.
        return stack[top--];
    }
}

// Here we have defined priority of operator so that
// we can make sure which elements enters into the stack and which elements is popped from the stack.

int precedence(int x)
{
    if (x == '(')
        // '(' --> 0 priority
        return 0;
    if (x == '+' || x == '-') // '+' and '-' has equal priority.
        return 1;
    if (x == '*' || x == '/') // '*' and '/' has equal priority.
        return 2;
    if (x == '^') // '^' and other special characters has highest priority among all the operators and special characters.
        return 3;
}
int main()
{
    
    char exp[20]; // we have created array to store infix expression having size upto 20
    char *e, x; 
    printf("Enter the expression : ");
    scanf("%s", exp);
    e = exp;

    // reads the expression or strings entered until it gets NULL
    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}
