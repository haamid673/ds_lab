#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main() {
    int stack[MAX], choice, item, TOP = -1, i;

    while (1) {
        printf("\n*****MENU*****");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (TOP == MAX - 1) {
                    printf("\nStack is full");
                } else {
                    printf("\nEnter the value to be inserted: ");
                    scanf("%d", &item);
                    TOP++;
                    stack[TOP] = item;
                }
                break;

            case 2:
                if (TOP == -1) {
                    printf("\nStack is empty");
                } else {
                    printf("\nPopped element is %d", stack[TOP]);
                    TOP--;
                }
                break;

            case 3:
                if (TOP == -1) {
                    printf("\nStack is empty");
                } else {
                    printf("\nDisplaying stack: ");
                    for (i = TOP; i >= 0; i--) {
                        printf("%d ", stack[i]);
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }

    return 0;
}