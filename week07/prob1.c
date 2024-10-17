#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc(sizeof(int)*(*returnSize));
    if (row == NULL){return NULL;}

    row[0]=1;

    for (int i = 1; i <= rowIndex; i++) {
        row[i] = (row[i - 1] * (rowIndex - i + 1)) / i;
    }
    
    return row; 
}

int main(int argc, char* argv[]) {
    // Check if the user passed a command-line argument
    if (argc != 2) {
        printf("Usage: %s <rowIndex>\n", argv[0]);
        return -1;  // Return an error if the input is invalid
    }

    // Parse the rowIndex from command-line argument
    int rowIndex = atoi(argv[1]);  // Convert the argument to an integer

    // Make sure the rowIndex is non-negative
    if (rowIndex < 0) {
        printf("Error: rowIndex should be a non-negative integer.\n");
        return -1;
    }

    int returnSize;
    int* row = getRow(rowIndex, &returnSize);  // Call getRow to get the Pascal's Triangle row

    // Check if memory allocation was successful
    if (row != NULL) {
        // Print the computed row
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", *(row + i));  // Access the elements using pointer arithmetic
        }
        printf("\n");

        free(row);  // Free the dynamically allocated memory
        return 0;   // Return success
    } else {
        printf("Memory allocation unsuccessful.\n");
        return -1;  // Return error if memory allocation failed
    }
}