#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[MAX];
int front = -1;
int rear = -1;

int main() {
    int choice, item;

    while (1) {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Insert element
                printf("Input the element for insertion in queue: ");
                scanf("%d", &item);
                
                if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
                    // Circular Queue is full
                    printf("\nQueue is full\n");
                } else {
                    if (front == -1 && rear == -1) {
                        // Queue is initially empty
                        front = 0;
                        rear = 0;
                    } else {
                        rear = (rear + 1) % MAX; // Circular increment
                    }
                    cqueue[rear] = item;
                }
                break;
            }

            case 2: { // Delete element
                if (front == -1 && rear == -1) {
                    // Queue is empty
                    printf("\nQueue is empty\n");
                } else {
                    printf("Deleted element: %d\n", cqueue[front]);
                    if (front == rear) {
                        // Queue becomes empty after deleting the last element
                        front = -1;
                        rear = -1;
                    } else {
                        front = (front + 1) % MAX; // Circular increment
                    }
                }
                break;
            }

            case 3: { // Display elements
                if (front == -1 && rear == -1) {
                    printf("\nQueue is empty\n");
                } else {
                    printf("\nDisplaying Queue: ");
                    int i = front;
                    while (i != rear) {
                        printf("%d ", cqueue[i]);
                        i = (i + 1) % MAX;
                    }
                    printf("%d\n", cqueue[rear]); // Display the last element
                }
                break;
            }

            case 4: {
                exit(0); // Exit the program
            }

            default: {
                printf("Wrong choice\n");
            }
        }
    }

    return 0;
}