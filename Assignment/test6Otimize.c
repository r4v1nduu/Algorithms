#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void printPaths(int n, int m, int array[MAX][MAX], int cRow, int cCoulmn, int right, int down, int idx, int *path, int *pathValue, int *count) {
    if (right == 0 && down == 0) {
        //Total number of moves is (n+m-2)
        for (int i = 0; i < n+m-3; i++) {
            if (pathValue[i] == 1 && path[i] != path[i + 1]) {
                return;
            }
        }
        (*count)++;
        return;
    }

    if (right > 0) {
        path[idx] = 1;
        pathValue[idx] = array[cRow][cCoulmn + 1];
        printPaths(n, m, array, cRow, cCoulmn + 1, right - 1, down, idx + 1, path, pathValue, count);
    }

    if (down > 0) {
        path[idx] = 0;
        pathValue[idx] = array[cRow + 1][cCoulmn];
        printPaths(n, m, array, cRow + 1, cCoulmn, right, down - 1, idx + 1, path, pathValue, count);
    }
}

int main() {
    int n, m, count=0;
    printf("Enter the number of Rows & Columns, (Max %d): ", MAX);
    scanf("%d %d", &n, &m);

    if (n > MAX || m > MAX) {
        printf("Error: Max exceeded.\n");
        return 1;
    }

    int array[MAX][MAX];
    int path[2*MAX], pathValue[2*MAX];

    printf("Enter the Grid values (0/1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printPaths(n, m, array, 0, 0, m-1, n-1, 0, path, pathValue, &count);

    printf("Number of valid paths: %d\n", count);

    return 0;
}
