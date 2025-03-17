#include <stdio.h>
#include "pessoa.h"

int main(int argc, char **argv)
{
    // Criando uma instância da struct `Person`
    struct Person *pessoa;

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
    struct Person pessoa1;

    // Inicializando a struct `Person`
    setPessoa(&pessoa1, "Pedro", 27U, 1.71, 95.4);

    // Imprimindo os dados da struct `Person`
    getPessoa(&pessoa1);

    // Calcular e imprimir o IMC da pessoa
    imprimirIMC(&pessoa1);

    // Verificar e imprimir se a pessoa está obesa
    imprimirObesidade(&pessoa1);

    printf("\n------------------------\n");

    struct Person pessoa2;

    // Testando com valores inválidos (altura ou peso zero)
    setPessoa(&pessoa2, "Maria", 28U, 0.0, 70.0); // Altura zero
    imprimirIMC(&pessoa2);                        // Não deve calcular

    printf("\n------------------------\n");

    struct Person *pessoa3;
    setPessoa(pessoa3, "Carlos", 35U, 1.80, 0.0); // Peso zero
    imprimirIMC(pessoa3);                         // Não deve calcular

    return 0;
}
