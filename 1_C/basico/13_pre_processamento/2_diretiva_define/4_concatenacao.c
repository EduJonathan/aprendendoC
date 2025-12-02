#include <stdio.h>

/**
 * O operador "##", conhecido como *token pasting operator*, é utilizado em macros para
 * concatenar tokens durante a fase de pré-processamento. Ele não concatena strings,
 * mas sim elementos léxicos do código — formando novos identificadores antes da
 * compilação.
 *
 * Por exemplo: token##n
 *
 * Se `n` for 5, o pré-processador produzirá o identificador `token5`. Caso exista uma
 * variável com esse nome, ela poderá ser referenciada normalmente pelo código expandido.
 *
 * No código abaixo, a macro CONCATENAR(n) usa esse mecanismo para montar dinamicamente
 * nomes de variáveis (como token34) e imprimir seu valor.
 *
 * Já a macro MSG_FORMAT(type, arg) demonstra como combinar *stringification* (#) com
 * *string literals*, convertendo o identificador `type` em texto e montando uma mensagem
 * formatada.
 */

// Macro para imprimir o valor de uma variável token seguida pelo valor de n
#define CONCATENAR(n) printf("token" #n " = %d\n", token##n)

// Macro para formatar uma mensagem com um tipo (ERROR, WARNING, INFO) e um argumento (mensagem)
#define MSG_FORMAT(type, arg) \
    #type ": " arg

// Definições de constantes para tipos de mensagem
#define ERROR 1
#define WARNING 2
#define INFO 3

int main(int argc, char **argv)
{
    // Variável para token34
    int token34 = 40;

    // Utilizando a macro CONCATENAR
    CONCATENAR(34);
    /// OUTPUT: "token34 = 40"

    // Utilizando a macro MSG_FORMAT para diferentes tipos de mensagens
    printf("%s\n", MSG_FORMAT(ERROR, "teste1"));
    /// OUTPUT: "ERROR" ":" " teste1"

    printf("%s\n", MSG_FORMAT(WARNING, "teste2"));
    /// OUTPUT: "WARNING" ": " "teste2"

    printf("%s\n", MSG_FORMAT(INFO, "teste3"));
    /// OUTPUT: "INFO" ": " "teste3"
    return 0;
}
