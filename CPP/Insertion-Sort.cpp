#include <stdio.h>

int main() {
    int A[5];
    int j, key, i, m;

    //Insert values to the array
    for (m=0; m<5; m++) {
        printf("Enter element %d: ", m+1);
        scanf("%d", &A[m]);
    }

    //Insertion Sort
    for (j=1; j<5; j++) {
        key = A[j];
        i = j-1;
        while (i>=0 && A[i]>key) {
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
    printf("Sorted Array: ");
    //Print the sorted array
    for (m=0; m<5; m++) {
        printf("%d ", A[m]);
    }

    return 0;
}