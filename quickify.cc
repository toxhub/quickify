#include <stdio.h>
#include <stdlib.h>
#include "quiche.h"

int main(int argc, char* argv[]) {
  printf("Hello Quickify! \n");
  printf("This is Quiche Version: %d \n", QUICHE_PROTOCOL_VERSION);
  return 0;
}
