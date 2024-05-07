#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printPathsRec(int right, int down, int idx, int total, char *path, int array[MAX][MAX], int r, int c, int *value_path, int *AB) {
    if (right == 0 && down == 0) {
        // Print the path and store values in AB
        printf("%s - Values: ", path);
        for (int i = 0; i < total; i++) {
            printf("%d ", value_path[i]);
            AB[i] = value_path[i]; // Store the value path in AB
        }
        printf("\n");
        return;
    }

    if (right > 0) {
        path[idx] = '1'; // Move right
        value_path[idx] = array[r][c + 1]; // Store the value at the next right position
        printPathsRec(right - 1, down, idx + 1, total, path, array, r, c + 1, value_path, AB);
    }

    if (down > 0) {
        path[idx] = '0'; // Move down
        value_path[idx] = array[r + 1][c]; // Store the value at the next down position
        printPathsRec(right, down - 1, idx + 1, total, path, array, r + 1, c, value_path, AB);
    }
}

void printPaths(int n, int m, int array[MAX][MAX], int *AB) {
    int totalMoves = n + m;
    char path[2*(MAX) + 1] = {0}; // Fixed-size array for path with room for null terminator
    int value_path[2*(MAX)] = {0}; // Fixed-size array for storing the values along the path
    path[totalMoves] = '\0'; // Ensure the string is null-terminated
    value_path[0] = array[0][0]; // Start from the top-left corner value

    printPathsRec(m, n, 0, totalMoves, path, array, 0, 0, value_path, AB);
}

int main() {
    int n, m;
    printf("Enter the number of rows (n), max 10: ");
    scanf("%d", &n);
    printf("Enter the number of columns (m), max 10: ");
    scanf("%d", &m);
    getchar(); // Consume newline character left in input buffer

    if (n > MAX || m > MAX) {
        printf("Error: Number of rows or columns cannot exceed 10.\n");
        return 1;
    }

    int array[MAX][MAX] = {0}; // Declare and input the array
    int AB[MAX]; // Declare the AB array in main

    for (int i = 0; i < n; i++) {
        printf("Enter %d integers for row %d (separated by space): ", m, i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("The entered array is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    n--; // Adjust for zero-based index sizes
    m--;

    printPaths(n, m, array, AB);

    return 0;
}
