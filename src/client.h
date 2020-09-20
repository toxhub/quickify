#ifndef QUICKIFY_CLIENT_H_
#define QUICKIFY_CLIENT_H_

#include <uv.h>
#include <openssl/ssl.h>

class Client {
  public:
    Client(uv_loop_t *loop, SSL_CTX *ssl_ctx);
    ~Client();

    void close();
};


#endif /* QUICKIFY_CLIENT_H_ */
