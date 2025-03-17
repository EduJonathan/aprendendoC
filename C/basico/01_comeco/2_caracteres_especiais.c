#include <stdio.h>

// Caracteres especiais (caracteres de escape): permitem realizar
// uma determinada ação, e estão sempre acompanhado pela '\'.

int main(int argc, char **argv)
{
    printf("CARACTERES ESPECIAIS:\n");

    printf("\n [\\a]   \t -> Beep\n");
    printf("\n [\\b]   \t -> Backsapce\n");
    printf("\n [\\f]   \t -> Form feed\n");
    printf("\n [\\n]   \t -> New Line - Nova Linha\n");
    printf("\n [\\r]   \t -> Carriage Return - retrocesso\n");
    printf("\n [\\t]   \t -> Tab horizontal\n");
    printf("\n [\\v]   \t -> Tab vertical\n");
    printf("\n [\\\\]  \t\t -> Backslash - barra vertical\n");
    printf("\n [\'Lang\']  \t -> One quote - uma aspa\n");
    printf("\n [\"hello\"] \t -> Double quotes - duas aspa\n");
    printf("\n [\\0]   \t -> Caractere Nulo\n");
    printf("\n [%%%%] \t\t -> porcentagem dupla - insere uma porcentagem\n");

    printf("\n============================================================\n");
    printf("\n USO DOS CARACTERES ESPECIAIS:\n");

    // Alerta sonoro
    printf("\n Toque \a\n");
    /// OUTPUT: Toque de um beep do sistema operacional

    // Retrocesso (backspace)
    printf("\n back\bspa\bce\n");
    /// OUTPUT: bacspce

    // Avanço de página (form feed)
    printf("\n form\ffeed\n");
    /**
     * OUTPUT:
     * 
     * form
     *     feed
     */

    // Quebras de linha
    printf("\n Quebra\n de\n linha\n");
    /**
     * OUTPUT:
     * 
     * Quebra
     * de
     * linha
     */

    // Retrocesso (carriage return)
    printf("\n retroce\r ssede\n");
    /// OUTPUT: ssedece

    // Tabulação horizontal
    printf("\n tabu\tlacao\n");
    /// OUTPUT: tabu   lacao

    // Tabulação vertical
    printf("\n\vtabulacao\vvertical\n");
    /**
     * OUTPUT:
     * 
     * tabulacao
     *          vertical
     */

    // Barra invertida
    printf("\n Tire essa \\ do seu caminho\n");
    /// OUTPUT: Tire essa \ do seu caminho

    // Aspas simples
    printf("\n hoje em dia nao preciso das \\'barras\\' mas se precisar apenas insira \\' as barras e aspas simples\\'\n");
    /**
     * OUTPUT:
     * 
     * hoje em dia das nao preciso das \'barras\' mas se precisar apenas insira \'as barras e aspas simples\'
     */

    // Aspas duplas
    printf("\n \\\"\\\"Eu sou necessario\"\\\"\\\n");
    /// OUTPUT: \"\"Eu sou necessario"\"\

    // Porcentagem
    printf("\n %%%% - nao preciso de barras, apenas de irmãos\n");
    /// OUTPUT: %% - nao preciso de barra apenas de irmãos

    // Caractere nulo (marca o fim do texto)
    printf("\n '\\0' eu marco o fim do texto\n");
    /// OUTPUT: '\0' eu marco o fim do texto
    return 0;
}
