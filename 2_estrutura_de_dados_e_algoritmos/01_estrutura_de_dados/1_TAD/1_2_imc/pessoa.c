#include <math.h>
#include <string.h>
#include "pessoa.h"

/**
 * @brief Estrutura auxiliar para mapear intervalos de IMC a descrições.
 */
struct IMCCategoria
{
    float limite;          ///< Limite superior do intervalo de IMC
    const char *descricao; ///< Descrição da categoria
};

/**
 * @brief Tabela de categorias de IMC.
 */
static const struct IMCCategoria categorias[] = {
    {18.5, "Abaixo do peso"},
    {25.0, "Peso normal"},
    {30.0, "Sobrepeso"},
    {35.0, "Obesidade grau I"},
    {40.0, "Obesidade grau II"},
    {INFINITY, "Obesidade grau III"}}; // Ou FP_INFINITE

bool setPessoa(struct Pessoa *pessoa, const char *nome, unsigned idade, float altura, float peso)
{
    if (!pessoa || !nome || altura <= 0 || peso <= 0 || strlen(nome) >= 100)
    {
        printf("Erro: Parâmetros inválidos.\n");
        return false;
    }
    strncpy(pessoa->nome, nome, 99);
    pessoa->nome[99] = '\0'; // Garante terminação nula
    pessoa->idade = idade;
    pessoa->altura = altura;
    pessoa->peso = peso;
    return true;
}

void getPessoa(const struct Pessoa *pessoa)
{
    if (!pessoa)
    {
        printf("Erro: Pessoa inválida.\n");
        return;
    }
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %u\n", pessoa->idade);
    printf("Altura: %.2f m\n", pessoa->altura);
    printf("Peso: %.2f kg\n", pessoa->peso);
}

float calcularIMC(const struct Pessoa *pessoa)
{
    if (!pessoa || pessoa->altura <= 0 || pessoa->peso <= 0)
    {
        printf("Erro: Altura e peso devem ser maiores que zero.\n");
        return -1;
    }
    return pessoa->peso / pow(pessoa->altura, 2);
}

struct IMC classificarIMC(const struct Pessoa *pessoa)
{
    struct IMC imc = {.valor = -1, .descricao = "Erro"};

    if (!pessoa)
    {
        printf("Erro: Pessoa inválida.\n");
        return imc;
    }

    float imc_val = calcularIMC(pessoa);
    imc.valor = imc_val;

    if (imc_val == -1)
    {
        strncpy(imc.descricao, "Erro no cálculo do IMC", 49);
    }
    else
    {
        for (size_t i = 0; i < sizeof(categorias) / sizeof(categorias[0]); i++)
        {
            if (imc_val < categorias[i].limite)
            {
                strncpy(imc.descricao, categorias[i].descricao, 49);
                break;
            }
        }
    }

    imc.descricao[49] = '\0'; // Garante terminação nula
    return imc;
}

void imprimirIMC(const struct Pessoa *pessoa)
{
    if (!pessoa)
    {
        printf("Erro: Pessoa inválida.\n");
        return;
    }

    struct IMC imc = classificarIMC(pessoa);

    if (imc.valor != -1)
    {
        printf("IMC de %s: %.2f (%s)\n", pessoa->nome, imc.valor, imc.descricao);
    }
}

bool verificarObesidade(const struct Pessoa *pessoa)
{
    if (!pessoa)
    {
        return false;
    }
    float imc = calcularIMC(pessoa);
    return imc >= 30;
}

void imprimirObesidade(const struct Pessoa *pessoa)
{
    if (!pessoa)
    {
        printf("Erro: Pessoa inválida.\n");
        return;
    }

    if (verificarObesidade(pessoa))
    {
        printf("%s está obeso(a).\n", pessoa->nome);
    }
    else
    {
        printf("%s não está obeso(a).\n", pessoa->nome);
    }
}
