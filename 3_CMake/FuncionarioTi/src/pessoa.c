#include "pessoa.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Pessoa *criar_pessoa(const char *nome, int idade, float salario, NivelExperiencia nivel)
{
    Pessoa *p = malloc(sizeof(Pessoa));
    if (!p)
    {
        log_erro("Erro na alocação de memória para Pessoa");
        return NULL;
    }

    string_segura_copiar(p->nome, sizeof(p->nome), nome);
    p->idade = idade;
    p->salario = salario;
    p->nivel = nivel;
    p->dados_processador = NULL; // Inicializar o novo campo

    log_info("Pessoa criada com sucesso");
    return p;
}

void destruir_pessoa(Pessoa *p)
{
    if (p)
    {
        free(p);
        log_info("Pessoa destruída com sucesso");
    }
}

void imprimir_pessoa(const Pessoa *p)
{
    if (!validar_pessoa(p))
    {
        log_erro("Tentativa de imprimir pessoa inválida");
        return;
    }

    printf("Nome: %s, Idade: %d, Salário: %.2f, Nível: %s\n",
           p->nome, p->idade, p->salario, nivel_para_string(p->nivel));
}

void processar_array(Pessoa pessoas[], size_t tamanho, Processador callback)
{
    if (!callback)
    {
        log_erro("Callback inválido para processar_array");
        return;
    }

    for (size_t i = 0; i < tamanho; i++)
    {
        if (validar_pessoa(&pessoas[i]))
        {
            callback(&pessoas[i]);
        }
    }
}

void promover_pessoa(Pessoa *p)
{
    if (!validar_pessoa(p))
        return;

    if (p->nivel < SENIOR)
    {
        p->nivel++;
        p->salario *= 1.1f; // Aumento de 10% no salário
        log_info("Pessoa promovida com sucesso");
    }
}

Pessoa *clonar_pessoa(const Pessoa *original)
{
    if (!validar_pessoa(original))
        return NULL;

    Pessoa *copia = criar_pessoa(original->nome, original->idade,
                                 original->salario, original->nivel);
    return copia;
}

Pessoa *criar_array_pessoas(size_t tamanho)
{
    if (tamanho == 0)
    {
        log_erro("Tamanho do array deve ser maior que zero");
        return NULL;
    }

    Pessoa *array = calloc(tamanho, sizeof(Pessoa));
    if (!array)
    {
        log_erro("Falha ao alocar array de pessoas");
        return NULL;
    }

    return array;
}

// Função auxiliar para comparação de nomes (usada na ordenação)
static int comparar_nomes(const void *a, const void *b)
{
    const Pessoa *pa = (const Pessoa *)a;
    const Pessoa *pb = (const Pessoa *)b;
    return strcmp(pa->nome, pb->nome);
}

// Função auxiliar para comparação de salários (usada na ordenação)
static int comparar_salarios(const void *a, const void *b)
{
    const Pessoa *pa = (const Pessoa *)a;
    const Pessoa *pb = (const Pessoa *)b;

    if (pa->salario < pb->salario)
        return -1;

    if (pa->salario > pb->salario)
        return 1;
    return 0;
}

void ordenar_pessoas_por_nome(Pessoa pessoas[], size_t tamanho)
{
    qsort(pessoas, tamanho, sizeof(Pessoa), comparar_nomes);
}

void ordenar_pessoas_por_salario(Pessoa pessoas[], size_t tamanho)
{
    qsort(pessoas, tamanho, sizeof(Pessoa), comparar_salarios);
}