#include <stdio.h>
#include <wchar.h>
#include <locale.h>

/**
 * @brief Arquivo de cabeçalho responsável pela configuração de localidade.
 *
 * O arquivo `locale.h` fornece funções para configurar e gerenciar a localidade
 * (ou regionalidade) do ambiente de execução, permitindo o suporte a diferentes
 * convenções culturais, como formatação de números, datas e o uso de caracteres especiais
 * (ex: japoneses, árabes). A função principal para isso é `setlocale`, que ajusta o ambiente
 * de execução conforme a configuração regional desejada.
 *
 * @note Em linguagens mais modernas como Python, Java e C#, o gerenciamento de localidade
 * é feito de forma automática, minimizando problemas relacionados à configuração do ambiente.
 * Além disso, o comportamento do `locale` pode ser configurado diretamente no ambiente do 
 * editor de código.
 */

int main(int argc, char **argv)
{
    printf("=== Teste de Configuração de Localidade para UTF-8 ===\n\n");

    /*
     * LC_ALL: Configura a localidade para todas as categorias a partir das variáveis de ambiente
     * Configuração automática baseada no ambiente do sistema
     * Esta é a forma recomendada, pois usa as configurações padrão do usuário
     */
    printf("[1] Configuração automática (baseada no ambiente do sistema):\n");
    if (setlocale(LC_ALL, "") == NULL)
    {
        printf("Erro: Não foi possível configurar a localidade baseada no ambiente.\n");
    }
    else
    {
        printf("✔ Localidade configurada automaticamente.\n");
        printf("   Teste de caracteres:\n");
        printf("   - Português: Olá, mundo! çãáéíóú\n");
        printf("   - Japonês: こんにちは世界！\n");
    }
    printf("\n");

    printf("--------------------------------------------\n");

    /*
     * Configurações manuais para diferentes localidades UTF-8
     * Testamos várias opções comuns de localização
     */
    const char *locales[] = {
        "en_US.UTF-8", // Inglês Americano (comum em muitos sistemas)
        "ja_JP.UTF-8", // Japonês
        "pt_BR.UTF-8", // Português Brasileiro
        "C.UTF-8",     // Localidade C padrão com UTF-8
        NULL           // Marcador de fim
    };

    printf("[2] Testando configurações manuais de localidade:\n");

    for (int i = 0; locales[i] != NULL; i++)
    {
        printf("\nTentando locale: %s\n", locales[i]);

        if (setlocale(LC_ALL, locales[i]) == NULL)
        {
            printf("✖ Esta localidade não está disponível no sistema.\n");
        }
        else
        {
            printf("✔ Localidade configurada com sucesso.\n");
            printf("   Teste de caracteres:\n");
            printf("   - Português: Café, avião, ação\n");
            printf("   - Japonês: 漢字(かんじ), ひらがな, カタカナ\n");

            // Exemplo com wide characters (opcional)
            wprintf(L"   - Wide chars: 日本語 → Português\n");
        }
    }
    return 0;
}
