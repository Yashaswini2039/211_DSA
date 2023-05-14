#include <stdio.h>

int is_subset_sum(int set[], int n, int sum) {
    if (sum == 0) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    if (set[n - 1] > sum) {
        return is_subset_sum(set, n - 1, sum);
    }
    return is_subset_sum(set, n - 1, sum) || is_subset_sum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (is_subset_sum(set, n, sum)) {
        printf("Found a subset with the given sum\n");
    } else {
        printf("No subset with the given sum\n");
    }
    return 0;
}
