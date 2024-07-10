#include <stdio.h>
#include <string.h>

char prod[1][10] = { "S->aA" };
char first[1][10] = { "a" };  
char follow[1][10] = { "$" };
char table[2][3][10];

int numr(char c) {
    switch (c) {
        case 'S':
            return 0;
        case 'A':
            return 1;
        case 'a':
            return 0;
        case '$':
            return 1;
    }
    return -1;
}

int main() {
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            strcpy(table[i][j], " ");
        }
    }

    printf("The following grammar is used for the Parsing Table:\n");
    for (i = 0; i < 1; i++) {
        printf("%s\n", prod[i]);
    }

    for (i = 0; i < 1; i++) {
        for (j = 0; j < strlen(first[i]); j++) {
            if (first[i][j] != '@') {
                strcpy(table[numr('S') + 1][numr(first[i][j]) + 1], prod[i]);
            }
        }
    }

    strcpy(table[0][0], " ");
    strcpy(table[0][1], "a");
    strcpy(table[0][2], "$");
    strcpy(table[1][0], "S");

    printf("\nPredictive parsing table:\n");
    printf("\n.................................\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%-10s", table[i][j]);
            if (j == 2) {
                printf("\n.................................\n");
            }
        }
    }

    return 0;
}
