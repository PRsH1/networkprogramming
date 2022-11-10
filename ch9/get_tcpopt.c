#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

void error_handling(char *message);

int main(int argc, char **argv) {
    int sock;
    int buf;
    socklen_t   len;
    int state;

    sock=socket(PF_INET, SOCK_STREAM, 0);

    len = sizeof(buf);
    state=getsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, &buf, &len);
    if(state) error_handling("TCP keepidle error!");
    printf("TCP Keepidle value : %d \n", buf);

    state=getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &buf, &len);
    if(state) error_handling("TCP No Delay error!");
    printf("TCP No Delay value : %d \n", buf);

    state=getsockopt(sock, IPPROTO_TCP, TCP_MAXSEG, &buf, &len);
    if(state) error_handling("TCP Max Segment error!");
    printf("TCP Max Segment value : %d \n", buf);

    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
