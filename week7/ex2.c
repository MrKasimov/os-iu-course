#include <stdio.h>

int main() {
    int N, i;

    printf("Input array size: ");
    scanf("%d", &N);

    int* arr = malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        arr[i] = i;

    printf("Memory is allocated and filled: ");
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\nMemory is released");
    free(arr);
    return 0;
}
