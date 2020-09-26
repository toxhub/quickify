#include "client.h"
#include <uv.h>

Client::Client(uv_loop_t *loop): loop_(loop) {}

Client::~Client() {}

void Client::close() {}

int Client::run(const char *addr, const char *port) {}
