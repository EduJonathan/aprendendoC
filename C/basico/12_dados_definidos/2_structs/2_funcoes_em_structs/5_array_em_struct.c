#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura para armazenar informações de um estudante.
 *
 * Esta estrutura contém o número de matrícula, o nome do estudante e a porcentagem.
 */
struct registroDeEstudantes
{
    unsigned matriculaAluno; /**< Número de matrícula do estudante. */
    char nomeEstudante[50];  /**< Nome do estudante. */
    float percentual;        /**< Percentual de notas do estudante. */
};

/**
 * @brief Coleta dados de estudantes.
 * Esta função solicita e lê as informações dos estudantes, como número de matrícula,
 * nome e percentual.
 *
 * @param students Array de estruturas registroDeEstudantes onde as informações serão armazenadas.
 * @param numEstudantes Número de estudantes cujas informações devem ser coletadas.
 */
void coletarDados(struct registroDeEstudantes students[], size_t numEstudantes)
{
    // Pecorrendo para inserir os dados do aluno
    for (size_t i = 0ull; i < numEstudantes; i++)
    {
        printf("\n>> Digite o id do aluno: ");
        scanf("%u", &students[i].matriculaAluno);
        setbuf(stdin, NULL);

        printf("\n>> Digite o nome do aluno: ");
        fgets(students[i].nomeEstudante, sizeof(students[i].nomeEstudante), stdin);

        // Tamanho da string
        size_t len = strlen(students[i].nomeEstudante);

        // Remove o caractere de nova linha, se presente
        if (len > 0 && students[i].nomeEstudante[len - 1] == '\n')
        {
            students[i].nomeEstudante[len - 1] = '\0'; // Substitui o \n por \0
        }

        printf("\n>> Digite o percentual do aluno: ");
        scanf("%f", &students[i].percentual);
        setbuf(stdin, NULL);

        printf("\n-----------------------------------------\n");
    }
}

/**
 * @brief Imprime as informações dos estudantes.
 * Esta função exibe as informações de todos os estudantes na tela.
 *
 * @param students Array de estruturas registroDeEstudantes cujas informações serão exibidas.
 * @param numEstudantes Número de estudantes cujas informações devem ser exibidas.
 */
void imprimirDadosTradicional(struct registroDeEstudantes students[], size_t numEstudantes)
{
    printf("\nIMPRIMINDO AS INFORMAÇÕES DOS ESTUDANTE TRADICIONALMENTE\n");
    for (size_t i = 0ull; i < numEstudantes; i++)
    {
        printf("\nId do aluno: %u\t Nome do aluno: %s\t Percentual: %.2f\n",
               students[i].matriculaAluno,
               students[i].nomeEstudante,
               students[i].percentual);
    }
}

/**
 * @brief Imprime as informações dos estudantes usando aritmética de ponteiros.
 * Esta função exibe as informações de todos os estudantes na tela utilizando aritmética de
 * ponteiros.
 *
 * @param students Ponteiro para o array de estruturas registroDeEstudantes cujas informações
 * serão exibidas.
 * @param numEstudantes Número de estudantes cujas informações devem ser exibidas.
 */
void imprimirDadosPonteiros(struct registroDeEstudantes *students, size_t numEstudantes)
{
    printf("\nINFORMAÇÕES DO ESTUDANTE UTILIZANDO A ARITMÉTICA DE PONTEIROS:\n");
    for (size_t i = 0ull; i < numEstudantes; i++)
    {
        // Acesso ao elemento usando aritmética de ponteiros
        struct registroDeEstudantes *currentStudent = students + i;

        printf("\nId do aluno: %u\t Nome do aluno: %s\t Percentual: %.2f\n",
               currentStudent->matriculaAluno,
               currentStudent->nomeEstudante,
               currentStudent->percentual);
    }
}

int main(int argc, char **argv)
{
    // Matriz para armazenar registros de estudantes
    struct registroDeEstudantes studentRecord[3] = {0}; // Inicializando com zero

    // Calculando o número total de elementos no array
    size_t totalElementos = sizeof(studentRecord) / sizeof(studentRecord[0]);

    // Coletando dados dos estudantes
    coletarDados(studentRecord, totalElementos);

    // Imprimindo dados tradicionalmente
    imprimirDadosTradicional(studentRecord, totalElementos);

    printf("\n---------------------------------------\n");

    // Imprimindo dados usando aritmética de ponteiros
    imprimirDadosPonteiros(studentRecord, totalElementos);
    return 0;
}
