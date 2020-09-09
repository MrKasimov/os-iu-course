#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    char str[1000];

    while (str != "end") {
        fgets(str, 1000, stdin);
        if (fork() == 0) {
            system(str);
            exit(0);
        }
    }
}