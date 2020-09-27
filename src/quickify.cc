#include <stdio.h>
#include <stdlib.h>

#include <uv.h>
#include "client.h"

#include "nghttp3/nghttp3.h"
#include "nghttp3/version.h"

#include <iostream>

using namespace quickify;

namespace quickify {

}  // namespace quickify

int main(int argc, char* argv[]) {
  auto addr = argv[1];
  auto port = argv[2];

  printf("nghttp3 version: %s\n", NGHTTP3_VERSION);

  uv_loop_t* loop = uv_default_loop();

  Client client(loop);

  if (client.run() != 0) {
    fprintf(stderr, "client run failed\n");
    exit(-1);
  }

  return uv_run(loop, UV_RUN_DEFAULT);
}
