#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue[MAX];
int rear = -1;
int front = -1;

int main() {
    int choice;
    
    while (1) {
        printf("\n1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: { // Insert element into queue
                int num;
                if (rear == MAX - 1) {
                    printf("Queue Overflow\n");
                } else {
                    if (front == -1) {
                        front = 0; // Queue is initially empty
                    }
                    printf("Insert the element in queue: ");
                    scanf("%d", &num);
                    rear = rear + 1;
                    queue[rear] = num;
                }
                break;
            }

            case 2: { // Delete element from queue
                if (front == -1 || front > rear) {
                    printf("Queue Underflow\n");
                } else {
                    printf("Deleted element: %d\n", queue[front]);
                    front = front + 1;
                }
                break;
            }

            case 3: { // Display elements in queue
                if (front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 4: {
                exit(0); // Normal program termination
            }

            default: {
                printf("Wrong choice\n");
            }
        }
    }

    return 0;
}