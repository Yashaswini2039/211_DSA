#include <stdio.h>
#include <limits.h>

#define N 4

int graph[N][N] = { {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0} };
                  
int best_cost = INT_MAX;

void copy(int *dst, int *src, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void tsp(int cost, int path[], int level) {
    if (level == N) {
        if (cost + graph[path[level - 1]][0] < best_cost) {
            best_cost = cost + graph[path[level - 1]][0];
        }
    } else {
        for (int i = level; i < N; i++) {
            swap(&path[level], &path[i]);
            int bound = cost + graph[path[level - 1]][path[level]];
            if (bound < best_cost) {
                tsp(bound, path, level + 1);
            }
            swap(&path[level], &path[i]);
        }
    }
}

int main() {
    int path[N] = {0, 1, 2, 3};
    tsp(0, path, 1);
    printf("Best cost: %d\n", best_cost);
    return 0;
}
