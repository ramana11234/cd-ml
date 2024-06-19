#include <stdio.h>
#include <string.h>

void main() {
    char s[50];
    printf("enter input: ");
    gets(s);

    if (s[0] == '/') {
        if (s[1] == '/') {
            printf("given statement is a comment");
        } else if (s[1] == '*') {
            int n = strlen(s) - 1;
            if (s[n] == '/' && s[n - 1] == '*') {
                printf("given statement is a comment");
            } else {
                printf("given statement is not a comment");
            }
        } else {
            printf("given statement is not a comment");
        }
    } else {
        printf("given statement is not a comment");
    }
}
