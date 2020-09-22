#ifndef QUICKIFY_SESSION_H_
#define QUICKIFY_SESSION_H_

class Session {
  public:
    Session();
    ~Session();

    int closed;
    int connecting;
    int destoryed;

    int abort();
    int request();
    int end();
};

#endif /* QUICKIFY_SESSION_H_ */
