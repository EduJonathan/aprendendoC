#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

/* Tabela de Lookup - Palavras-chave da linguagem C (C99/C11) */
static const Keyword keywords[KEYMAX] = {
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
    {"while",    0}
};

/**
 * @brief Mostra todas as palavras-chave disponíveis
 */
void mostrar_todas_palavras(void)
{
    printf("\n=== Palavras-chave da Linguagem C (%d) ===\n", KEYMAX);
    for (int i = 0; i < KEYMAX; i++)
    {
        printf("%2d. %s\n", i + 1, keywords[i].word);
    }
    printf("\n");
}

/**
 * @brief Função de autocomplete que sugere palavras com base no prefixo fornecido.
 *
 * @param prefix Prefixo digitado pelo usuário.
 */
void autocomplete(const char *prefix)
{
    if (prefix == NULL || strlen(prefix) == 0)
    {
        printf("Por favor, digite pelo menos um caractere.\n");
        return;
    }

    int len = strlen(prefix);
    int found = 0;

    printf("\nSugestões para '%s':\n", prefix);
    printf("---------------------------\n");

    for (int i = 0; i < KEYMAX; i++)
    {
        // Comparação case-insensitive usando strncmp
        if (strncasecmp(prefix, keywords[i].word, len) == 0)
        {
            printf("  → %s\n", keywords[i].word);
            found++;
        }
    }

    if (found == 0)
    {
        printf("Nenhuma palavra-chave encontrada com esse prefixo.\n");
    }
    else
    {
        printf("\nTotal de sugestões: %d\n", found);
    }
}

int main(int argc, char **argv)
{
    char input[50];
    bool running = true;

    printf("=== Autocomplete de Palavras-chave da Linguagem C ===\n");
    printf("Digite prefixos (ex: 'in', 'st', 'vo') ou 'sair' para encerrar.\n");
    printf("Digite 'todas' para ver todas as palavras-chave.\n\n");

    while (running)
    {
        printf("\n> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        // Remove o caractere de nova linha
        input[strcspn(input, "\n")] = '\0';

        // Comando para sair
        if (strcmp(input, "sair") == 0 || strcmp(input, "exit") == 0)
        {
            running = false;
            continue;
        }

        // Mostrar todas as palavras
        if (strcmp(input, "todas") == 0)
        {
            mostrar_todas_palavras();
            continue;
        }

        // Converte para minúsculo e faz autocomplete
        str_to_lower(input);
        autocomplete(input);
    }

    printf("\nPrograma encerrado. Obrigado!\n");

    return 0;
}
