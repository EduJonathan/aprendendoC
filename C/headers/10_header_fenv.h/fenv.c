#include <stdio.h>
#include <fenv.h>
#include <math.h>

#pragma STDC FENV_ACCESS ON

/**
 * fenv(): É uma biblioteca que fornece funções para manipular o ambiente de ponto flutuante,
 * incluindo o controle de arredondamento, exceções e status do ambiente de ponto flutuante.
 * É útil para garantir precisão e conformidade com padrões de ponto flutuante em cálculos
 * numéricos.
 *
 * exceptions: A biblioteca fenv permite o controle de exceções de ponto flutuante,
 * como divisão por zero, overflow, underflow e operações inválidas.
 * Você pode habilitar ou desabilitar essas exceções e verificar se ocorreram durante
 * os cálculos. sendo elas
 *
 * feclearexcept: Limpa as exceções de ponto flutuante especificadas.
 * fegetexceptflag: Obtém o estado das exceções de ponto flutuante e armazena em um objeto fexcept_t.
 * feraiseexcept: Levanta uma exceção de ponto flutuante especificada.
 * fesetexceptflag: Define o estado das exceções de ponto flutuante a partir de um objeto fexcept_t.
 * fetestexcept: Testa se uma ou mais exceções de ponto flutuante estão ativas.
 *
 * -------------------------
 *
 * As funções fegetround obtém o modo de arredondamento atual do ambiente de ponto flutuante.
 * fegetround: Obtém o modo de arredondamento atual.
 * fesetround: Define o modo de arredondamento.
 *
 * -------------------------
 * E as envoriment functions: Funções de ambiente de ponto flutuante
 * que permitem manipular o ambiente de ponto flutuante, como salvar e restaurar o estado
 * do ambiente, atualizar o ambiente atual e manter exceções pendentes.
 * As funções de ambiente incluem:
 *
 * fegetenv: Obtém o estado atual do ambiente de ponto flutuante.
 * fesetenv: Define o estado do ambiente de ponto flutuante.
 * feupdateenv: Atualiza o estado do ambiente de ponto flutuante.
 * feholdexcept: Mantém as exceções pendentes no ambiente de ponto flutuante.
 */

void test_fenv_exception()
{
    fexcept_t flag;

    // Limpa todas as exceções de ponto flutuante
    feclearexcept(FE_ALL_EXCEPT);

    // Testa se há exceções ativas (não deve haver nenhuma neste momento)
    if (fetestexcept(FE_ALL_EXCEPT))
    {
        printf("Exceção de ponto flutuante detectada (antes de qualquer operação)\n");
    }
    else
    {
        printf("Nenhuma exceção de ponto flutuante detectada (antes de qualquer operação)\n");
    }

    // Levanta uma exceção de ponto flutuante: divisão por zero
    printf("\nRealizando uma divisão por zero...\n");
    feraiseexcept(FE_DIVBYZERO);

    // Testa se a exceção de divisão por zero foi levantada
    if (fetestexcept(FE_DIVBYZERO))
    {
        printf("Exceção de divisão por zero detectada.\n");
    }

    // Obtém o estado das exceções de ponto flutuante
    fegetexceptflag(&flag, FE_ALL_EXCEPT);
    printf("\nEstado das exceções foi armazenado em 'flag'.\n");

    // Limpa a exceção de ponto flutuante de divisão por zero
    feclearexcept(FE_DIVBYZERO);
    printf("\nExceção de divisão por zero limpa.\n");

    // Testa novamente se a exceção foi limpa
    if (fetestexcept(FE_DIVBYZERO))
    {
        printf("Exceção de divisão por zero ainda está ativa.\n");
    }
    else
    {
        printf("Exceção de divisão por zero já foi limpa.\n");
    }

    // Restaura o estado das exceções de ponto flutuante a partir do objeto 'flag'
    fesetexceptflag(&flag, FE_ALL_EXCEPT);
    printf("\nEstado das exceções foi restaurado.\n");

    // Testa novamente se qualquer exceção está ativa
    if (fetestexcept(FE_ALL_EXCEPT))
    {
        printf("Alguma exceção de ponto flutuante está ativa.\n");
    }
    else
    {
        printf("Nenhuma exceção de ponto flutuante detectada após a restauração.\n");
    }
}

void test_rounding_modes()
{
    int current_rounding_mode;

    // Obter o modo de arredondamento atual
    current_rounding_mode = fegetround();

    // Exibir o modo de arredondamento atual
    printf("Modo de arredondamento atual: ");
    switch (current_rounding_mode)
    {
    case FE_TONEAREST:
        printf("FE_TONEAREST (Arredondar para o número mais próximo)\n");
        break;

    case FE_DOWNWARD:
        printf("FE_DOWNWARD (Arredondar para baixo)\n");
        break;

    case FE_UPWARD:
        printf("FE_UPWARD (Arredondar para cima)\n");
        break;

        // case FE_ZERO:
        // printf("FE_ZERO (Arredondar para zero)\n");
        // break;

    default:
        printf("Modo desconhecido\n");
        break;
    }

    // Alterar o modo de arredondamento para FE_UPWARD
    fesetround(FE_UPWARD);
    printf("\nModo de arredondamento alterado para: FE_UPWARD (Arredondar para cima)\n");

    // Realizar uma operação de ponto flutuante para demonstrar o arredondamento
    double result = 2.5 / 3.0; // O resultado é 0.833333...
    printf("Resultado de 2.5 / 3.0 (arredondado): %.10f\n", result);

    // Alterar o modo de arredondamento para FE_DOWNWARD
    fesetround(FE_DOWNWARD);
    printf("\nModo de arredondamento alterado para: FE_DOWNWARD (Arredondar para baixo)\n");

    // Realizar a mesma operação para ver o efeito do novo modo de arredondamento
    result = 2.5 / 3.0; // O resultado ainda é 0.833333...
    printf("Resultado de 2.5 / 3.0 (arredondado): %.10f\n", result);

    // Alterar o modo de arredondamento para FE_TONEAREST
    fesetround(FE_TONEAREST);
    printf("\nModo de arredondamento alterado para: FE_TONEAREST (Arredondar para o número mais próximo)\n");

    // Realizar a mesma operação novamente
    result = 2.5 / 3.0; // O resultado ainda é 0.833333...
    printf("Resultado de 2.5 / 3.0 (arredondado): %.10f\n", result);
}

void test_fenv_operations()
{
    fenv_t env_current, env_new;

    // 1. Obtém o estado atual do ambiente de ponto flutuante
    if (fegetenv(&env_current) == 0)
    {
        printf("Estado atual do ambiente de ponto flutuante obtido com sucesso.\n");
    }
    else
    {
        printf("Falha ao obter o estado do ambiente de ponto flutuante.\n");
        return;
    }

    // 2. Modificando o estado: Levanta uma exceção de ponto flutuante (ex: divisão por zero)
    feraiseexcept(FE_DIVBYZERO);
    printf("Exceção de divisão por zero foi levantada.\n");

    // Verificando se a exceção foi levantada
    if (fetestexcept(FE_DIVBYZERO))
    {
        printf("Exceção de divisão por zero está ativa.\n");
    }
    else
    {
        printf("Exceção de divisão por zero não está ativa.\n");
    }

    // 3. Mantém as exceções pendentes usando feholdexcept
    feholdexcept(&env_new); // Mantém as exceções pendentes no ambiente de ponto flutuante
    printf("Exceções pendentes foram armazenadas e o ambiente foi congelado.\n");

    // Verificando se as exceções ainda estão ativas após feholdexcept
    if (fetestexcept(FE_DIVBYZERO))
    {
        printf("Exceção de divisão por zero ainda está ativa.\n");
    }
    else
    {
        printf("Exceção de divisão por zero foi "
               "desabilitada após feholdexcept.\n");
    }

    // 4. Atualiza o estado do ambiente de ponto flutuante
    feupdateenv(&env_current); // Atualiza o estado com o que foi obtido anteriormente
    printf("Estado do ambiente de ponto flutuante foi atualizado.\n");

    // Verificando se as exceções ainda estão ativas após feupdateenv
    if (fetestexcept(FE_DIVBYZERO))
    {
        printf("Exceção de divisão por zero está ativa após feupdateenv.\n");
    }
    else
    {
        printf("Exceção de divisão por zero não está ativa após feupdateenv.\n");
    }

    // 5. Definindo um novo estado de ambiente de ponto flutuante
    if (fesetenv(&env_new) == 0)
    {
        printf("Estado do ambiente de ponto flutuante foi redefinido.\n");
    }
    else
    {
        printf("Falha ao redefinir o estado do ambiente de ponto flutuante.\n");
    }

    // Verificando se o estado foi alterado corretamente
    if (fetestexcept(FE_DIVBYZERO))
    {
        printf("Exceção de divisão por zero ainda está ativa após fesetenv.\n");
    }
    else
    {
        printf("Exceção de divisão por zero foi "
               "limpa após fesetenv.\n");
    }
}

int main(int argc, char **argv)
{
    // Variável de ambiente
    fenv_t env;

    // Inicializa a variável de ambiente
    fegetenv(&env);

    // Imprime o status da variável de ambiente de ponto flutuante
    printf("Status da variável de ambiente de ponto flutuante: %d\n", fegetround());

    // Libera a variável de ambiente
    fesetenv(&env);

    printf("---------------------------------\n");

    // Testa as exceções de ponto flutuante
    printf("\nTestando exceções de ponto flutuante:\n");
    test_fenv_exception();

    printf("----------------------------------\n");
    printf("\nTestando modos de arredondamento:\n");

    // Testa os modos de arredondamento
    test_rounding_modes();

    printf("----------------------------------\n");
    printf("\nTestando operações de fenv:\n");

    // Testa as operações de fenv
    test_fenv_operations();
    return 0;
}
