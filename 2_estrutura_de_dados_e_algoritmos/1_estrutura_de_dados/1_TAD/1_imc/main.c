#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main(int argc, char **argv)
{
    // Criando uma instância da struct `Person`
    struct Person *pessoa = (struct Person *)malloc(sizeof(struct Person));

    // Inicializando a struct `Person`
    setPessoa(pessoa, "João", 20U, 1.70, 80.0);

    // Imprimindo os dados da struct `Person`
    getPessoa(pessoa);

    // Calcular e imprimir o IMC da pessoa
    imprimirIMC(pessoa);

    // Verificar e imprimir se a pessoa está obesa
    imprimirObesidade(pessoa);

    printf("\n------------------------\n");

    // Criando uma instância da struct `Person`
    struct Person pessoa1 = {0}; // Inicializando a struct `Person` com zeros

    // Inicializando a struct `Person`
    setPessoa(&pessoa1, "Pedro", 27U, 1.71f, 95.4f);

    // Imprimindo os dados da struct `Person`
    getPessoa(&pessoa1);

    // Calcular e imprimir o IMC da pessoa
    imprimirIMC(&pessoa1);

    // Verificar e imprimir se a pessoa está obesa
    imprimirObesidade(&pessoa1);

    printf("\n------------------------\n");

    // ERRO: erro em "Maria" e "Carlos" aos valores inválidos para altura e peso

    struct Person pessoa2 = {0}; // Inicializando a struct `Person` com zeros

    // Testando com valores inválidos (altura ou peso zero)
    setPessoa(&pessoa2, "Maria", 28U, 0.0f, 70.0f); // Altura zero
    imprimirIMC(&pessoa2);                          // Não deve calcular

    printf("\n------------------------\n");

    struct Person *pessoa3 = (struct Person *)malloc(sizeof(struct Person));
    setPessoa(pessoa3, "Carlos", 35U, 1.80f, 0.0f); // Peso zero
    imprimirIMC(pessoa3);                           // Não deve calcular

    free(pessoa);
    free(pessoa3);
    return 0;
}
