#include <stdio.h>
#include <stdlib.h>

void main() {
    char s[50];
    printf("enter string: ");
    gets(s);

    if (atoi(s)) {
        printf("given string is constant\n");
    } else {
        printf("given string is not constant\n");
    }
}
