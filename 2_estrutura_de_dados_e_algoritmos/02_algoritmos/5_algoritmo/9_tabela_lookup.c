#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define KEYMAX 32

/**
 * TABELAS LOOKUP:
 *
 * Tabela lookup (ou tabela de consulta) é uma técnica que utiliza uma estrutura de dados
 * para mapear chaves a valores correspondentes, permitindo acesso rápido e eficiente
 * às informações. Em vez de calcular ou determinar um valor dinamicamente, o programa
 * consulta diretamente a tabela para obter o resultado desejado.
 *
 * Em C, uma tabela lookup pode ser implementada usando arrays, structs ou até mesmo
 * ponteiros para funções, dependendo do caso de uso. Elas ajudam a otimizar o desempenho
 * do programa ao substituir cálculos complexos ou operações repetitivas por simples
 * consultas diretas.
 *
 * Também podem substituir múltiplos comandos condicionais (if-else ou switch-case)
 * por uma única consulta de tabela, tornando o código mais limpo, organizado e eficiente.
 *
 * DETALHE:
 * Tabelas lookup não substituem todas as estruturas de controle condicional, mas são
 * uma técnica útil em cenários onde há uma correspondência direta entre chaves e valores.
 *
 * É importante considerar o uso de memória, pois tabelas lookup podem consumir mais
 * espaço dependendo do tamanho da tabela e do número de entradas.
 *
 * Além disso, não substituem estruturas de dados como hash tables ou maps/sets, que são
 * mais complexas e oferecem funcionalidades adicionais, como tratamento de colisões
 * e redimensionamento dinâmico.
 */

// Definição da estrutura
typedef struct
{
    const char *word;
    int count;
} Keyword;

// Tabela de Lookup (deve estar em ordem alfabética para a busca binária)
Keyword lookup_table[KEYMAX] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0}};

/**
 * @brief Função de comparação para busca binária
 *
 * @param a Ponteiro para o token
 * @param b Ponteiro para a estrutura Keyword
 * @return int Resultado da comparação
 */
int compare_keywords(const void *a, const void *b)
{
    return strcmp((char *)a, ((Keyword *)b)->word);
}

/**
 * @brief Conta as ocorrências das keywords no texto
 *
 * @param text Texto de entrada
 */
void count_keywords(char *text)
{
    char *delimiters = " ,.;:()[]\n\t\r";
    char *token = strtok(text, delimiters);

    while (token != NULL)
    {
        // Converte o token para minúsculo para garantir o match
        for (int i = 0; token[i]; i++)
            token[i] = tolower(token[i]);

        // Realiza o LookUp usando busca binária nativa
        Keyword *match = bsearch(token, lookup_table, KEYMAX, sizeof(Keyword), compare_keywords);

        if (match)
        {
            match->count++;
        }
        token = strtok(NULL, delimiters);
    }
}

int main(int argc, char **argv)
{
    char input[500];

    printf("Digite o texto: ");
    if (fgets(input, sizeof(input), stdin))
    {
        count_keywords(input);

        printf("\n********* Resultado do Lookup *********\n");
        printf("%-15s %s\n", "Keyword", "Count");
        printf("---------------------------------------\n");

        for (int i = 0; i < KEYMAX; i++)
        {
            if (lookup_table[i].count > 0)
            {
                printf("%-15s %d\n", lookup_table[i].word, lookup_table[i].count);
            }
        }
    }

    return 0;
}
