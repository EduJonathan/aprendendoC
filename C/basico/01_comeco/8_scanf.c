#include <stdio.h>

/**
 * scanf: Função da linguagem C utilizada para entrada de dados(input) fornecidos pelo usuário.
 *
 * SINTAXE: scanf("formato", &variavel);
 *
 * O símbolo '&' (operador de endereço) é essencial para passar o endereço de memória da variável,
 * permitindo que a função armazene o valor digitado diretamente nessa posição.
 *
 * IMPORTANTE: Sempre utilize '&' antes da variável (exceto em strings), ele indica onde o
 * valor lido deve ser armazenado. Esquecer esse operador pode causar erros de execução ou
 * comportamento indefinido.
 */

int main(int argc, char **argv)
{
    printf("\n\t==>SCANF<==\n");

    int idade = 0;
    char letra = '\0';
    float pi = 0.0f;

    printf(">> Quantos anos você tem : ");
    scanf("%d", &idade);
    setbuf(stdin, NULL);

    printf(">> Digite apenas uma letra : ");
    scanf("%c", &letra);
    setbuf(stdin, NULL);

    printf(">> Digite o numero do PI : ");
    scanf("%f", &pi);
    setbuf(stdin, NULL);

    // Gerando saída de dados (output) do conteúdo digitado, a partir do printf
    printf("\n Sua Idade é     \t : %d\n", idade);
    printf(" A letra digitada é\t : %c\n", letra);
    printf(" O número do PI é\t : %f\n", pi);

    /**
     * No código utilizamos a função fflush, acontece que quando usamos o scanf ou
     * qualquer outro uso de input quando é digitado um conteúdo acontece o buffer
     * de teclado.
     * (BUFFER DE MEMÓRIA: Aréa de memória específica para o armazenamento das teclas que
     * são digitadas pelo usuário, ou seja, cada tecla pressionada ela será guardada no buffer
     * de teclado, e a informação irá ficar lá até o programar encerrar ou o computador seja desligado).
     *
     * fflush(): Função que limpa o buffer de saída de um fluxo de dados, como `stdin` ou
     * `stdout`. É comumente usada para evitar problemas ao ler entradas do teclado após uma
     * operação de `scanf()`. No entanto, seu comportamento em `stdin` não é padronizado e pode
     * não funcionar em todas as implementações.
     *
     * setbuf(): Permite configurar o buffer de um fluxo, podendo desativá-lo (`NULL`)
     * ou definir um buffer específico. Diferente do `fflush()`, que apenas limpa o buffer,
     * `setbuf()` dá mais controle sobre o uso do buffer de entrada e saída. Mais recomendado!
     *
     * fpurge(): Similar ao `fflush()`, mas especificamente projetada para limpar o
     * buffer de entrada (`stdin`). No entanto, essa função não faz parte do padrão ANSI C e
     * pode não estar disponível em todas as plataformas.
     */

    unsigned char caractere = '\0';
    unsigned char letter = '\0';

    printf("\n>> Digite um caractere: ");
    scanf(" %c", &caractere);
    printf("Você inseriu a letra : %c\n", caractere);

    printf("\n>> Digite uma letra : ");
    scanf(" %c", &letter);
    printf("Você inseriu a letra : %c\n", letter);

    /**
     * Perceba que não utilizamos o fflush, e sem ele a partir do momento de
     * digitar um valor para a variável "caractere", o programa pula esse scanf
     * não deixando o valor ser digitado, existe uma maneira de burlar esse problema,
     * sem utilizar o fflush, não sendo uma boa prática, trata-se de inserir um espaço
     * antes do formatador.
     *
     * scanf(" %c", &caractere);
     * scanf(" %c", &letter);
     *
     * ou poderia utilizar também uma função chamada getchar(), onde poderiámos:
     *
     * scanf("%c", &caractere);
     * getchar();
     *
     * scanf("%c", &letter);
     * getchar();
     *
     * perceba, que os espaços antes do formatador não se encontram, mas como dito
     * não se torna uma boa prática, Existem outras maneiras de tratar strings e limpeza
     * de buffer além do fflush, veremos adiante.
     * OBS: Cuidado com strings e char eles precisam de atenção para seus usos.
     */

    printf("\n-----------------------------------------------------\n");
    printf("\n\t==>SCANF COM MÚLTIPLAS ENTRADAS<==\n");

    unsigned dia = 0;
    unsigned mes = 0;
    unsigned ano = 0;

    /// OBS: Ter entrada múltiplas de dados não é aconselhável o seu uso por não ser uma boa prática.
    printf(">> Insira o dia, mes e ano atual (formato: dia mes ano): ");
    scanf("%u %u %u", &dia, &mes, &ano); // (01 01 2025)

    printf(" A data atual é: %u/%u/%u\n", dia, mes, ano);
    return 0;
}
