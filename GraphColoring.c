#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

void randomize_colors(int vertices, int k) {
    for (int i = 0; i < vertices; i++) {
        colors[i] = rand() % k;
    }
}

int can_color(int v, int c, int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

int color_graph(int vertices, int k) {
    randomize_colors(vertices, k);
    int colors_used = k;

    for (int i = 0; i < vertices; i++) {
        for (int c = 0; c < k; c++) {
            if (can_color(i, c, vertices)) {
                colors[i] = c;
                break;
            }
        }
        if (colors[i] == k) {
            randomize_colors(vertices, k);
            i = -1;
            colors_used = k;
        }
        if (colors_used < colors[i] + 1) {
            colors_used = colors[i] + 1;
        }
    }

    return colors_used;
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int k;
    printf("Enter the number of colors: ");
    scanf("%d", &k);

    int num_colors = color_graph(vertices, k);
    printf("Number of colors used: %d\n", num_colors);

    return 0;
}
