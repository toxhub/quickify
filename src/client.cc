#include "client.h"
#include <stdio.h>
#include <stdlib.h>

namespace quickify {

Client::Client(uv_loop_t *loop): loop_(loop) {
  printf("Client init\n");
  uv_udp_init(loop_, handle_);
}

Client::~Client() {
  printf("Client destory\n");
}

int Client::run() {
  return 0;
};

}  // namespace quickify
