#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct node {
    int data;
    struct node *next;
};

// Declare pointers for the front and rear of the queue
struct node *front = NULL, *rear = NULL, *temp;

// Function to add an element to the queue (enqueue)
void enqueue() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node
    if (newnode == NULL) {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->data); // Input data for the new node
    newnode->next = NULL; // The new node will point to NULL
    
    if (front == NULL && rear == NULL) {
        // If the queue is empty, both front and rear will point to the new node
        front = rear = newnode;
    } else {
        // If the queue is not empty, add the new node to the end and update rear
        rear->next = newnode;
        rear = newnode;
    }
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    if (front == NULL && rear == NULL) {
        // If the queue is empty
        printf("Queue is empty\n");
    } else {
        temp = front; // Store the current front node in a temporary variable
        printf("Dequeued element: %d\n", front->data); // Print the dequeued element
        if (front == rear) {
            // If there is only one element in the queue, reset both front and rear
            front = rear = NULL;
        } else {
            // Move the front to the next node
            front = front->next;
        }
        free(temp); // Free the memory of the dequeued node
    }
}

// Function to display the elements of the queue
void display() {
    if (front == NULL && rear == NULL) {
        // If the queue is empty
        printf("Queue is empty\n");
    } else {
        temp = front; // Start from the front of the queue
        printf("Queue elements: ");
        while (temp != NULL) {
            // Traverse the queue and print each element
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        // Display menu options
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}