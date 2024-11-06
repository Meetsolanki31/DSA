#include <stdio.h>
#define SIZE 5  // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == SIZE - 1;
}

// Function to insert an element into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0;  // Set front to 0 for the first element
        rear++;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue\n");
    } else {
        printf("Dequeued %d\n", queue[front]);
        front++;
        if (front > rear) {  // Reset the queue when empty
            front = rear = -1;
        }
    }
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);


    display();  // Display all elements

    dequeue();
    dequeue();

    display();  // Display elements after dequeuing

    enqueue(60);  // Try to add another element
    display();

    return 0;
}