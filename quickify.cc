#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

static void recv(uv_timer_t* req) {
  fprintf(stdout, "recv message\n");
}

int main(int argc, char* argv[]) {
  const char* host = argv[1];
  const char* port = argv[2];

  uv_loop_t* loop = uv_default_loop();

  uv_timer_t g_tick;

  uv_timer_init(loop, &g_tick);
  uv_timer_start(&g_tick, recv, 1, 2000);

  return uv_run(loop, UV_RUN_DEFAULT);
}
