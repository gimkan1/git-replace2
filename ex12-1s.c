#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SIZE    sizeof(struct sockaddr_in)

// 작업1 4307175
// 작업2 2227148
// 작업3 4607711
// 작업4 8f8664a
// 작업5

int main()
{
    int sockfd_listen;
    int sockfd_connect;

    char c;

    struct sockaddr_in server = {AF_INET, 5000, INADDR_ANY};

    printf("socket()\n");
    sockfd_listen = socket(AF_INET, SOCK_STREAM, 0);

    printf("bind()\n");
    bind(sockfd_listen, (struct sockaddr *)&server, SIZE);

    printf("listen()\n");
    listen(sockfd_listen, 5);

    printf("wating for client\n");
    sockfd_connect = accept(sockfd_listen, NULL, NULL);
    printf("accepted\n");

    recv(sockfd_connect, &c, 1, 0);
    printf("recv %c from client\n", c);

    c++;
    printf("send %d to client\n", c);
    send(sockfd_connect, &c , 1, 0);

    printf("close()\n");
    close(sockfd_connect);
    close(sockfd_listen);

    return 0;
}