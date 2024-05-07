#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printPaths(int n, int m, int array[MAX][MAX], int r, int c, int right, int down, int idx, int total, int *path, int *pathValue, int count) {
    if (right == 0 && down == 0) { // Base case: reached destination
        int checker = 1;

        printf("Path - Values: ");
        for (int i = 0; i < total; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");

        for (int i = 0; i < total; i++) {
            if (pathValue[i] == 1) {
                if (path[i] != path[i+1]) {
                    printf("Error: Invalid path.\n");
                    checker = 0;
                    break;
                
                }
            }
        }

        if (checker == 1) {
            count++;
        }

        return;
    }

    if (right > 0) {
        path[idx] = 1; // Move right
        pathValue[idx] = array[r][c + 1]; // Store the value at the next right position
        printPaths(n, m, array, r, c + 1, right - 1, down, idx + 1, total, path, pathValue, count);
    }

    if (down > 0) {
        path[idx] = 0; // Move down
        pathValue[idx] = array[r + 1][c]; // Store the value at the next down position
        printPaths(n, m, array, r + 1, c, right, down - 1, idx + 1, total, path, pathValue, count);
    }
}

int main() {
    int n, m;
    printf("Enter the number of Rows & Columns, (Max %d): ", MAX);
    scanf("%d %d", &n, &m);

    if (n > MAX || m > MAX) {
        printf("Error: Max exceeded.\n");
        return 1;
    }

    int array[MAX][MAX]; // Declare and input the array
    int path[2 * MAX];   // Statically allocated array for path
    int pathValue[2 * MAX]; // Statically allocated array for pathValue

    printf("Enter the Grid values (0 or 1 only):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    /*printf("The entered array is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }*/

    int count = 0;

    int totalMoves = n + m - 2; // Calculating the number of movements required
    printPaths(n-1, m-1, array, 0, 0, m-1, n-1, 0, totalMoves, path, pathValue, count);

    printf("Total number of valid paths: %d\n", count);

    return 0;
}
