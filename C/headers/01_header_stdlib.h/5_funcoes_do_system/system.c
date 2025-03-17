#include <stdio.h>
#include <stdlib.h>

/**
 * system: A função system executa linhas de comandos do terminal do sistema operacional.
 * Elas podem ser usadas para executar comandos do sistema operacional, como
 * executar programas, navegar diretorios, etc.
 *
 * SINTAXE: int system(const char *command);
 *
 * @param command Ponteiro para a string contendo o comando a ser executado.
 * @return O status de saída do comando executado.
 */

/**
 * @brief Executa um comando do sistema.
 *
 * Esta função utiliza a função `system` para executar um comando
 * fornecido como uma string.
 *
 * @param string Ponteiro para a string contendo o comando a ser executado.
 */
void executaComando(const char *string) { system(string); }

int main(int argc, char **argv)
{
    // Muda a cor do terminal(cmd) do windows
    executaComando("color a");

    // Limpa a tela do console
    // executaComando("clear"); // Para Linux
    // executaComando("cls"); // Para Windows

    // Escreve no terminal "echo Hello, World!"
    executaComando("echo Hello, World!");

    // "Congela" o terminal até clicar em qualquer outra tecla para sair
    executaComando("pause");

    return 0;
}
