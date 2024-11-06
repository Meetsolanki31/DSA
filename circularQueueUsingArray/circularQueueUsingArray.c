#include<stdio.h>
#define size 4

int queue[size];
int front = 0, rear = 0;

int isEmpty()
{
    return front == rear;
}

int isFull()
{
    // rear++ == front then queue is full
    return (rear+1) % size == front;
}

int enqueue(int value)
{
    if(isFull())
    {
        printf("Queue is full. cannot enqueue %d\n",value);
    }
    else
    {
        // circular increment formula, in simple term "rear++""
        rear = (rear + 1) % size;
        queue[rear] = value;
        printf("%d is enqueued.\n",queue[rear]);
    }
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        // circular increment formula, in simple term "front++""
        front = (front + 1) % size;
        printf("%d is dequeued\n",queue[front]);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue Elements :");
        // i = f++; i 
        for(int i = (front+ 1) % size ; i != (rear + 1) % size ; i = (i+1) % size)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    enqueue(40);
    display();
    if(isEmpty())
    {
        printf("Queue is empty.\n");
    }

    if(isFull())
    {
        printf("Queue is Full.\n");
    }

return 0;
}
