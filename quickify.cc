#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#include <fcntl.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>

#include <quiche.h>
#include <uv.h>

#define LOCAL_CONN_ID_LEN 16

#define MAX_DATAGRAM_SIZE 1350

struct conn_io {
    uv_timer_t *timer;

    const char *host;

    int sock;

    quiche_conn *conn;

    quiche_h3_conn *http3;
};

static void debug_log(const char* line, void* argp) {
  fprintf(stderr, "%s\n", line);
}

static void recv(uv_timer_t* req) {
  fprintf(stdout, "recv message\n");
}

int main(int argc, char* argv[]) {
  const char* host = argv[1];
  const char* port = argv[2];

  const struct addrinfo hints = {.ai_family = PF_UNSPEC,
                                 .ai_socktype = SOCK_DGRAM,
                                 .ai_protocol = IPPROTO_UDP};

  // quiche_enable_debug_logging(debug_log, NULL);
  struct addrinfo* peer;
  if (getaddrinfo(host, port, &hints, &peer) != 0) {
    perror("failed to resolve host");
    return -1;
  }

  int sock = socket(peer->ai_family, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("failed to create socket");
    return -1;
  }

  if (fcntl(sock, F_SETFL, O_NONBLOCK) != 0) {
    perror("failed to make socket non-blocking");
    return -1;
  }

  if (connect(sock, peer->ai_addr, peer->ai_addrlen) < 0) {
    perror("failed to connect socket");
    return -1;
  }

  quiche_config* config = quiche_config_new(0xbabababa);
  if (config == NULL) {
    fprintf(stderr, "failed to create config\n");
    return -1;
  }

  quiche_config_set_application_protos(
      config,
      (uint8_t*)QUICHE_H3_APPLICATION_PROTOCOL,
      sizeof(QUICHE_H3_APPLICATION_PROTOCOL) - 1);

  quiche_config_set_max_idle_timeout(config, 5000);
  quiche_config_set_max_udp_payload_size(config, MAX_DATAGRAM_SIZE);
  quiche_config_set_initial_max_data(config, 10000000);
  quiche_config_set_initial_max_stream_data_bidi_local(config, 1000000);
  quiche_config_set_initial_max_stream_data_bidi_remote(config, 1000000);
  quiche_config_set_initial_max_stream_data_uni(config, 1000000);
  quiche_config_set_initial_max_streams_bidi(config, 100);
  quiche_config_set_initial_max_streams_uni(config, 100);
  quiche_config_set_disable_active_migration(config, true);

  if (getenv("SSLKEYLOGFILE")) {
    quiche_config_log_keys(config);
  }

  // ABC: old config creation here

  uint8_t scid[LOCAL_CONN_ID_LEN];
  int rng = open("/dev/urandom", O_RDONLY);
  if (rng < 0) {
    perror("failed to open /dev/urandom");
    return -1;
  }

  ssize_t rand_len = read(rng, &scid, sizeof(scid));
  if (rand_len < 0) {
    perror("failed to create connection ID");
    return -1;
  }

  quiche_conn* conn =
      quiche_connect(host, (const uint8_t*)scid, sizeof(scid), config);
  if (conn == NULL) {
    fprintf(stderr, "failed to create connection\n");
    return -1;
  }

  struct conn_io* conn_io = (struct conn_io*) malloc(sizeof(struct conn_io));
  if (conn_io == NULL) {
    fprintf(stderr, "failed to allocate connection IO\n");
    return -1;
  }

  conn_io->sock = sock;
  conn_io->conn = conn;
  conn_io->host = host;

  uv_loop_t* loop = uv_default_loop();

  uv_timer_t g_tick;

  uv_timer_init(loop, &g_tick);
  uv_timer_start(&g_tick, recv, 200, 200);

  return uv_run(loop, UV_RUN_DEFAULT);
}
