#include <stdio.h>

/*
 * Tudo que foi demonstrado em structs a union pode realizar também, pois assim como
 * structs, unions podem agrupar vários tipos de dados, mas tendo suas diferenças em sua
 * alocação de memória para com os campos que unions em vez de separar cada membro em um
 * bloco de memória único, todos os membros ocupam um único espaço de memória apenas.
 * A alocação de memória para uma union é determinada pela quantidade de memória necessária
 * para o membro de maior tamanho dentro da union.
 */

/**
 * @brief Definição de uma união chamada `Dado`.
 *
 * Esta união permite armazenar diferentes tipos de dados na mesma localização de memória.
 * Apenas um dos membros da união pode conter um valor válido de cada vez.
 */
union Dado
{
    int inteiro;          /**< Membro inteiro, ocupa 4 bytes. */
    float pontoFlutuante; /**< Membro float, ocupa 4 bytes. */
    char caractere;       /**< Membro char, ocupa 1 byte. */
};

int main(int argc, char **argv)
{
    // Declaração de uma variável 'dados' do tipo 'Dado'
    union Dado dados;

    // Impressão do tamanho da Union 'Dado'
    printf("Tamanho da Union Dado: %zu bytes\n", sizeof(dados));

    // Atribuição de valor ao membro 'inteiro' da Union
    dados.inteiro = 42;

    // Impressão do endereço de memória da Union 'dados'
    printf("Endereço de dados: %p\n", (void *)&dados);

    // Impressão do valor do membro 'inteiro'
    printf("Valor do inteiro: %d\n", dados.inteiro); // Output: 42

    printf("\n----------------------------------------------\n");

    dados.pontoFlutuante = 3.14; // Atribuição de valor ao membro 'pontoFlutuante' da Union

    // Impressão do endereço de memória da Union 'dados' (note que é o mesmo endereço)
    printf("\nEndereço de dados: %p\n", (void *)&dados);

    // Impressão do valor do membro 'pontoFlutuante' como um float
    printf("Valor do ponto flutuante: %f\n", dados.pontoFlutuante); // Output: 3.140000

    printf("\n----------------------------------------------\n");

    // Atribuição de valor ao membro 'caractere' da Union
    dados.caractere = 'A';

    // Impressão do endereço de memória da Union 'dados' (ainda o mesmo endereço)
    printf("\nEndereço de dados: %p\n", (void *)&dados);

    // Impressão do valor do membro 'caractere' como um caractere e como um número inteiro
    printf("Valor do caractere: %c\n", dados.caractere);                // Output: A
    printf("Valor do caractere (como inteiro): %d\n", dados.caractere); // Output: 65 (Onde 65 na tabela ASCII é 'A')

    /*
     * O código acima demonstra o uso de uma Union chamada 'Dado' com três membros:
     * 'inteiro' do tipo int, 'pontoFlutuante' do tipo float e 'caractere' do tipo char.
     * Durante a execução do programa, são atribuídos valores a cada membro, e o programa
     * imprime os valores dos membros, bem como seus endereços de memória. É importante
     * notar que todos os membros compartilham o mesmo espaço de memória.
     */
    return 0;
}
