#include <stdio.h>

/**
 * #pragma message: Diretiva de pré-processador para exibir mensagens personalizadas
 * durante a COMPILAÇÃO (não na execução). Útil para:
 * - Informar o status do código (ex.: "Em desenvolvimento").
 * - Lembrar ações pendentes (ex.: "Testar em outra plataforma").
 * - Alertar sobre problemas potenciais (ex.: dependências faltantes).
 *
 * Sintaxe: #pragma message("Sua mensagem aqui")
 * - Suporte:
 *   - Nativo no MSVC: Mensagens aparecem diretamente no log de compilação.
 *   - Extensão no GCC/Clang: Requer flags como -Wall para visibilidade.
 *   - Não é padrão C (C11/C17/C23); para portabilidade, use #warning ou #error.
 * - Dica: Use #ifdef para mensagens condicionais (ex.: apenas em modo DEBUG).
 *
 * Alternativas:
 * - #warning "mensagem": Emite um aviso (padrão C99+), suportado por GCC/Clang/MSVC.
 * - #error "mensagem": Interrompe a compilação com uma mensagem de erro.
 *
 * Exemplo de saída na compilação (MSVC):
 * > cl exemplo.c
 * > Aviso: Este código está em fase de desenvolvimento.
 * > Dica: Verifique dependências externas; teste em múltiplas plataformas.
 *
 * Boas práticas:
 * - Use mensagens curtas e claras para evitar poluição no log.
 * - Prefira #warning para avisos padronizados e portáteis.
 * - Evite mensagens permanentes; use para lembretes temporários.
 * - Combine com #ifdef _MSC_VER ou __GNUC__ para portabilidade.
 *
 * Compilação:
 * - GCC: gcc -std=c17 -Wall -DDEBUG -o programa pragma_message.c
 * - gcc -std=c17 -Wall -o programa pragma_message.c
 * - MSVC: cl /W4 pragma_message.c
 * - Depuração: gcc -E pragma_message.c (verifica pré-processamento, mas não mostra mensagens)
 */

#ifdef _MSC_VER
#pragma message("Aviso: Este código está em fase de desenvolvimento.")
#else
#warning "Este código está em fase de desenvolvimento."
#endif

#ifdef DEBUG
#ifdef _MSC_VER
#pragma message("DEBUG MODE: Otimizações desativadas para testes.")
#else
#warning "DEBUG MODE: Otimizações desativadas para testes."
#endif
#endif

#ifdef _MSC_VER
#pragma message("Dica: Verifique dependências externas; teste em múltiplas plataformas.")
#else
#warning "Dica: Verifique dependências externas; teste em múltiplas plataformas."
#endif

int main(int argc, char **argv)
{
    printf("Programa compilado com sucesso!\n");
    return 0;
}
