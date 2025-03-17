#include <stdio.h>

// Macro para imprimir o valor de uma variável token seguida pelo valor de n
#define CONCATENAR(n) printf("token" #n " = %d\n", token##n)
// O operador "##" realiza a concatenação dos tokens. Isso significa que ele junta o
// token com o valor do argumento `n` para formar um novo token. Exemplo, se n for 5,
// então token##n se torna token5. Se você tiver uma variável chamada token5

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
