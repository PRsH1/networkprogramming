#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

#define TRUE  1
#define FALSE 0

void error_handling(char *message);

int main(int argc, char **argv) {
    int sock;
    int state, opt_val, opt_len;

    sock=socket(PF_INET, SOCK_STREAM, 0);

    state=getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &opt_val, &opt_len);
    if(state) error_handling("getsockopt() error!");
    printf("����Ʈ nagle �˰��� : %s \n", opt_val ? "����":"����");

    opt_val = TRUE;
    state=setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &opt_val, sizeof(opt_val));
    if(state) error_handling("getsockopt() error!");

    getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &opt_val, &opt_len);
    printf("����� nagle �˰��� : %s \n", opt_val ? "����":"����");

    close(sock);
    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
