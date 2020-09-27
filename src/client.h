#ifndef QUICKIFY_CLIENT_H_
#define QUICKIFY_CLIENT_H_

#include <uv.h>

namespace quickify {
class Client {
 public:
  Client(uv_loop_t *loop);
  ~Client();
  int run();

 private:
  uv_loop_t *loop_;
  uv_udp_t *handle_;
};

}  // namespace quickify

#endif /* QUICKIFY_CLIENT_H_ */
