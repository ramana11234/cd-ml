#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    char s[50];
    printf("enter input: ");
    gets(s);

    int flag = 0;
    if (isalpha(s[0]) || s[0] == '_') {
        for (int i = 0; i < strlen(s); i++) {
            if (isdigit(s[i]) || isalpha(s[i]) || s[i] == '_') {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1) {
        printf("valid\n");
    } else {
        printf("invalid\n");
    }
}
