#include <stdio.h>
#include "../header/Server.h"
#include <string.h>
#include <unistd.h>


void launch(struct Server* server) {
    int address_length = sizeof(server->address);
    char *hello = "HTTP/1.1 202 OK\nDate: Mon, 27 Jul 2020 12:28:53 GMT\nServer: Apache/2.2.14 (Win32)\nLast-Modified: Wed, 22 Jul 2009 19:15:56 GMT\nContent-type: text/html\nConnection: Closed \n\n<html><body><h2>Hello World!</h2></body></html>\n";
    int newSocket;
    while (1) {
        printf("=====WAITING=====\n");
        newSocket = accept(server->socket, (struct sockaddr*)&server->address,
                               (socklen_t*)&address_length);
        printf("===Connected and Sent===\n");
        write(newSocket, hello, strlen(hello));
        close(newSocket);
    }
}

int main(int argc, char** argv) {
    struct Server server = serverInit(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    server.launch(&server);
}