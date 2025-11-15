#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, k;
    char states[10][3];
    char from[20][3], to[20][3], input[20][3];
    int transitions;

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the states:\n");
    for (i = 0; i < n; i++)
        scanf("%s", states[i]);

    printf("Enter the number of transitions: ");
    scanf("%d", &transitions);

    printf("Enter transitions in the form <from input to>\n");
    for (i = 0; i < transitions; i++)
        scanf("%s %s %s", from[i], input[i], to[i]);

    // For each state, find its epsilon closure
    for (i = 0; i < n; i++) {
        char closure[10][3];
        int count = 0;

        strcpy(closure[count++], states[i]); // Every state reaches itself

        // Check transitions
        for (j = 0; j < transitions; j++) {
            if (strcmp(from[j], states[i]) == 0 && strcmp(input[j], "e") == 0) {
                strcpy(closure[count++], to[j]);

                // Also check one more epsilon step (2-level depth)
                for (k = 0; k < transitions; k++) {
                    if (strcmp(from[k], to[j]) == 0 && strcmp(input[k], "e") == 0) {
                        strcpy(closure[count++], to[k]);
                    }
                }
            }
        }

        // Print closure
        printf("\nEpsilon closure of %s = { ", states[i]);
        for (j = 0; j < count; j++)
            printf("%s ", closure[j]);
        printf("}\n");
    }

    return 0;
}