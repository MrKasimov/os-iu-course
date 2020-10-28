#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define FILE "ex1.txt"
#define INPUT "This is a nice day\n"

int main() {
  int file = open(FILE, O_RDWR);
  int size = strlen(INPUT);

  ftruncate(file, size);
  char * mapping = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);

  memcpy(mapping, INPUT, size);
  return 0;
}
