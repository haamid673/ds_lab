#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *newnode, *top = 0, *temp;

void push() {
    newnode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node
    if (!newnode) {
        printf("Heap Overflow\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->data);  // Input data
    newnode->next = top;  // Point newnode's next to the current top node
    top = newnode;  // Set newnode as the new top of the stack
}

void pop() {
    if (top == 0) {
        printf("Stack empty\n");  // Stack is empty
    } else {
        temp = top;
        printf("Popped element: %d\n", temp->data);  // Print the data being popped
        top = top->next;  // Move the top pointer to the next node
        free(temp);  // Free memory of the old top node
    }
}

void display() {
    if (top == 0) {
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("Stack elements: ");
        while (temp != 0) {
            printf("%d ", temp->data);  // Print the data
            temp = temp->next;  // Move to the next node
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);  // Input the user's choice

        switch (choice) {
            case 1:
                push();  // Call push function to insert element
                break;
            case 2:
                pop();  // Call pop function to remove top element
                break;
            case 3:
                display();  // Call display function to show stack contents
                break;
            case 4:
                exit(0);  // Exit the program
            default:
                printf("Wrong choice\n");  // Handle invalid choices
        }
    }
    return 0;
}