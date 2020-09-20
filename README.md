# QuickIFY
C++ based HTTP/3 Client

## Dependencies
- [libuv](https://github.com/libuv/libuv) - Cross-platform asynchronous I/O
- [nghttp3](https://github.com/ngtcp2/nghttp3) - HTTP/3 library written in C
- [ngtcp2](https://github.com/ngtcp2/ngtcp2) - implement IETF QUIC protocol

## Build

### Fetch source code

```sh
$ git clone git@github.com:toxhub/quickify.git
$ cd quickify
```

### Build QuickIFY

```sh
$ ./configure
$ make
```

### Run

```sh
./quickify
```
