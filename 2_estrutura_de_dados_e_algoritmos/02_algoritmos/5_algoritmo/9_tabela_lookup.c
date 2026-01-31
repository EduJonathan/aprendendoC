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

// Tabela de Lookup
Keyword lookup_table[KEYMAX] = {
    {"auto",     0},
    {"break",    0},
    {"case",     0},
    {"char",     0},
    {"const",    0},
    {"continue", 0},
    {"default",  0},
    {"do",       0},
    {"double",   0},
    {"else",     0},
    {"enum",     0},
    {"extern",   0},
    {"float",    0},
    {"for",      0},
    {"goto",     0},
    {"if",       0},
    {"int",      0},
    {"long",     0},
    {"register", 0},
    {"return",   0},
    {"short",    0},
    {"signed",   0},
    {"sizeof",   0},
    {"static",   0},
    {"struct",   0},
    {"switch",   0},
    {"typedef",  0},
    {"union",    0},
    {"unsigned", 0},
    {"void",     0},
    {"volatile", 0},
    {"while",    0}};

/**
 * @brief Função de autocomplete que sugere palavras com base no prefixo fornecido.
 *
 * @param prefix Prefixo digitado pelo usuário.
 */
void autocomplete(const char *prefix)
{
    int len = strlen(prefix);
    if (len == 0)
        return;

    int found = 0;
    printf("\nSugestoes para '%s':\n", prefix);
    printf("---------------------------\n");

    for (int i = 0; i < KEYMAX; i++)
    {
        // strncmp compara apenas até o comprimento do prefixo digitado
        if (strncmp(prefix, lookup_table[i].word, len) == 0)
        {
            printf("- %s\n", lookup_table[i].word);
            found++;
        }
    }

    if (found == 0)
    {
        printf("Nenhuma correspondencia encontrada.\n");
    }
    else
    {
        printf("Total: %d sugestao(oes).\n", found);
    }
}

int main(int argc, char **argv)
{
    char search[50];

    while (1)
    {
        printf("\nDigite um caractere (Exemplo: 'a') ou as iniciais de uma palavra (Exemplo: 'un') para autocomplete (ou 'sair'): ");
        if (fgets(search, sizeof(search), stdin))
        {
            // Remove o \n do fgets
            search[strcspn(search, "\n")] = 0;

            if (strcmp(search, "sair") == 0)
                break;

            // Converte para minúsculo para busca case-insensitive
            for (int i = 0; search[i]; i++)
                search[i] = tolower(search[i]);

            autocomplete(search);
        }
    }

    return 0;
}
