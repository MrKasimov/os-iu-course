#include <stdio.h>
#include <string.h>

void *my_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    } else if (size == 0) {
        free(ptr);
        return NULL;
    }

    void* new_ptr = malloc(size);
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

int main() {
    // Usage example
    int n = 3, new_n = 5;
    int* arr = malloc(n * sizeof(int));
    arr = my_realloc(arr, new_n * sizeof(int));
    return 0;
}

