#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printPathsRec(int right, int down, int idx, int total, char *path, int array[MAX][MAX], int r, int c, int *value_path) {
    if (right == 0 && down == 0) {
        // Print the path
        printf("%s - Values: ", path);
        for (int i = 0; i < total; i++) {
            printf("%d ", value_path[i]);
        }
        printf("\n");
        return;
    }

    if (right > 0) {
        path[idx] = '1'; // Move right
        value_path[idx] = array[r][c + 1]; // Store the value at the next right position
        printPathsRec(right - 1, down, idx + 1, total, path, array, r, c + 1, value_path);
    }

    if (down > 0) {
        path[idx] = '0'; // Move down
        value_path[idx] = array[r + 1][c]; // Store the value at the next down position
        printPathsRec(right, down - 1, idx + 1, total, path, array, r + 1, c, value_path);
    }
}

void printPaths(int n, int m, int array[MAX][MAX]) {
    int totalMoves = n + m;
    char *path = (char *)malloc((totalMoves + 1) * sizeof(char));
    int *value_path = (int *)malloc(totalMoves * sizeof(int));
    path[totalMoves] = '\0';
    value_path[0] = array[0][0]; // Start from the top-left corner value
    printPathsRec(m, n, 0, totalMoves, path, array, 0, 0, value_path);
    free(path);
    free(value_path);
}

int main() {
    int n, m;
    printf("Enter the number of rows (n), max 10: ");
    scanf("%d", &n);
    printf("Enter the number of columns (m), max 10: ");
    scanf("%d", &m);
    getchar(); // Consume newline character left in input buffer

    //Check if array size excedds MAX
    if (n > MAX || m > MAX) {
        printf("Error: Number of rows or columns cannot exceed 10.\n");
        return 1;
    }

    // Declare an array
    int array[MAX][MAX] = {0};

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

    // Adjust for zero-based index sizes
    n--;
    m--;


    printPaths(n, m, array);

    return 0;
}
