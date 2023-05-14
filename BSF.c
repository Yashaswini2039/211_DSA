#include <stdio.h>
#include <string.h>

void search(char* text, char* pattern) {
    int m = strlen(text);
    int n = strlen(pattern);
    int i, j;

    for (i = 0; i <= m - n; i++) {
        for (j = 0; j < n; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == n)
            printf("Pattern found at position %d\n", i);
    }
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text string: ");
    scanf("%s", text);

    printf("Enter the pattern string: ");
    scanf("%s", pattern);

    search(text, pattern);
    return 0;
}
