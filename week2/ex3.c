#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wrong number of command line parameters!");
        return 0;
    }

    int n, i, j;
    sscanf(argv[1], "%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++)
            printf(" ");

        for (j = 0; j < 2*i + 1; j++)
            printf("*");

        for (j = 0; j < n - 1 - i; j++)
            printf(" ");

        if (i != n - 1)
            printf("\n");
    }
    return 0;
}
