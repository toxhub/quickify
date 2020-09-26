#include <stdio.h>
#include <stdlib.h>

#include <uv.h>
#include "client.h"

#include "nghttp3/nghttp3.h"
#include "nghttp3/version.h"

static void recv(uv_timer_t* req) {
  fprintf(stdout, "recv message\n");
}

int main(int argc, char* argv[]) {
  auto addr = argv[1];
  auto port = argv[2];

  printf("nghttp3 version: %s\n", NGHTTP3_VERSION);

  uv_loop_t* loop = uv_default_loop();

  Client c(loop);

  if (c.run(addr, port) != 0) {
    exit(-1);
  }

  return EXIT_SUCCESS;
}
