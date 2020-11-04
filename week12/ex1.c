#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *random = fopen("/dev/random", "r");
  char *buff = calloc(20, sizeof(char));
  int i;
  for (i = 0; i < 20; i++)
    buff[i] = fgetc(random);
  fclose(random);

  printf("%s\n", buff);

  FILE *result = fopen("ex1.txt", "w");
  fprintf(result, buff);
  fclose(result);
  return 0;
}
