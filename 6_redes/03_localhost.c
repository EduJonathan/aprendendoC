#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT        8800
#define BUFFER_SIZE 4096

int main(int argc, char const **argv)
{
    int server_fd = 0, client_fd = 0;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Criar socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Falha ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Configurar endereço
    address.sin_family      = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port        = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Falha no bind");
        exit(EXIT_FAILURE);
    }

    // Escutar por conexões
    if (listen(server_fd, 3) < 0)
    {
        perror("Falha ao escutar");
        exit(EXIT_FAILURE);
    }

    printf("Servidor rodando em http://localhost:%d\n", PORT);

    while (1)
    {
        // Aceitar conexão
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("Falha ao aceitar conexão");
            continue;
        }

        // Ler requisição HTTP
        read(client_fd, buffer, BUFFER_SIZE);
        printf("Requisição recebida\n");

        // Resposta HTTP
        char *response = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/html; charset=utf-8\r\n"
                         "Connection: close\r\n"
                         "\r\n"
                         "<!DOCTYPE html>\r\n"
                         "<html>\r\n"
                         "<head>\r\n"
                         "    <title>Hello World em C</title>\r\n"
                         "</head>\r\n"
                         "<body>\r\n"
                         "    <h1>Hello World!</h1>\r\n"
                         "    <p>Servidor rodando em C na porta 8800</p>\r\n"
                         "</body>\r\n"
                         "</html>\r\n";

        send(client_fd, response, strlen(response), 0);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
