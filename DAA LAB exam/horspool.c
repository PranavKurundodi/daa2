#include <stdio.h>
#include <string.h>

#define MAX 500

// Function to preprocess the pattern and calculate the shift table
void shiftTable(char pattern[], int m, int shift[]) {
    int i;
    for (i = 0; i < MAX; i++)
        shift[i] = m;
    for (i = 0; i < m - 1; i++)
        shift[pattern[i]] = m - 1 - i;
}

// Function to perform string matching using Horspool algorithm
void horspool(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shift[MAX];
    shiftTable(pattern, m, shift);
    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;
        if (k == m) {
            printf("Pattern found at index %d\n", i - m + 1);
            i += shift[text[i]];
        } else {
            i += shift[text[i]];
        }
    }
}

int main() {
    char text[MAX], pattern[MAX];
    printf("Enter the text: ");
    fgets(text, MAX, stdin);
    printf("Enter the pattern to search for: ");
    fgets(pattern, MAX, stdin);

    // Remove newline characters from input
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    horspool(text, pattern);
    return 0;
}
