#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#define PORT 8070

int main()
{
    int server_fd;
    int new_socket;
    int valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response1 = "transaksi gagal\n";
    char *response2 = "transaksi berhasil\n";
    key_t key = 1234;
    int *value;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);
    *value = 2;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    };

    if (listen(server_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for(;;)
    {
        new_socket = accept(server_fd, (struct  sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
             perror("accept");
             exit(EXIT_FAILURE);
        }
        valread = read( new_socket, buffer, 1024);
        printf("%s", buffer);
        if(*value == 0)
            send(new_socket, response1, strlen(response1), 0);
        else {
            send(new_socket, response2, strlen(response2), 0);
            *value = *value - 1;
        }
    }

    return 0;
}