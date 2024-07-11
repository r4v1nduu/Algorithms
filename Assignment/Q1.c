#include <stdio.h>

int calcDays(int workload[], int n) {
    int mStreak=0, cStreak=0;
    
    for (int i = 0; i < n; i++) {
        if (workload[i] > 6) {
            cStreak++;
        } else {
            if (cStreak > mStreak) {
                mStreak = cStreak;
            }
            cStreak = 0;
        }
    }
    
    // Final check to ensure the last streak is counted
    if (cStreak > mStreak) {
        mStreak = cStreak;
    }
    
    return mStreak;
}

int main() {
    int n;
    printf("Enter number of working days: ");
    scanf("%d", &n);
    
    int workload[n];
    printf("Enter workloads for each day: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &workload[i]);
    }
    
    int rating = calcDays(workload, n);
    printf("Employee rating: %d\n", rating);
    
    return 0;
}
