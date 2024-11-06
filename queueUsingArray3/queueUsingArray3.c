#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow.\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("%d is enqueued.\n",q->arr[q->r]);
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;

    if (isEmpty(q))
    {
        printf("Queue is empty. Underflow\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct Queue *q)
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
    struct Queue q;

    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 5);
    enqueue(&q, 2);

    printf("%d is dequeued \n", dequeue(&q));
    printf("%d is dequeued \n", dequeue(&q));

    display(&q);
    
    if (isEmpty(&q))
    {
        printf("Queue is empty or underflow\n");
    }

    if (isFull(&q))
    {
        printf("Queue is full. overflow\n");
    }

    return 0;
}
