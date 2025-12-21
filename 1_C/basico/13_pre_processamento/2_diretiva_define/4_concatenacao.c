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
#define ERROR   1
#define WARNING 2
#define INFO    3

// 1. Define a estrutura e cria um apelido (typedef) para facilitar o uso
#define class(name, block)    \
    typedef struct name name; \
    struct name block

// 2. Define o construtor: aloca memória e executa o bloco de inicialização
#define class_constructor(name, ctor_block)        \
    name *name##_new(void)                         \
    {                                              \
        name *self = (name *)malloc(sizeof(name)); \
        do                                         \
        {                                          \
            ctor_block                             \
        } while (0);                               \
        return self;                               \
    }

#define new(class_name) class_name##_new()

// 3. Função de suporte para o atributo cleanup (liberação automática)
void autoFree_func(void *ptr_ptr)
{
    void *ptr = *(void **)ptr_ptr;
    if (ptr)
    {
        printf("[Log] Liberando memoria automaticamente...\n");
        free(ptr);
    }
}

#define autoFree __attribute__((cleanup(autoFree_func)))
#define var      __auto_type

class(TestClass, {
    int a;
    int b;
    int (*sum)(struct TestClass *self); // Ponteiro para função (Método)
});

// Função que será usada como método da "classe"
int TestClassSum(TestClass *self)
{
    return self->a + self->b;
}

// Implementação do construtor da TestClass
class_constructor(TestClass, {
    self->a = 0;
    self->b = 0;
    self->sum = TestClassSum; // Atribui a função ao ponteiro
});

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

    {
        // 'autoFree' fará com que o objeto seja liberado assim que sair deste escopo { }
        autoFree var obj = new(TestClass);
        obj->a = 5;
        obj->b = 4;

        // Chamando o método através do ponteiro e passando 'obj' como 'self'
        printf("Resultado da soma: %d\n", obj->sum(obj));
    }
    // Aqui a memória já foi liberada automaticamente pelo autoFree_func
    return 0;
}
