#include <stdio.h>

/**
 * scanf(): Função da linguagem C utilizada para entrada de dados(input) fornecidos pelo usuário.
 *
 * SINTAXE: scanf("formato", &variavel);
 *
 * O símbolo '&' (operador de endereço) é essencial para passar o endereço de memória da variável,
 * permitindo que a função armazene o valor digitado diretamente nessa posição.
 *
 * IMPORTANTE: Sempre utilize '&' antes da variável (exceto em strings), ele indica onde o
 * valor lido deve ser armazenado. Esquecer esse operador pode causar erros de execução ou
 * comportamento indefinido.
 *
 * NOVIDADE: Sempre verifique o retorno de scanf() para tratar falhas de input!
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
     * ### Sobre buffers e leitura de entrada
     *
     * Quando usamos `scanf()` ou outras funções de entrada em C, as teclas digitadas
     * pelo usuário são armazenadas em um **buffer de teclado** (buffer de memória).
     * Esse buffer é uma área de memória temporária que guarda os caracteres até que
     * o programa os leia ou seja finalizado.
     *
     * #### fflush()
     * - Função padrão da biblioteca C para **limpar o buffer de saída** de um fluxo,
     *   como `stdout` ou `stderr`.
     * - Apesar de muitas implementações permitirem `fflush(stdin)` para limpar o
     *   buffer de entrada, **isso não é definido pelo padrão ANSI C** e pode não
     *   funcionar em todos os compiladores/sistemas.
     *
     * #### setbuf()
     * - Permite configurar ou desativar o buffer de um fluxo (`stdin`, `stdout` etc.).
     * - Ao passar `NULL`, o buffer é desativado, garantindo que as operações de E/S
     *   sejam imediatas.
     * - Oferece **mais controle** que `fflush()`, pois define o comportamento do
     *   buffering em vez de apenas limpar o conteúdo atual.
     *
     * #### fpurge() (não-padrão)
     * - Função específica de algumas plataformas (ex.: BSD, GNU libc) para **esvaziar
     *   o buffer de entrada**.
     * - Útil para limpar `stdin`, mas **não é parte do padrão C** e não é portátil.
     *
     * **Recomendação**: para código portável, evite depender de `fflush(stdin)` ou
     * `fpurge()`. Se precisar descartar entrada pendente, leia e descarte os caracteres
     * manualmente ou use `setbuf()` para controlar o buffering.
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
     * ### Leitura de caracteres com `scanf()` e o problema do buffer
     *
     * Ao ler um único caractere com `scanf("%c", &caractere)`, é comum que o
     * programa "pule" a leitura. Isso ocorre porque o **caractere de nova linha (`\n`)**
     * deixado no buffer por leituras anteriores (ex.: `scanf` de números) é consumido
     * pelo próximo `scanf("%c")`.
     *
     * #### Soluções comuns (sem `fflush(stdin)`)
     *
     * 1. **Espaço antes do especificador**
     *    Colocar um espaço em `" %c"` faz o `scanf` ignorar automaticamente
     *    espaços em branco, que incluem `\n`, `\t` e espaços normais:
     *
     *    ```c
     *    scanf(" %c", &caractere);
     *    scanf(" %c", &letter);
     *    ```
     *
     *    Essa é uma prática aceitável quando se quer apenas pular espaços e novas linhas.
     *
     * 2. **Uso de `getchar()` para descartar o `\n`**
     *    Ler e descartar o caractere extra manualmente:
     *
     *    ```c
     *    scanf("%c", &caractere);
     *    getchar();  // descarta o '\n' restante
     *
     *    scanf("%c", &letter);
     *    getchar();
     *    ```
     *
     *    Aqui, o `getchar()` lê o `\n` que ficou no buffer antes da próxima leitura.
     *
     * #### Observações
     * - `fflush(stdin)` **não é padrão ANSI C** e não deve ser usado para limpar o
     *   buffer de entrada.
     * - Para strings e caracteres, sempre atente ao `\n` residual: ele é a causa
     *   mais frequente de leituras "puladas".
     * - Em leituras mais complexas (strings, linhas inteiras), considere funções
     *   como `fgets()` para maior controle.
     */

    printf("\n-----------------------------------------------------\n");
    printf("\n\t==>SCANF COM MÚLTIPLAS ENTRADAS E COM VERIFICAÇÕES<==\n");

    unsigned dia = 0, mes = 0, ano = 0;

    /**
     * OBS: Entradas múltiplas com scanf não são ideais (falha se input malformado).
     *
     * ⚠️ Entrada múltipla na mesma linha:
     * Embora funcional, dificulta validação de erros. Prefira ler cada valor
     * separadamente ou usar `fgets()` + `sscanf()` para validação.
     */

    printf(">> Insira o dia, mes e ano atual (formato: dia mes ano): ");
    int itens_lidos = scanf("%u %u %u", &dia, &mes, &ano);

    if (itens_lidos != 3)
    {
        printf("Entrada inválida! Use formato correto (ex: 18 9 2025).\n");
        dia = mes = ano = 0;
    }
    else
    {
        // Validação básica de data
        if (mes < 1 || mes > 12 || dia < 1 || dia > 31 || ano < 2020)
        {
            printf("Data inválida! Usando default.\n");
            dia = 18;
            mes = 9;
            ano = 2025; // Data atual: 18/09/2025
        }
    }

    printf(" A data atual é: %02u/%02u/%04u\n", dia, mes, ano); // Zero-padding para formato DD/MM/YYYY
    return 0;
}
