#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura para armazenar a data de nascimento.
 *
 * Esta estrutura é usada para representar uma data com o formato dia, mês e ano.
 */
struct Datas
{
    unsigned dia; /**< Dia do mês (1-31). */
    unsigned mes; /**< Mês do ano (1-12). */
    unsigned ano; /**< Ano (por exemplo, 2024). */
};

/**
 * @brief Estrutura para armazenar informações pessoais de uma pessoa.
 *
 * Esta estrutura é usada para representar uma pessoa com suas informações básicas,
 * incluindo a data de nascimento, idade, sexo e nome.
 */
struct pessoa
{
    int idade;          /**< Idade da pessoa em anos. */
    char sexo;          /**< Sexo da pessoa ('f' para feminino, 'm' para masculino). */
    char nome[100];     /**< Nome completo da pessoa. */
    struct Datas datas; /**< Data de nascimento da pessoa. */
};

int main(int argc, char **argv)
{
    // Matriz para armazenar informações de 4 pessoas (2x2)
    struct pessoa pessoas[2][2];

    // Calculando o número total de elementos na matriz de pessoas
    size_t totalElementos = sizeof(pessoas) / sizeof(pessoas[0][0]);

    // Calculando o número de linhas na matriz
    size_t numLinhas = sizeof(pessoas) / sizeof(pessoas[0]);

    // Calculando o número de colunas na matriz
    size_t numColunas = sizeof(pessoas[0]) / sizeof(pessoas[0][0]);

    // Entrada de dados para cada pessoa
    for (size_t i = 0ULL; i < numLinhas; i++)
    {
        // Lendo os dados de cada pessoa
        for (size_t j = 0ULL; j < numColunas; j++)
        {
            // Solicita e lê o nome da pessoa
            printf(">> Digite seu nome: ");
            fgets(pessoas[i][j].nome, sizeof(pessoas[i][j].nome), stdin);

            // Obtendo da string
            size_t len = strlen(pessoas[i][j].nome);

            // Remove o caractere de nova linha, se presente
            if (len > 0 && pessoas[i][j].nome[len - 1] == '\n')
            {
                pessoas[i][j].nome[len - 1] = '\0'; // Substitui o \n por \0
            }

            // Solicita e lê a idade da pessoa
            printf(">> Digite sua idade: ");
            scanf("%d", &pessoas[i][j].idade);
            setbuf(stdin, NULL);

            // Solicita e lê o sexo da pessoa
            printf(">> Digite 'f' ou 'm' para o sexo: ");
            scanf("%c", &pessoas[i][j].sexo);
            setbuf(stdin, NULL);

            // Solicita e lê a data de nascimento da pessoa
            printf(">> Digite sua data de nascimento no formato dd mm aaaa: ");
            scanf("%d %d %d", &pessoas[i][j].datas.dia, &pessoas[i][j].datas.mes,
                  &pessoas[i][j].datas.ano);

            setbuf(stdin, NULL);

            printf("\n------------------------------\n");
        }
    }

    printf("IMPRIMINDO COM A MATRIZ TRADICIONALMENTE\n");

    // Impressão dos dados de cada pessoa
    for (size_t i = 0ULL; i < numLinhas; i++)
    {
        for (size_t j = 0ULL; j < numColunas; j++)
        {
            printf("\nNome: %s\n", pessoas[i][j].nome);
            printf("Idade: %d\n", pessoas[i][j].idade);
            printf("Sexo: %c\n", pessoas[i][j].sexo);
            printf("Data de nascimento: %d/%d/%d\n",
                   pessoas[i][j].datas.dia,
                   pessoas[i][j].datas.mes,
                   pessoas[i][j].datas.ano);
        }
    }

    printf("\n-----------------------------\n");

    printf("IMPRIMINDO COM A MATRIZ ARITMÉTICA DE PONTEIROS\n");

    // Ponto de partida para o início da matriz
    struct pessoa *p = (struct pessoa *)pessoas;

    // Iterando sobre cada elemento da matriz
    for (size_t i = 0ULL; i < numLinhas; i++)
    {
        // Iterando sobre cada coluna da matriz
        for (size_t j = 0ULL; j < numColunas; j++)
        {
            // Acessando o elemento usando aritmética de ponteiros
            struct pessoa *elem = p + i * numColunas + j;

            // Imprimindo as informações da pessoa
            printf("\nNome: %s\n", elem->nome);
            printf("Idade: %d\n", elem->idade);
            printf("Sexo: %c\n", elem->sexo);
            printf("Data de nascimento: %d/%d/%d\n", elem->datas.dia, elem->datas.mes, elem->datas.ano);
        }
    }
    return 0;
}
