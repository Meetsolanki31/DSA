#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}
int enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow.\n");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("%d is enqueued.\n", q->arr[q->r]);
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;

    if (isEmpty(q))
    {
        printf("Queue is empty. Underflow\n");
    }
    else
    {
        q->f = (q->f + 1)%q->size;
        a = q->arr[q->f];
        printf("%d is dequeued \n",a);
    }
    return a;
}

void display(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct circularQueue q;

    q.size = 4;

    // front = rear = -1; --> this is for linear queue or simple queue 

    // front = rear = 0; --> this is for circular queue 
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 5);


    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    // printf("%d is dequeued \n", dequeue(&q));
    // printf("%d is dequeued \n", dequeue(&q));

    // display(&q);
    enqueue(&q,45);
    enqueue(&q,45);
    enqueue(&q,45);
    if (isEmpty(&q))
    {
        printf("Queue is empty.\n");
    }

    if (isFull(&q))
    {
        printf("Queue is full.\n");
    }

    return 0;
}