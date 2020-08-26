#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];

    printf("Please input a string for reversal: ");
    scanf("%s", &input);

    char output[strlen(input) + 1];
    int i;

    // reverse
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[strlen(input) - 1 - i];
    }

    // add null termination
    output[strlen(input)] = '\0';

    printf("Reversed string: %s\n", output);
    return 0;
}
