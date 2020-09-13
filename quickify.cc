#include <stdio.h>
#include <stdlib.h>
#include <quiche.h>
#include <uv.h>

int main(int argc, char* argv[]) {
  printf("Hello Quickify! \n");
  printf("This is Quiche Version: %d \n", QUICHE_PROTOCOL_VERSION);
  return 0;
}

static void debug_log(const char *line, void *argp) {
    fprintf(stderr, "%s\n", line);
}
