#include <stdio.h>

/**
 * PADDING EM STRUCTS:
 * Em C, quando definimos uma `struct`, o compilador pode inserir espaços extras de memória
 * chamados de *padding* (preenchimento) entre os membros da struct.
 *
 * POR QUE ISSO ACONTECE?
 * O padding é usado para alinhar os dados da struct na memória, de forma que cada membro
 * esteja no endereço de memória adequado para seu tipo de dado. Isso permite que o
 * processador acesse os dados de maneira mais rápida e eficiente.
 *
 * EXEMPLO:
 *
 * struct Exemplo {
 *     char a;   // 1 byte
 *     int b;    // 4 bytes
 * };
 *
 * => Esperado: 1 byte (char) + 4 bytes (int) = 5 bytes
 * => Realidade: O compilador geralmente aloca 8 bytes!
 *
 * POR QUÊ?
 * - O `char` ocupa 1 byte.
 * - O `int` precisa começar em um endereço múltiplo de 4 (em arquiteturas comuns).
 * - Então o compilador insere 3 bytes de *padding* após o `char`, antes do `int`.
 * - Total: 8 bytes usados, para garantir o alinhamento.
 *
 * COMO EVITAR OU CONTROLAR O PADDING?
 * - A reorganização os membros da struct do maior para o menor tipo pode reduzir ou eliminar padding.
 * - Exemplo otimizado:
 *
 * struct Melhor {
 *   int b;
 *   char a;
 * };
 *
 * Nesse caso, o `int` vem primeiro, e o `char` pode ficar no final com menos ou nenhum padding extra.
 *
 * CONCLUSÃO:
 * - O padding é automático, feito pelo compilador.
 * - Serve para alinhamento eficiente dos dados, porém o padding acontece principalmente
 * pela influência da organização dos campos (ordem dos membros) dentro da struct.
 * - É importante entender isso especialmente ao trabalhar com I/O binário, sockets,
 * ou interoperabilidade entre linguagens.
 */

struct SemPadding
{
    int a;  // 4 bytes
    char b; // 1 byte
    // --> Padding de 3 bytes pode ser inserido aqui
};

struct ComMaisTipos
{
    char a; // 1 byte
    int b;  // 4 bytes -> precisa começar em múltiplo de 4
    char c; // 1 byte
    // --> Padding após 'a' (3 bytes) e talvez após 'c' (3 bytes)
};

struct naoOrdenada
{
    char c;
    double d;
    short s;
    int i;
};

struct Ordenada
{
    char c;
    short s;
    int i;
    double d;
};

struct Otimizada
{
    int b;  // 4 bytes
    char a; // 1 byte
    char c; // 1 byte
    // --> Pode sobrar menos padding aqui (2 bytes no final)
};

// Struct que será aninhada
struct Interna
{
    char a; // 1 byte
    int b;  // 4 bytes -> exige alinhamento
    // --> total 8 bytes, Deve ter 3 bytes de padding após 'a'
};

// Struct externa com a interna aninhada
struct Externa
{
    char x;            // 1 byte
    struct Interna in; // começa no próximo múltiplo de 4
    int y;             // também precisa de alinhamento
};

int main(int argc, char **argv)
{
    struct Externa s;

    printf("Tamanho da struct SemPadding   : %zu bytes\n", sizeof(struct SemPadding));
    printf("Tamanho da struct ComMaisTipos : %zu bytes\n", sizeof(struct ComMaisTipos));
    printf("Tamanho da struct Otimizada    : %zu bytes\n", sizeof(struct Otimizada));
    printf("Tamanho da struct Interna      : %zu bytes\n", sizeof(struct Interna));
    printf("Tamanho da struct Externa      : %zu bytes\n", sizeof(struct Externa));
    printf("Tamanho da struct naoOrdenada  : %zu bytes\n", sizeof(struct naoOrdenada));
    printf("Tamanho da struct Ordenada     : %zu bytes\n", sizeof(struct Ordenada));

    // Mostrando endereços para entender o padding
    printf("\nEndereço de x  : %p\n", (void *)&s.x);
    printf("Endereço de in.a : %p\n", (void *)&s.in.a);
    printf("Endereço de in.b : %p\n", (void *)&s.in.b);
    printf("Endereço de y    : %p\n", (void *)&s.y);

    return 0;
}
