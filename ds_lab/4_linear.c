#include <stdio.h>

int main() {
    int num;
    int i, item, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int array[num]; // Create an array of size 'num'

    printf("Enter the elements one by one:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &array[i]); // Input elements
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &item);

    /* Linear search begins */
    for (i = 0; i < num; i++) {
        if (item == array[i]) {
            found = 1;
            break; // Exit loop when element is found
        }
    }

    if (found == 1) {
        printf("Element is present in the array at position %d\n", i + 1); // 1-based index
    } else {
        printf("Element is not present in the array\n");
    }

    return 0;
}