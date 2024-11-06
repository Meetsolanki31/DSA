#include <stdio.h>

#define MAX_SIZE 4
int queue[MAX_SIZE];
int front = -1, rear = -1;

int main()
{
    int choice, item;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Enqueue
            if (rear == MAX_SIZE - 1)
            {
                printf("Overflow! Queue is full.\n");
            }
            else
            {
                printf("Enter the element: ");
                scanf("%d", &item);
                if (front == -1)
                { // Queue is initially empty
                    front = rear = 0;
                }
                else
                {
                    rear++;
                }
                queue[rear] = item;
                printf("Item inserted.\n");
            }
            break;

        case 2: // Dequeue
            if (front == -1)
            {
                printf("Underflow! Queue is empty.\n");
            }
            else
            {
                item = queue[front];
                printf("Item deleted: %d\n", item);
                if (front == rear)
                { // Only one element was in the queue
                    front = rear = -1;
                }
                else
                {
                    front++;
                }
            }
            break;

        case 3: // Display queue
            if (front == -1)
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue elements are: ");
                for (int i = front; i <= rear; i++)
                {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
            break; // Add break here to prevent fall-through

        case 4: // Exit
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
