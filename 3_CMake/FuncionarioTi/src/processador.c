#include "processador.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// Processador de impressão
static void processar_impressao(Pessoa *p)
{
    if (p)
    {
        printf("Processando impressão: ");
        imprimir_pessoa(p);
    }
}

static void finalizar_impressao(void)
{
    printf("Processador de impressão finalizado.\n");
}

ProcessadorPessoas criar_processador_impressao(void)
{
    ProcessadorPessoas proc = {
        .processar = processar_impressao,
        .finalizar = finalizar_impressao};
    return proc;
}

// Processador de aumento salarial
typedef struct
{
    float percentual;
} DadosAumento;

static void processar_aumento_salario(Pessoa *p)
{
    if (p)
    {
        DadosAumento *dados = (DadosAumento *)p->dados_processador;
        p->salario *= (1 + dados->percentual / 100.0f);
        printf("Salário ajustado: %.2f (+%.1f%%)\n", p->salario, dados->percentual);
    }
}

static void finalizar_aumento_salario(void)
{
    printf("Processador de aumento salarial finalizado.\n");
}

ProcessadorPessoas criar_processador_aumento_salario(float percentual)
{
    DadosAumento *dados = malloc(sizeof(DadosAumento));
    dados->percentual = percentual;

    ProcessadorPessoas proc = {
        .processar = processar_aumento_salario,
        .finalizar = finalizar_aumento_salario,
        .dados = dados};
    return proc;
}

// Processador de log
static void processar_log(Pessoa *p)
{
    if (p)
    {
        log_info("Processando pessoa via log");
        printf("Log: %s - %d anos - R$ %.2f - %s\n",
               p->nome, p->idade, p->salario, nivel_para_string(p->nivel));
    }
}

static void finalizar_log(void) { log_info("Processador de log finalizado"); }

ProcessadorPessoas criar_processador_log(void)
{
    ProcessadorPessoas proc = {
        .processar = processar_log,
        .finalizar = finalizar_log};
    return proc;
}

// Função para liberar recursos do processador
void liberar_processador(ProcessadorPessoas *proc)
{
    if (proc && proc->dados)
    {
        free(proc->dados);
        proc->dados = NULL;
    }
}