#include <stdio.h>

/**
 * @union Union
 *
 * @brief Definição de uma união chamada `Union`. Esta união permite armazenar diferentes
 * tipos de dados na mesma localização de memória. Somente um dos membros da união pode
 * ter um valor válido de cada vez.
 */
union Union
{
    char a;  /**< Membro char */
    int b;   /**< Membro inteiro */
    float c; /**< Membro float */
};

/**
 * @struct Struct
 *
 * @brief Definição de uma estrutura chamada `Struct`. Esta estrutura armazena três
 * tipos de dados distintos: um caractere, um inteiro e um ponto flutuante.
 *
 * @note Cada membro da estrutura tem seu próprio espaço de memória, diferente da união.
 */
struct Struct
{
    char x;  /** Membro char */
    int y;   /** Membro inteiro */
    float z; /** Membro float */
};

/**
 * @brief Inicializa os membros da união `Union` com valores padrão.
 * Esta função configura todos os membros da união `Union` com valores iniciais.
 * Os valores específicos atribuídos podem ser ajustados conforme necessário.
 *
 * @param ptrUnion Ponteiro para a união `Union` a ser inicializada.
 */
void inicializarUnion(union Union *Union)
{
    *Union = (union Union){0};
}

/**
 * @brief Imprime o tamanho e o endereço de memória de cada membro da estrutura `Struct`.
 * Esta função exibe o tamanho total da estrutura `Struct` e os endereços dos seus membros.
 *
 * @param ptrStruct Ponteiro para a estrutura `Struct` cujos atributos serão impressos.
 */
void imprimeAtributosDeStruct(struct Struct *ptrStruct)
{
    printf(" TAMANHO DA STRUCT: %zu\n", sizeof(struct Struct));
    for (size_t i = 0; i < sizeof(struct Struct) / sizeof(int); i++)
    {
        printf(" Endereço de membro%d na struct: %p\n", i + 1, (void *)((int *)ptrStruct + i));
    }
}

/**
 * @brief Imprime o tamanho e o endereço de memória dos membros da união `Union`.
 * Esta função exibe o tamanho total da união `Union` e os endereços dos seus membros.
 * Como todos os membros da união compartilham o mesmo espaço de memória, todos os membros
 * têm o mesmo endereço base.
 *
 * @param ptrUnion Ponteiro para a união `Union` cujos atributos serão impressos.
 */
void imprimeAtributosDeUnion(union Union *ptrUnion)
{
    // Imprime o tamanho da união
    printf("\nTAMANHO DA UNION: %zu\n", sizeof(union Union));

    // Imprime o endereço do primeiro membro (todos os membros compartilham o mesmo endereço)
    printf("Endereço do membro 'b' na union: %p\n", (void *)&ptrUnion->b);
    printf("Endereço do membro 'c' na union: %p\n", (void *)&ptrUnion->c);
    printf("Endereço do membro 'a' na union: %p\n", (void *)&ptrUnion->a);
}

/**
 * @brief Imprime o tamanho e o endereço de memória de cada membro da união `Union`.
 * Esta função exibe o tamanho total da união `Union` e os endereços dos seus membros.
 * Como todos os membros da união compartilham o mesmo espaço de memória, todos os membros
 * têm o mesmo endereço base.
 *
 * @param ptrUnion Ponteiro para a união `Union` cujos atributos serão impressos.
 */
void imprimirUnion(const union Union *Union)
{
    printf(" Union.a: %c, Union.b: %d, Union.c: %f\n", Union->a, Union->b, Union->c);
}

int main(int argc, char **argv)
{
    printf("==============================================================\n");
    printf("\n\t\t>>DIFERENCA DE UNIONS E STRUCTS<<\n");
    printf("\n\tTAMANHO DE CADA UNION E STRUCT:\n");

    // Criação de instâncias da Struct e Union
    struct Struct estrutura;

    imprimeAtributosDeStruct(&estrutura);

    // Inicialização dos membros da estrutura
    estrutura.x = 'A';
    estrutura.y = 56;
    estrutura.z = 14.514F;

    // Impressão dos valores dos membros da estrutura
    printf("\n estrutura.x: %c\n estrutura.y: %d\n estrutura.z: %f\n", estrutura.x, estrutura.y, estrutura.z);

    // Impressão dos endereços de memória dos membros da estrutura
    printf("\n Endereço de estrutura.x : %p\n", (void *)&estrutura.x);
    printf(" Endereço de estrutura.y   : %p\n", (void *)&estrutura.y);
    printf(" Endereço de estrutura.z   : %p\n", (void *)&estrutura.z);

    printf("=====================================================================\n");

    // Criação de instâncias Union
    union Union Uniao;

    // Imprime tamanho e endereço de memória de cada membro da união
    imprimeAtributosDeUnion(&Uniao);

    putchar('\n');

    // Inicializa a união e imprime os valores do membro 'a'
    inicializarUnion(&Uniao);
    Uniao.a = 'A';

    // Imprimindo os valores
    printf("Uniao.a: %c\n", Uniao.a);
    printf("Endereço de Uniao.a: %p\n", (void *)&Uniao.a);

    putchar('\n');

    // Reinicializa a união e imprime os valores do membro 'b'
    inicializarUnion(&Uniao);
    Uniao.b = 56;

    printf("Uniao.b: %d\n", Uniao.b);
    printf("Endereço de Uniao.b: %p\n", (void *)&Uniao.b);

    putchar('\n');

    // Reinicializa a união e imprime os valores do membro 'c'
    inicializarUnion(&Uniao);
    Uniao.c = 14.514F;

    // Imprimindo os valores
    printf("Uniao.c: %f\n", Uniao.c);
    printf("Endereço de Uniao.c: %p\n", (void *)&Uniao.c);

    /**
     * @note DIFERENÇA DE UNION E STRUCT
     * TAMANHO:
     * - O tamanho da struct é a soma dos tamanhos de bytes de cada um de seus membros individuais.
     * - O tamanho de uma union é determinado pelo maior membro em termos de tamanho em bytes.
     * - Quando valores são atribuídos a membros de uma union, eles compartilham o mesmo espaço
     * de armazenamento, o que significa que, ao modificar um membro, os outros podem ser afetados.
     * Isso é evidenciado ao imprimir os valores de Uniao.a, Uniao.b e Uniao.c após atribuir valores
     * a eles, então temos que ser cuidadosos.

     * ARMAZENAMENTO:
     * - Em uma struct, cada membro tem seu próprio espaço de armazenamento (região de memória).
     * - Já em uma union, todos os membros compartilham o mesmo espaço de armazenamento.

     * REINICIALIZAÇÃO DA UNION:
     * - A reinicialização usando (union Uniao){0} é feita para garantir um estado conhecido
     * e evitar comportamentos indefinidos.
     */
    return 0;
}
