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

#if defined(_WIN32)
    executaComando("color a"); // Verde no Windows
    executaComando("cls");
#endif

#if defined(__linux__)
    executaComando("clear");
    executaComando("echo -e \"\\033[0;32m\""); // Verde no Linux
#endif

#if defined(__linux__) || defined(_WIN32)
    executaComando("echo Hello, World!");
#endif

    // "Congela" o terminal até clicar em qualquer outra tecla para sair(Não utilize nem no Windows PowerShell nem no Linux)
    // executaComando("pause");

    return 0;
}
