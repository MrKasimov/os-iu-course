#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define FILE_READ "ex1.txt"
#define FILE_WRITE "ex1.memcpy.txt"

int main() {
  int file_read = open(FILE_READ, O_RDWR);
  int file_write = open(FILE_WRITE, O_RDWR);

  struct stat buf;
  fstat(file_read, &buf);
  int size = buf.st_size;

  ftruncate(file_write, size);
  char * mapping_read = mmap(NULL, size, PROT_READ, MAP_SHARED, file_read, 0);
  char * mapping_write = mmap(NULL, size, PROT_WRITE, MAP_SHARED, file_write, 0);

  memcpy(mapping_write, mapping_read, size);

  close(file_read);
  close(file_write);
  munmap(mapping_read, size);
  munmap(mapping_write, size);
  return 0;
}
