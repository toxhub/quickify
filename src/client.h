#ifndef QUICKIFY_CLIENT_H_
#define QUICKIFY_CLIENT_H_

#include <uv.h>
#include <openssl/ssl.h>
#include "session.h"

class Client {
  public:
    Client(uv_loop_t *loop, SSL_CTX *ssl_ctx);
    ~Client();

    int aborted;
    int closed;
    int destoryed;
    int pending;

    void close();
    Session* connect();
};


#endif /* QUICKIFY_CLIENT_H_ */
