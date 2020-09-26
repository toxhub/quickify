#ifndef QUICKIFY_CLIENT_H_
#define QUICKIFY_CLIENT_H_

#include <uv.h>
#include <openssl/ssl.h>
#include "session.h"

class Client {
  public:
    Client(uv_loop_t *loop);
    ~Client();

    int aborted;
    int closed;
    int destoryed;
    int pending;

    void close();
    int run(const char *addr, const char *port);
    Session* connect();

  private:
    uv_loop_t *loop_;
};


#endif /* QUICKIFY_CLIENT_H_ */
