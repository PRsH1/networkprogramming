#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

void error_handling(char *message);

int main(int argc, char **argv) {
    int sock;
    int buf;
    socklen_t   len;
    int state;

    sock=socket(PF_INET, SOCK_STREAM, 0);

    len = sizeof(buf);
    state=getsockopt(sock, IPPROTO_IP, IP_TOS, &buf, &len);
    if(state) error_handling("TOS error!");
    printf("TOS value : %d \n", buf);

    state=getsockopt(sock, IPPROTO_IP, IP_TTL, &buf, &len);
    if(state) error_handling("TTL error!");
    printf("TTL value : %d \n", buf);


    state=getsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &buf, &len);
    if(state) error_handling("Multicast TTL error!");
    printf("Multicast TTL value : %d \n", buf);

    state=getsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &buf, &len);
    if(state) error_handling("Multicast Loop error!");
    printf("Multicast Loop value : %d \n", buf);

    state=getsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, &buf, &len);
    if(state) error_handling("Multicast Interface error!");
    printf("Multicast Interface value : %d \n", buf);

    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
