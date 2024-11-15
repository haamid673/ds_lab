#include<stdio.h>
#define N 20

int Q[N], Pr[N]; // Q is the queue array, Pr is the priority array
int r = -1, f = -1; // r for rear, f for front

void enqueue(int data, int p) { // Enqueue function to insert data with priority
    int i;

    if ((f == 0 && r == N - 1)) { // Check if Queue is full
        printf("Queue is full\n");
        return;
    }

    if (f == -1) { // If Queue is empty
        f = r = 0;
        Q[r] = data;
        Pr[r] = p;
    } else { // If there are some elements in the Queue
        // Shift elements to maintain priority order
        for (i = r; i >= f; i--) {
            if (p > Pr[i]) { // Compare priority
                Q[i + 1] = Q[i];
                Pr[i + 1] = Pr[i];
            } else {
                break;
            }
        }
        Q[i + 1] = data; // Insert the data
        Pr[i + 1] = p;   // Insert its priority
        r++; // Increase rear
    }
}

void print() { // Print the queue
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        printf("\nQueue elements are:\n");
        for (int i = f; i <= r; i++) {
            printf("Element = %d\tPriority = %d\n", Q[i], Pr[i]);
        }
    }
}

int dequeue() { // Dequeue function to remove the front element
    if (f == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = Q[f];
        printf("Deleted Element = %d\tIts Priority = %d\n", Q[f], Pr[f]);

        if (f == r) { // If there was only one element
            f = r = -1;
        } else {
            f++; // Move front forward
        }

        return data;
    }
}

int main() {
    int opt, n, i, data, p;

    do {
        printf("\n\n1. Insert Data in Queue");
        printf("\n2. Show Data in Queue");
        printf("\n3. Delete Data from Queue");
        printf("\n0. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\nEnter the number of data to insert: ");
                scanf("%d", &n);
                i = 0;
                while (i < n) {
                    printf("\nEnter your data and its priority: ");
                    scanf("%d %d", &data, &p);
                    enqueue(data, p);
                    i++;
                }
                break;
            case 2:
                print();
                break;
            case 3:
                dequeue();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Incorrect choice, try again!\n");
        }
    } while (opt != 0);

    return 0;
}