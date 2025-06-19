#include <stdio.h>
#include <signal.h>

/*
 * <signal.h>: fornece meios para tratar condições excepcionais que surgem
 * durante a execução, como um sinal de interrupção de uma fonte externa ou um erro
 * na execução.
 */

int main(int argc, char **argv)
{
    // raise: A função raise envia um sinal para o processo atual.
    // Neste caso, envia o sinal SIGINT para si mesmo.
    printf("Enviando sinal SIGINT para si mesmo...\n");
    raise(SIGINT);
    printf("Sinal SIGINT enviado.\n");

    // signal: A função signal é usada para definir um manipulador de sinal.
    // Ela permite que o programa especifique uma função a ser chamada quando um sinal
    // específico é recebido. Neste exemplo, estamos definindo um manipulador para o sinal
    // SIGINT (Ctrl+C).
    
    // Exemplo de uso da função signal para tratar o sinal SIGINT (Ctrl+C)
    signal(SIGINT, SIG_IGN); // Ignora o sinal de interrupção (Ctrl+C)
    printf("Pressione Ctrl+C para testar o tratamento de sinal...\n");

    // Loop infinito para se manter o programa em execução
    while (1)
    {
        // Simula trabalho do programa
    }
    // Se o sinal SIGINT for recebido, o programa será encerrado sem interrupção
    // porque o sinal foi ignorado.

    return 0;
}
