#include <stdio.h>

// Caracteres especiais (caracteres de escape): Permitem realizar ações específicas na exibição,
// e sempre são precedidos pelo caractere '\'. São úteis para controlar a saída de dados de forma
// mais dinâmica.

int main(int argc, char **argv)
{
    printf("CARACTERES ESPECIAIS:\n");

    // Descrição dos caracteres especiais
    printf("\n [\\a]   \t -> Alerta sonoro (beep)\n");
    printf("\n [\\b]   \t -> Backspace (deleta o último caractere)\n");
    printf("\n [\\f]   \t -> Form feed (avança para nova página)\n");
    printf("\n [\\n]   \t -> Nova linha (quebra de linha)\n");
    printf("\n [\\r]   \t -> Carriage Return (retrocede o cursor para o início da linha)\n");
    printf("\n [\\t]   \t -> Tabulação horizontal (cria um espaçamento horizontal)\n");
    printf("\n [\\v]   \t -> Tabulação vertical (cria um espaçamento vertical)\n");
    printf("\n [\\\\]  \t\t -> Barra invertida (backslash)\n");
    printf("\n [\'Lang\']  \t -> Aspas simples (representa uma aspa simples)\n");
    printf("\n [\"hello\"] \t -> Aspas duplas (representa aspas duplas)\n");
    printf("\n [\\0]   \t -> Caractere nulo (indica o fim da string)\n");
    printf("\n [%%%%] \t\t -> Porcentagem (exibe um símbolo de porcentagem)\n");

    printf("\n============================================================\n");
    printf("\n USO DOS CARACTERES ESPECIAIS:\n");

    // Exemplo de alerta sonoro (beep)
    printf("\n Toque \a\n");
    /// OUTPUT: Em sistemas com suporte, emite um beep ou alerta sonoro.

    // Exemplo de retrocesso (backspace)
    printf("\n Back\bspa\bce\n");
    /// OUTPUT: "bacspce" (o caractere 'k' foi apagado pelo backspace).

    // Exemplo de avanço de página (form feed)
    printf("\n Form\ffeed\n");
    /**
     * OUTPUT:
     *
     * form
     *     feed
     *
     * O form feed pode mover o texto para uma nova página ou linha,
     * dependendo do ambiente de exibição.
     */

    // Exemplo de quebras de linha
    printf("\n Quebra\n de\n linha\n");
    /**
     * OUTPUT:
     *
     * Quebra
     * de
     * linha
     *
     * Cada \n cria uma nova linha.
     */

    // Exemplo de retrocesso com carriage return (retorno de carro)
    printf("\n Retroce\r ssede\n");
    /// OUTPUT: "ssedece" (o 'retroce' foi substituído por 'ssede' devido ao retorno de carro).

    // Exemplo de tabulação horizontal
    printf("\n Tabu\tlacao\n");
    /// OUTPUT: "tabu   lacao" (o \t cria um espaçamento horizontal).

    // Exemplo de tabulação vertical
    printf("\n\vTabulacao\vvertical\n");
    /**
     * OUTPUT:
     *
     * tabulacao
     *          vertical
     *
     * O \v cria um espaçamento vertical entre as palavras.
     */

    // Exemplo de barra invertida
    printf("\n Tire essa \\ do seu caminho\n");
    /// OUTPUT: "Tire essa \ do seu caminho" (a barra invertida é exibida literalmente).

    // Exemplo de aspas simples
    printf("\n Hoje em dia nao preciso das \\'barras\\' mas se precisar apenas insira \\' as barras e aspas simples\\'\n");
    /**
     * OUTPUT:
     *
     * hoje em dia nao preciso das \'barras\' mas se precisar apenas insira \' as barras e aspas simples\'
     *
     * As aspas simples são exibidas com o uso de \'.
     */

    // Exemplo de aspas duplas
    printf("\n \\\"\\\"Eu sou necessario\"\\\"\\\n");
    /// OUTPUT: "\"Eu sou necessario\""

    // Exemplo de porcentagem
    printf("\n %%%% - Nao preciso de barras, apenas de irmãos\n");
    /// OUTPUT: "%% - Nao preciso de barra, apenas de irmãos"

    // Exemplo de caractere nulo (marca o fim da string)
    printf("\nEu marco o fim do texto '\\0'\n");
    /// OUTPUT: "Eu marco o fim do texto '\0'"
    /// O caractere nulo é usado para indicar o fim de uma string em C.

    return 0;
}
