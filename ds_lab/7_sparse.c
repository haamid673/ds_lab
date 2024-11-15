#include <stdio.h>
int main()
{
    // Assume 4x5 sparse matrix
    int sparseMatrix[10][10], r, c, j, i;
    int compactMatrix[10][10], transpose[10][10];
    // code for inputing a sparse matrix
    printf("\nEnter the number of row and column:\n");
    scanf("%d %d", &r, &c);
    printf("\nEnter the %dx%d elements\n", r, c);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &sparseMatrix[i][j]);
    // code for siplaying matrix
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
    // Making of new matrix
    int k = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c;
             j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] =
                    sparseMatrix[i][j];
                k++;
            }
    // code for displaying the compact matrix
    printf("\n Displaying Compact matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < k; j++)
            printf("%d ", compactMatrix[i][j]);
        printf("\n");
    }
    // code for finding the transpose
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
            transpose[i][j] = compactMatrix[j][i];
    }
    // code for displaying the transpose matrix
    printf("\n Displaying transpose of Compact matrix:\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
    return 0;
}
