#include <unistd.h>

// Processes = 2 ^ (number of forks)
// 3 forks - 8 pr
// 5 forks - 32 pr

int main() {
    int i;
    for(i = 0; i < 5; i++)
        fork();
    sleep(5);
    return 0;
}
