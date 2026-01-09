#include <stdio.h>

/**
 * #pragma pack: Diretiva de pré-processador usada para controlar o alinhamento de memória
 * de estruturas (`struct`) e uniões (`union`) em C. Permite ajustar ou desativar o *padding*
 * (bytes extras adicionados para alinhamento), garantindo tamanhos específicos para estruturas.
 * É especialmente útil em:
 * - Comunicação com hardware (ex.: protocolos binários).
 * - Interoperabilidade com outros sistemas ou linguagens.
 * - Redução do tamanho de estruturas em memória.
 *
 * Sintaxe:
 * - #pragma pack(n): Define alinhamento de n bytes (ex.: 1, 2, 4, 8). Com n=1, elimina *padding*.
 * - #pragma pack(): Restaura o alinhamento padrão.
 * - #pragma pack(push, n): Salva o estado atual e define alinhamento.
 * - #pragma pack(pop): Restaura o estado salvo.
 *
 * Exemplo:
 * - Com #pragma pack(1), a estrutura abaixo tem 9 bytes (1 + 4 + 4, sem *padding*).
 * - Sem #pragma pack, o tamanho seria maior (ex.: 12 bytes devido a alinhamento).
 *
 * Suporte:
 * - Compatível com MSVC, GCC, e Clang, mas não é padrão C (C11/C17/C23).
 * - Para portabilidade, use com #ifdef para alternar entre compiladores.
 *
 * Alternativas no GCC/Clang:
 * - Flag `-fpack-struct`: Aplica empacotamento (equivalente a #pragma pack(1)) a todas as estruturas.
 * - Flag `-fno-pack-struct`: Usa alinhamento padrão (padrão do GCC).
 * - Atributo __attribute__((packed)): Aplica empacotamento a uma estrutura específica.
 *
 * Boas práticas:
 * - Use apenas quando necessário (ex.: dados binários ou interoperabilidade).
 * - Evite empacotamento global (-fpack-struct), pois pode reduzir desempenho.
 * - Teste em diferentes arquiteturas, pois acessos desalinhados podem causar falhas.
 *
 * Compilação:
 * - MSVC: cl pragma_pack.c
 * - GCC: gcc -std=c17 -o programa pragma_pack.c
 * - Depuração: gcc -E pragma_pack.c (verifica pré-processamento)
 */

#pragma pack(push, 1) // Empacotamento de 1 byte (sem *padding*)
struct Exemplo
{
    char x;  // 1 byte
    int y;   // 4 bytes
    float z; // 4 bytes
};
#pragma pack(pop) // Restaura o alinhamento padrão

struct ExemploSemPack
{
    char x;  // 1 byte + padding (ex.: 3 bytes em 32-bit)
    int y;   // 4 bytes
    float z; // 4 bytes
};

int main(int argc, char **argv)
{
    printf("Tamanho da struct com #pragma pack(1): %zu bytes\n", sizeof(struct Exemplo));
    printf("Tamanho da struct sem #pragma pack: %zu bytes\n", sizeof(struct ExemploSemPack));
    return 0;
}
