#include <stdio.h>

int main() {
    int c, first, last, middle, n, search, array[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers in sorted order:\n", n);
    for (c = 0; c < n; c++) {
        scanf("%d", &array[c]); // Input the sorted array elements
    }

    printf("Enter value to find: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        if (array[middle] < search) {
            first = middle + 1; // Search in the right half
        } else if (array[middle] == search) {
            printf("%d found at location %d.\n", search, middle + 1); // 1-based index
            break;
        } else {
            last = middle - 1; // Search in the left half
        }
        middle = (first + last) / 2; // Recalculate the middle index
    }

    if (first > last) {
        printf("Not found! %d isn't present in the list.\n", search);
    }

    return 0;
}