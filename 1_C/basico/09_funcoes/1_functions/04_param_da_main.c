#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Função que converte os argumentos passados e os ordena.
 *
 * @param argc (argument count): Quantidade de argumentos passados na linha de comando.
 * @param argv (argument vector): Vetor de strings com os argumentos.
 * @return Vetor de inteiros ordenados.
 */
int *sortArguments(int argc, char **argv)
{
    // Alocando espaço para os números inteiros (considerando os argumentos passados)
    int *numbers = (int *)malloc((argc - 1) * sizeof(int));

    // Convertendo os argumentos para inteiros
    for (int i = 1; i < argc; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    // Função qsort para ordenar os números
    qsort(numbers, argc - 1, sizeof(int), (int (*)(const void *, const void *))strcmp);

    // Retornando o vetor de números ordenados
    return numbers;
}

/**
 * @brief Este programa demonstra o uso dos parâmetros da função main em C.
 *
 * @param argc (argument count): Informa a quantidade de parâmetros passados na linha de comando.
 * @param argv (argument vector): `**argv ou *argv[]` Vetor de strings que armazena os
 * argumentos passados na linha de comando. O elemento argv[0] geralmente contém o nome do programa.
 * @param env (environment): Vetor de strings que representa as variáveis de ambiente do sistema.
 *
 * @return int seu retorno é 0 para indício do programa que foi concluído com êxito.
 * @note Estes parâmetros são úteis para passar informações adicionais para o programa
 * porém não são obrigatórios. O programa pode ser executado sem eles.
 */
int main(int argc, char **argv, char **env)
{
    // Imprime todos os argumentos passados na linha de comando
    printf("Argumentos passados:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("argc[%d] - argv[%s]\n", i, argv[i]);
    }

    printf("\n===================================================================\n\n");

    // Imprime todas as variáveis de ambiente do sistema
    printf("Variáveis de ambiente:\n");
    for (int i = 0; env[i] != NULL; i++)
    {
        printf("env[%d] - %s\n", i, env[i]);
    }

    printf("\n===============================================================\n\n");

    // Verifica se foram passados argumentos suficientes
    if (argc < 2)
    {
        printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1; // Retorna 1 para indicar erro de argumentos insuficientes
    }

    // Irá Calcular a soma dos números passados como argumentos
    int sum = 0;

    for (int i = 1; i < argc; ++i)
    {
        // Converte cada argumento para inteiro e soma ao total
        sum += atoi(argv[i]);

        /**
         * Quando se passa os argumentos mesmo que sejam números no console antes de compilar
         *
         * > C:\Users\nomeUser\Documents\aprendendoC\1_C\basico\09_funcoes\1_functions>
         * > gcc 04_param_da_main.c -o main.exe
         * > .\main.exe 10 45 20
         *
         * EXE: .\main.exe 10 45 20, este argumentos serão strings devido ao tipo de
         * dado char **argv, então convertemos com a função `atoi`, pois se não a visualização 
         * será 0.
         */

        // Exibindo os valores utilizados
        printf("Os argumentos utilizando em 'argc' foram %d: %s\n", i, argv[i]);
    }

    // Imprime a soma calculada dos valores passados e convertidos pela função "atoi".
    printf("Soma dos números passados: %d\n", sum);

    printf("\n===================================================\n");

    // Verificando se foram passados argumentos suficientes
    if (argc < 2)
    {
        printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    // Chama a função para ordenar os argumentos
    int *sortedNumbers = sortArguments(argc, argv);

    // Imprime os números ordenados
    printf("Argumentos ordenados:\n");
    for (int i = 0; i < argc - 1; i++)
    {
        printf("Argumento %d: %d\n", i + 1, sortedNumbers[i]);
    }

    // Libera a memória alocada
    free(sortedNumbers);

    return 0;
}
