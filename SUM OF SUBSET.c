#include <stdio.h>

int count = 0;

int subset_sum(int set[], int n, int target, int solution[]) {
    count++;
    if (target == 0) {
        return 1;
    }
    if (n == 0 || target < 0) {
        return 0;
    }
    if (subset_sum(set, n - 1, target - set[n - 1], solution)) {
        solution[n - 1] = 1;
        return 1;
    }
    if (subset_sum(set, n - 1, target, solution)) {
        solution[n - 1] = 0;
        return 1;
    }
    return 0;
}

int main() {
    int n, target;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    int solution[n];
    int result = subset_sum(set, n, target, solution);
    printf("Subset with sum %d %s found.\n", target, result ? "was" : "was not");
    printf("Total number of calls to the Subset Sum procedure: %d\n", count);
    printf("Solution array in binary: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", solution[i]);
    }
    return 0;
}
