#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[20][20], fiSet[20], foSet[20];
int n, findex;

void findFirst(char c);
void findFollow(char c);

int main() {
    int i, cont;
    char s;

    printf("Enter number of productions:\t");
    scanf("%d", &n);

    printf("Productions (E=TR form):\n");
    for (i = 0; i < n; i++) scanf("%s", prod[i]);

    do {
        printf("Symbol:\t");
        scanf(" %c", &s);
        findex = 0;
        findFirst(s);
        printf("First(%c) = { ", s);
        for (i = 0; i < findex; i++) {
            printf("%c ", fiSet[i]);
        }
        printf("}\n");
        findex = 0;
        findFollow(s);
        printf("Follow(%c) = { ", s);
        for (i = 0; i < findex; i++) {
            printf("%c ", foSet[i]);
        }
        printf("}\n");
        printf("Continue? [1/0]:\t");
        scanf("%d", &cont);
    } while (cont == 1);

    return 0;
}

void findFirst(char c) {
    for (int i = 0; i < n; i++) {
        if (prod[i][0] == c) {
            char next = prod[i][2];
            if (!isupper(next)) {
                fiSet[findex++] = next;
            } else {
                findFirst(next);
            }
        }
    }
}

void findFollow(char c) {
    if (prod[0][0] == c) {
        foSet[findex++] = '$';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(prod[i]); j++) {
            if (prod[i][j] == c) {
                if (prod[i][j + 1] != '\0') {
                    char next = prod[i][j + 1];
                    if (!isupper(next)) {
                        foSet[findex++] = next;
                    } else {
                        findFirst(next);
                    }
                } else if (prod[i][0] != c) findFollow(prod[i][0]);
            }
        }
    }
}

