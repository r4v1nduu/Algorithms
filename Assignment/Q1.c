#include <stdio.h>

int calculate_max_consecutive_days(int workload[], int n) {
    int max_streak = 0;
    int current_streak = 0;
    
    for (int i = 0; i < n; i++) {
        if (workload[i] > 6) {
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 0;
        }
    }
    
    // Final check to ensure the last streak is counted
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }
    
    return max_streak;
}

int main() {
    int n;
    printf("Enter the number of working days: ");
    scanf("%d", &n);
    
    int workload[n];
    printf("Enter the workloads for each day: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &workload[i]);
    }
    
    int rating = calculate_max_consecutive_days(workload, n);
    printf("Employee rating: %d\n", rating);
    
    return 0;
}
