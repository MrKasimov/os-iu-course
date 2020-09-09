#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 10;

    if (fork() == 0) {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    else {
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    }
    return 0;
}

// Parallel execution of processes causes strings to be shuffled