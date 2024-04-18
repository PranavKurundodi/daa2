#include<stdio.h>
#include<string.h>

void naiveStringMatching(char t[],char p[]){
    int n=strlen(t);
    int m=strlen(p);

    int i,j;
    for(i=0;i<(n-m);i++){
        for(j=0;j<m;j++){
            if(t[j+i]!=p[j]){
                break;
            }
        }
        if(j==m){
            printf("Pattern found at %d",i);
            break;
        }
    }
}

int main() {
    char text[100];
    char pattern[50]; 

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; 

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    naiveStringMatching(text, pattern);

    return 0;
}