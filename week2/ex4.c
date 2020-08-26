#include <stdio.h>

void swap_func(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    printf("Input two integers for swap: ");
    int first, second;
    scanf("%d %d", &first, &second);

    swap_func(&first, &second);
    printf("Get your integers back: %d %d", first, second);
    return 0;
}
