#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 2809

int serv_fd; // global var

void sigint_handler(int sig)
{
    // close main socket
    shutdown(serv_fd, SHUT_RDWR);
    // terminate the appln
    _exit(0);
}

int main()
{
    int cli_fd, ret, num1, num2, result;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clisock_len = sizeof(cli_addr);
    char msg[512];
    // register signal handler
    signal(SIGINT, sigint_handler);
    // create main socket
    serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    // bind socket address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_IP);
    serv_addr.sin_port = htons(SERV_PORT);
    ret = bind(serv_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    // listen main socket
    listen(serv_fd, 5);
    while (1)
    {
        // accept client connection
        memset(&cli_addr, 0, sizeof(cli_addr));
        cli_fd = accept(serv_fd, (struct sockaddr *)&cli_addr, &clisock_len);
        // accept string from client
        read(cli_fd, &num1, sizeof(int));
        read(cli_fd, &num2, sizeof(int));
        printf("from client: %d + %d\n", num1, num2);
        // calculate the result
        result = num1 + num2;
        // send result to client
        write(cli_fd, &result, sizeof(int));
        // close comm socket
        close(cli_fd);
    } // repeat for next client
    return 0;
}
