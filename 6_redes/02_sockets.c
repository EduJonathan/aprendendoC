#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int e_socket = 0;
int conexao  = 0;
struct sockaddr_in destiny;

int main(int argc, char const *argv[])
{
    e_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (e_socket < 0)
    {
        perror("ERROR!");
        exit(1);
    }

    destiny.sin_family      = AF_INET;
    destiny.sin_port        = htons(22);
    destiny.sin_addr.s_addr = inet_addr("10.0.0.20");

    bzero(&(destiny.sin_zero), 8);

    conexao = connect(e_socket, (struct sockaddr *)&destiny, sizeof(destiny));
    if (conexao < 0)
    {
        perror("Porta fechada!");
        pclose(e_socket);
        exit(1);
    }

    printf("A porta 22 DO SSH ESTÁ ABERTA!\n");
    pclose(e_socket);
    return 0;
}
