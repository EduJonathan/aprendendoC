#include <stdio.h>
#include <string.h>

/**
 * O #pragma warning controla avisos (warnings) no compilador. usado para ativar, desativar
 * ou modificar o nível de alguns avisos, especialmente no compilador MSVC (Microsoft Visual C++).
 */

/**
 * #pragma GCC diagnostic warning "-Wuninitialized" → No GCC, essa diretiva muda o nível de
 * aviso de variáveis não inicializadas para warning, garantindo alertas quando uma variável
 * pode ser usada sem ser inicializada.
 */
#ifdef __GNUC__
#pragma GCC diagnostic warning "-Wuninitialized"
#endif

/**
 * #pragma warning(push) → No MSVC (Visual Studio Compiler), salva o estado atual das
 * advertências antes de desativar alguma.
 * #pragma warning(disable : 4996) → No MSVC, desativa o aviso C4996, que geralmente ocorre
 * ao usar funções consideradas inseguras, como scanf() e strcpy().
 * #pragma warning(pop) → Restaura os warnings para o estado anterior.
 */
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996) // Desativa aviso sobre strcpy
#endif

void usarStrcpy()
{
    char destino[10];
    strcpy(destino, "Hello!"); // Pode gerar um aviso em MSVC

    printf("String copiada: %s\n", destino);
}

#ifdef _MSC_VER
#pragma warning(pop)
#pragma warning(push)
#pragma warning(disable : 4101) // Variável não utilizada
#endif

void funcaoComVariavel()
{
    int x; // Variável não utilizada, normalmente gera aviso em MSVC
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

int main(int argc, char **argv)
{
    int x;                         // Variável não inicializada
    printf("Valor de x: %d\n", x); // O compilador pode alertar aqui!

    usarStrcpy();

    /**
     * Aconselho a compilação para melhor resultado das diretivas em cada cenário
     * com a seguinte linha:
     * > gcc -Wall -O1 -std=c11 nome_do_seu_arquivo_de_codigo.c -o teste
     * > .\teste.exe
     */
    return 0;
}
