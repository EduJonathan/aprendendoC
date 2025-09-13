#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "utils.h"
#include "processador.h"

// Função de callback exemplo
void aumentar_salario_10(Pessoa *p)
{
    if (p)
    {
        p->salario *= 1.1f;
        printf("Salario aumentado para: %.2f\n", p->salario);
    }
}

// Função para demonstrar _Generic
void demonstrar_generic(void)
{
    printf("\n=== Demonstracao _Generic ===\n");
    PRINT_VALUE(42);
    PRINT_VALUE(3.14f);
    PRINT_VALUE(2.71828);
    PRINT_VALUE("Texto de exemplo");
}

// Função para demonstrar array de pessoas
void demonstrar_array_pessoas(void)
{
    printf("\n=== Demonstração Array de Pessoas ===\n");

    // Criar array de pessoas usando inicialização composta
    Pessoa equipe[] = {
        {"Maria Santos", 25, 4500.00f, JUNIOR, NULL},
        {"Pedro Costa", 35, 6000.00f, PLENO, NULL},
        {"Ana Oliveira", 28, 4800.00f, PLENO, NULL},
        {"Joao Silva", 42, 8500.00f, SENIOR, NULL}};

    const size_t num_membros = ARRAY_SIZE(equipe);

    printf("Equipe original:\n");
    for (size_t i = 0; i < num_membros; i++)
    {
        imprimir_pessoa(&equipe[i]);
    }

    // Ordenar por nome
    ordenar_pessoas_por_nome(equipe, num_membros);
    printf("\nEquipe ordenada por nome:\n");
    for (size_t i = 0; i < num_membros; i++)
    {
        imprimir_pessoa(&equipe[i]);
    }

    // Ordenar por salário
    ordenar_pessoas_por_salario(equipe, num_membros);
    printf("\nEquipe ordenada por salario:\n");
    for (size_t i = 0; i < num_membros; i++)
    {
        imprimir_pessoa(&equipe[i]);
    }
}

void demonstrar_processadores(void)
{
    printf("\n=== Demonstração Processadores ===\n");

    Pessoa equipe[] = {
        {"Maria Silva", 28, 5000.00f, JUNIOR, NULL},
        {"Joao Santos", 35, 7000.00f, PLENO, NULL},
        {"Ana Costa", 42, 9000.00f, SENIOR, NULL}};

    const size_t num_membros = ARRAY_SIZE(equipe);

    // Processador de impressão
    printf("\n1. Processador de Impressao:\n");
    ProcessadorPessoas impressor = criar_processador_impressao();
    for (size_t i = 0; i < num_membros; i++)
    {
        impressor.processar(&equipe[i]);
    }
    impressor.finalizar();

    // Processador de aumento salarial
    printf("\n2. Processador de Aumento Salarial (15%%):\n");
    ProcessadorPessoas aumentador = criar_processador_aumento_salario(15.0f);
    for (size_t i = 0; i < num_membros; i++)
    {
        equipe[i].dados_processador = aumentador.dados;
        aumentador.processar(&equipe[i]);
        equipe[i].dados_processador = NULL; // Limpar após uso
    }
    aumentador.finalizar();

    // Processador de log
    printf("\n3. Processador de Log:\n");
    ProcessadorPessoas logger = criar_processador_log();
    for (size_t i = 0; i < num_membros; i++)
    {
        logger.processar(&equipe[i]);
    }
    logger.finalizar();

    // Liberar recursos
    liberar_processador(&aumentador);

    // Mostrar resultado final
    printf("\nResultado final apos processamentos:\n");
    for (size_t i = 0; i < num_membros; i++)
    {
        imprimir_pessoa(&equipe[i]);
    }
}

int main(void)
{
    printf("=== Sistema de Gerenciamento de Pessoas ===\n");

    // Demonstrar criação de pessoa
    Pessoa *pessoa1 = criar_pessoa("Carlos Eduardo", 32, 5500.00f, PLENO);
    if (pessoa1)
    {
        imprimir_pessoa(pessoa1);

        // Promover pessoa
        promover_pessoa(pessoa1);
        printf("Após promoção:\n");
        imprimir_pessoa(pessoa1);

        // Clonar pessoa
        Pessoa *clone = clonar_pessoa(pessoa1);
        if (clone)
        {
            printf("Clone da pessoa:\n");
            imprimir_pessoa(clone);
            destruir_pessoa(clone);
        }

        destruir_pessoa(pessoa1);
    }

    // Demonstrar array de pessoas
    demonstrar_array_pessoas();

    // Demonstrar processadores
    demonstrar_processadores();

    // Demonstrar _Generic
    demonstrar_generic();

    // Demonstrar processamento com callback
    printf("\n=== Demonstração Callback ===\n");
    Pessoa equipe[] = {
        {"Maria Silva", 28, 5000.00f, JUNIOR, NULL},
        {"João Santos", 35, 7000.00f, PLENO, NULL}};

    processar_array(equipe, ARRAY_SIZE(equipe), aumentar_salario_10);

    printf("\nApós aumento de salario:\n");
    for (size_t i = 0; i < ARRAY_SIZE(equipe); i++)
    {
        imprimir_pessoa(&equipe[i]);
    }

    return EXIT_SUCCESS;
}
