#include<stdio.h>

void dfs(int s, int n);
void push(int item);
int pop();

int vis[20], stack[20], top = -1;
int a[20][20];

int main() {
    int n, s;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &s);
    dfs(s, n);
    return 0;
}

void dfs(int s, int n) {
    vis[s] = 1;
    printf("%d ", s);
    for(int i = 1; i <= n; i++) {
        if(a[s][i] != 0 && vis[i] == 0) {
            push(i);
            dfs(i, n);
        }
    }
}

void push(int item) {
    if(top == 20 - 1) {
        printf("Stack overflow ");
        return;
    }
   stack[++top] = item;

}
int pop() {
    if(top == -1) {
        return 0;
    }
    int k = stack[top--];
    return k;
}
