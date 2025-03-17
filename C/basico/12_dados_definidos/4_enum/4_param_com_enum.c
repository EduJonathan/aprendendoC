#include <stdio.h>

/**
 * @enum escapes
 *
 * @brief Enumeração para representar caracteres de controle comuns. Esta enumeração
 * define alguns caracteres de controle
 */
enum escapes
{
    retrocesso = '\b', /**< Caractere de retrocesso (backspace) */
    tabulacao = '\t',  /**< Caractere de tabulação horizontal */
    novalinha = '\n'   /**< Caractere de nova linha */
};

/**
 * @brief Imprime uma mensagem baseada no caractere de controle fornecido.
 *
 * @param caracteresEspeciais Um valor da enumeração `escapes` que determina qual
 * caractere de controle será usado para a impressão.
 */
void imprimirMensagem(enum escapes caracteresEspeciais)
{
    switch (caracteresEspeciais)
    {
    case retrocesso:
        printf("\nTeste de retrocesso %c escrita\n", caracteresEspeciais);
        break;

    case tabulacao:
        printf("\nTeste de tabulação %c escrita\n", caracteresEspeciais);
        break;

    case novalinha:
        printf("\nTeste de nova linha %c escrita\n", caracteresEspeciais);
        break;

    default:
        printf("\nValor inválido do enum\n");
        break;
    }
}

int main(int argv, char **argc)
{
    enum escapes charEspecial = novalinha;

    // Chamada da função para imprimir mensagem com o valor de charEspecial
    imprimirMensagem(charEspecial);

    charEspecial = tabulacao;

    // Chamada da função novamente para imprimir mensagem com o novo valor de charEspecial
    imprimirMensagem(charEspecial);
    return 0;
}
