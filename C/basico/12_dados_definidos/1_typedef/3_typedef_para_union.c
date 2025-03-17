#include <stdio.h>

/**
 * @brief Representa uma união de tipos de dados diferentes. Esta união pode armazenar
 * um valor de tipo inteiro, flutuante ou caractere, mas somente um tipo
 * pode ser armazenado e acessado por vez aos membros da union.
 */
union minhaUnion
{
    int inteiro;     /**< Armazena um valor inteiro. */
    float flutuante; /**< Armazena um valor flutuante. */
    char caractere;  /**< Armazena um valor caractere. */
};

typedef union minhaUnion TipoUnionGlobal;         // Renomeando minhaUnion para instância global.
typedef union minhaUnion *PointerTipoUnionGlobal; // Renomeando minhaUnion para ponteiro de instância global.

int main(int argc, char **argv)
{
    printf("\n================================================================\n");
    printf("\n\t\t TipoUnionGlobal dadosGlobais:\n");

    // Chamando e definindo o tipo de TipoUnionGlobal para dadosGlobais
    TipoUnionGlobal dadosGlobais;

    // Definido dados para os campos da instância renomeada `dadosGlobais` e imprimindo
    dadosGlobais.inteiro = 10;
    printf(" inteiro: %d\n", dadosGlobais.inteiro);

    // Definido dados para os campos da instância renomeada `dadosGlobais` e imprimindo
    dadosGlobais.flutuante = 3.14;
    printf(" Flutuante: %f\n", dadosGlobais.flutuante);

    // Definido dados para os campos da instância renomeada `dadosGlobais` e imprimindo
    dadosGlobais.caractere = 'A';
    printf(" caractere: %c\n", dadosGlobais.caractere);

    printf("\n================================================================\n");
    printf("\n\t\t TipoUnionLocal dadosLocais:\n");

    // Renomeando minhaUnion para instância local.
    typedef union minhaUnion TipoUnionLocal;

    // Chamando e definindo o tipo de TipoUnionLocal para dadosLocais
    TipoUnionLocal dadosLocais;

    // Definido dados para os campos da instância renomeada `TipoUnion` e imprimindo
    dadosLocais.inteiro = 15;
    printf(" inteiro: %d\n", dadosLocais.inteiro);

    // Definido dados para os campos da instância renomeada `TipoUnion` e imprimindo
    dadosLocais.flutuante = 0.4F;
    printf(" Flutuante: %f\n", dadosLocais.flutuante);

    // Definido dados para os campos da instância renomeada `TipoUnion` e imprimindo
    dadosLocais.caractere = 'C';
    printf(" caractere: %c\n", dadosLocais.caractere);

    printf("=================================================================\n");
    printf("\n\t\t PointerTipoUnionGlobal ptrDadosGlobais:\n");

    // Criando minhaUnion apartir da instância renomeada `ptrDadosGlobais`
    PointerTipoUnionGlobal ptrDadosGlobais = &dadosGlobais;

    // Definido dados para os campos da instância renomeada `TipoUnion` e imprimindo
    (*ptrDadosGlobais).caractere = 'a';
    (*ptrDadosGlobais).inteiro = 65;
    (*ptrDadosGlobais).flutuante = 3.14F;

    printf(" (*ptrDadosGlobais).caractere : %c\n", ptrDadosGlobais->caractere);
    printf(" (*ptrDadosGlobais).inteiro   : %d\n", ptrDadosGlobais->inteiro);
    printf(" (*ptrDadosGlobais).flutuante : %f\n", ptrDadosGlobais->flutuante);

    printf("\n=================================================================\n");
    printf("\n\t\t PointerTipoUnionLocal ptrDadosLocais:\n");

    // Renomeando minhaUnion para ponteiro de instância local.
    typedef union minhaUnion *PointerTipoUnionLocal;

    // Criando minhaUnion apartir da instância renomeada `PointerTipoUnionLocal`
    PointerTipoUnionLocal ptrDadosLocais = &dadosLocais;

    // Definido dados para os campos da instância renomeada `TipoUnion` e imprimindo
    (*ptrDadosLocais).caractere = 'F';
    (*ptrDadosLocais).inteiro = 4;
    (*ptrDadosLocais).flutuante = 6.14F;

    printf(" (*ptrDadosLocais).caractere : %c\n", ptrDadosLocais->caractere);
    printf(" (*ptrDadosLocais).inteiro   : %d\n", ptrDadosLocais->inteiro);
    printf(" (*ptrDadosLocais).flutuante : %f\n", ptrDadosLocais->flutuante);
    return 0;
}
