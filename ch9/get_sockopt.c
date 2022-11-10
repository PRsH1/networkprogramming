#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char **argv) {
    int sock;
    int buf;
    socklen_t   len;
    int state;

    sock=socket(PF_INET, SOCK_STREAM, 0);

    len = sizeof(buf);
    state=getsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &buf, &len);
    if(state) error_handling("keepalive error!");

    printf("keepalive value : %d \n", buf);

    state=getsockopt(sock, SOL_SOCKET, SO_BROADCAST, &buf, &len);
    if(state) error_handling("Broadcast error!");
    printf("Broadcast value : %d \n", buf);


    state=getsockopt(sock, SOL_SOCKET, SO_DONTROUTE, &buf, &len);
    if(state) error_handling("Don't Route error!");
    printf("dontroute value : %d \n", buf);

    state=getsockopt(sock, SOL_SOCKET, SO_OOBINLINE, &buf, &len);
    if(state) error_handling("oobinline error!");
    printf("oobline value : %d \n", buf);

    state=getsockopt(sock, SOL_SOCKET, SO_ERROR, &buf, &len);
    if(state) error_handling("ERROR error!");
    printf("ERROR value : %d \n", buf);

    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
