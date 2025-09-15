#include <stdlib.h>
#include "pessoa.h"

/**
 * TAD (Tipo Abstrato de Dados / Abstract Data Type)
 *
 * Trata-se de um modelo conceitual que define um tipo de dado com base em seu comportamento
 * e nas operações que podem ser realizadas sobre ele, sem expor os detalhes da sua implementação.
 *
 * Um TAD descreve:
 * - Quais dados o tipo armazena
 * - Quais operações podem ser realizadas sobre ele
 * - Quais são os efeitos dessas operações
 *
 * A implementação concreta (em C, por exemplo) é escondida do usuário do TAD, promovendo encapsulamento e modularização.
 *
 * TESE: O TAD é utilizado para modelar um conjunto de dados e operações de forma independente
 * da implementação, favorecendo a separação entre interface (.h) e implementação (.c).
 *
 * VANTAGENS:
 * - Maior organização e modularização do código.
 * - Reutilização de componentes.
 * - Facilidade de manutenção e testes.
 * - Encapsulamento: oculta detalhes internos da estrutura de dados.
 *
 * DESVANTAGENS:
 * - Exige compilação separada dos módulos (arquivos .c), o que pode ser mais trabalhoso em projetos simples.
 *
 * - Pode gerar erros de *linkagem* se os arquivos não forem corretamentecompilados e ligados
 *   (por exemplo, esquecer de incluir algum arquivo.c na hora de compilar).
 *
 * Exemplo de compilação manual no terminal (para arquivos separados): gcc main.c pessoa.c -o programa
 */

int main(int argc, char **argv)
{
    struct Pessoa p;

    // Teste 1: Sobrepeso
    if (setPessoa(&p, "João Silva", 30, 1.75, 80.0))
    {
        getPessoa(&p);
        imprimirIMC(&p);
        imprimirObesidade(&p);
        struct IMC imc = classificarIMC(&p);
        printf("Classificação: %s (IMC: %.2f)\n", imc.descricao, imc.valor);
    }

    printf("-------------------------------------\n");

    // Teste 2: Obesidade
    if (setPessoa(&p, "Maria Souza", 25, 1.60, 90.0))
    {
        getPessoa(&p);
        imprimirIMC(&p);
        imprimirObesidade(&p);
        struct IMC imc = classificarIMC(&p);
        printf("Classificação: %s (IMC: %.2f)\n", imc.descricao, imc.valor);
    }

    printf("-------------------------------------\n");

    // Teste 3: Abaixo do peso
    if (setPessoa(&p, "Ana Costa", 20, 1.65, 45.0))
    {
        getPessoa(&p);
        imprimirIMC(&p);
        imprimirObesidade(&p);
        struct IMC imc = classificarIMC(&p);
        printf("Classificação: %s (IMC: %.2f)\n", imc.descricao, imc.valor);
    }

    printf("-------------------------------------\n");

    struct Pessoa *eduardo = malloc(sizeof(struct Pessoa));
    if (eduardo == NULL)
    {
        printf("Erro ao alocar memória para Eduardo.\n");
        return 1;
    }

    if (setPessoa(eduardo, "Eduardo", 25, 1.73, 80))
    {
        getPessoa(eduardo);
        imprimirIMC(eduardo);
        imprimirObesidade(eduardo);
    }

    free(eduardo); // Libera a memória alocada

    /**
     * Compile e execute com:
     * gcc -o imc .\main.c .\pessoa.c
     * .\imc.exe
     */

    return 0;
}
