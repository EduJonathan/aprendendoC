#include <stdio.h>
#include <string.h>

/**
 * ASM: (Assembly) Refere-se à linguagem de baixo nível mais próxima da linguagem de
 * máquina, permitindo um controle absoluto sobre o hardware. Ao escrever em Assembly,
 * não é necessário utilizar bibliotecas externas ou funções de alto nível, o que permite
 * otimização manual de cada ciclo de clock e controle direto sobre a execução do código.
 * Embora ofereça grande flexibilidade e desempenho, a escrita em Assembly exige grande cuidado,
 * pois os códigos podem se tornar verbosos e difíceis de manter. Além disso, erros pequenos
 * podem causar falhas graves, tornando a manutenção e depuração um desafio.
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
