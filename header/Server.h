
#ifndef WEBDEV_SERVER_H
#define WEBDEV_SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>

struct Server {
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;

    int backlog;
    struct sockaddr_in address;

    int socket;
    void (*launch)(struct Server* server);
};

struct Server serverInit(int domain, int service, int protocol,
                         u_long interface, int port,
                         int backlog, void (*launch)(struct Server* server));
#endif //WEBDEV_SERVER_H
