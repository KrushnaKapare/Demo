#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 2809

int main(int argc, char *argv[])
{
    int cli_fd, ret, num1, num2, result;
    struct sockaddr_in serv_addr;
    char msg[512];
    // input two numbers on command line
    if (argc != 3)
    {
        printf("Error: syntax: %s <num1> <num2>\n", argv[0]);
        return 1;
    }
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    // create a new socket
    cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    // connect to server socket
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_IP);
    serv_addr.sin_port = htons(SERV_PORT);
    ret = connect(cli_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // send numbers to server
    write(cli_fd, &num1, sizeof(int));
    write(cli_fd, &num2, sizeof(int));
    // accept result from server
    read(cli_fd, &result, sizeof(int));
    // display that result to user
    printf("%d\n", result);

    // close client
    close(cli_fd);
    return 0;
}
