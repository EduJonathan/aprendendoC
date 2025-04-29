#include <stdio.h>
#include <string.h>

/**
 * ASM: É a keyword que escrever instruções em Assembly, a linguagem de baixo nível e
 * a mais próxima da linguagem de máquina, que não necessita de includes, e funções terceira
 * pois com esta linguagem temos o absoluto sobre o hardware e controle de cada clico de clocks
 * otimização totalmente manual de cada loop, e dentre outros, mas é sensível pois por sua
 * produtividade baixa(suas escritas necessitam cuidado e os códigos são verbosos)
 * manuntenção difícil pequenos erros pode levar falhas gravesm dentre outros
 */

/**
 * @brief Função que imprime uma string na saída padrão com uma nova linha ao final,
 * utilizando a chamada de sistema (syscall) diretamente para a escrita.
 *
 * @param str A string a ser impressa.
 *
 * @note Esta função usa uma instrução em **assembly inline** (`asm`) para invocar
 * diretamente a chamada de sistema do Linux para escrita (`sys_write`). Ao invés de usar
 * funções como `printf`, a syscall permite uma escrita mais rápida e eficiente, sem a
 * sobrecarga de bibliotecas. O uso de assembly permite um controle preciso sobre os
 * registradores e a execução do código.
 * syscall (chamada de sistema) é específica do Linux, que não é compatível
 * com o ambiente Windows. Caso não estiver imprimindo em seu terminal este é o problema.
 */
void println(const char *str)
{
    // Calcula o tamanho da string original
    size_t len = strlen(str);

    // Direciona o tamanho da string para +1 ('\n') e +1 '\0'
    char new_str[len + 2]; // Aloca espaço para '\n' e '\0'

    // Copia a string original para new_str
    for (size_t i = 0; i < len; ++i)
    {
        new_str[i] = str[i];
    }

    // Adiciona o caractere de nova linha e o terminador
    new_str[len] = '\n';
    new_str[len + 1] = '\0'; // Certifica-se que a string termina com '\0'

    // Chamada de sistema para escrever a string no stdout (file descriptor 1)
    asm volatile(
        "movq $1, %%rax;" // Número da syscall (1 = sys_write)
        "movq $1, %%rdi;" // File descriptor (1 = stdout)
        "movq %0, %%rsi;" // Ponteiro para a string
        "movq %1, %%rdx;" // Tamanho da string
        "syscall"         // Executa a syscall
        :
        : "r"(new_str), "r"(len + 1) // Passando a string e o tamanho correto
        : "%rax", "%rdi", "%rsi", "%rdx");
}

int main(int argc, char **argv)
{
    // Testando a função println
    println("Olá mundo!");
    println("Linguagem C");

    printf("---------------------------\n");

    int n1 = 10, n2 = 20, resultado = 0;

    asm volatile(
        "addl %1, %0;"     // Soma de n1 e n2
        : "=r"(resultado)  // Saída
        : "r"(n1), "0"(n2) // Entradas
    );

    printf("10 + 20 = %d\n", resultado);
    return 0;
}
