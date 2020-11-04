#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main(int argc, char *argv[]) {
  bool append = false;
  while (true) {
    int opt = getopt(argc, argv, "a");

    if (opt == -1)
      break;

    if (opt == 'a')
      append = true;
  }

  int len = argc - append - 1;
  FILE ** output = malloc(sizeof(FILE *) * len);

  int i = 1;
  for (; i < argc; i++) {
    if (strcmp(argv[i], "-a") == 0)
      continue;

    output[i - 1] = fopen(argv[i], append ? "a" : "w");
  }

  char buff[BUFFER_SIZE];

  while (fgets(buff, BUFFER_SIZE, stdin)) {
    printf("%s", buff);

    for (i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-a") == 0)
        continue;

      fprintf(output[i-1], buff);
    }
  }

  return 0;
}
