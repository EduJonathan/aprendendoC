#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/**
 * Níveis de ponteiros (*, **, ***) em RETORNOS de funções
 *
 * Retorne `struct s *` quando:
 * - A função cria ou retorna um nó específico (ex.: novo nó criado com malloc,
 *   nó encontrado em uma busca, ou a cabeça de uma lista já existente).
 * - O chamador só precisa acessar os dados do nó ou percorrer a lista a partir dele.
 *
 * ------------------------------------------------------------
 *
 * Retorne `struct s **` quando:
 * - A função precisa devolver um ponteiro que o chamador poderá modificar.
 *   Exemplo: retornar a referência à cabeça de uma lista para que quem chama
 *   possa alterar qual nó é a cabeça.
 * - Situação comum: funções que manipulam estruturas que armazenam internamente
 *   um ponteiro para outra estrutura (ex.: "ponteiro para a cabeça" guardado
 *   em outra variável ou struct).
 *
 * ------------------------------------------------------------
 *
 * Retorne `struct s ***` quando:
 * - A função precisa devolver um nível ainda mais profundo de indireção,
 *   geralmente quando existe um campo do tipo `struct s **head` dentro
 *   de outra estrutura.
 * - Casos assim são raros; normalmente indicam estruturas muito aninhadas
 *   (lista de listas, matriz dinâmica de listas, etc).
 *
 * ------------------------------------------------------------
 *
 * Considerações importantes:
 * - Prefira a menor indireção possível: retornar `struct s ***` quase sempre
 *   é sinal de que a estrutura de dados ou a lógica poderia ser simplificada.
 *
 * - Muitas vezes é melhor passar ponteiros como parâmetro do que retorná-los.
 *   Exemplo: `void inserir(struct s **cabeca, int valor)` é mais comum e
 *   mais claro do que retornar um `struct s **`.
 *
 * - Propriedade da memória: se a função aloca memória com `malloc`, o retorno
 *   deve corresponder ao nível de indireção alocado.
 *
 * Exemplo:
 * malloc(sizeof(struct s))    → retorna `struct s *`
 * malloc(sizeof(struct s *))  → retorna `struct s **`
 */

struct s
{
    int valor;
    struct s *proximo;
};

struct lista
{
    struct s **cabeca;
};

// Cria nó (*)
struct s *criar_no(int valor)
{
    struct s *novo = malloc(sizeof(struct s));
    if (!novo)
    {
        fprintf(stderr, "Erro: falha ao alocar memória para novo nó\n");
        return NULL;
    }
    novo->valor = valor;
    novo->proximo = NULL;
    printf("[criar_no *] Nó em %p | valor=%d | prox=%p\n", (void *)novo, novo->valor, (void *)novo->proximo);
    return novo;
}

// Insere no início (**)
struct s **inserir_inicio(struct s **cabeca, int valor)
{
    struct s *novo = criar_no(valor);
    novo->proximo = *cabeca;
    *cabeca = novo;

    printf("[inserir_inicio **] Nova cabeça: %p -> %d\n", (void *)*cabeca, (*cabeca)->valor);

    // Diagrama da lista
    printf("Encadeamento (**):\n");
    struct s *temp = *cabeca;
    while (temp)
    {
        printf("  [%p | %d] -> ", (void *)temp, temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
    return cabeca;
}

// Inicializa lista (***)
struct s ***inicializar_lista(struct lista *l)
{
    l->cabeca = malloc(sizeof(struct s *));
    if (!l->cabeca)
        exit(1);
    *(l->cabeca) = NULL;

    printf("[inicializar_lista ***] Lista em %p | cabeca=%p -> %p\n",
           (void *)l, (void *)l->cabeca, (void *)*(l->cabeca));
    return &(l->cabeca);
}

// Libera lista
void liberar_lista(struct s *cabeca)
{
    while (cabeca)
    {
        struct s *temp = cabeca;
        cabeca = cabeca->proximo;
        printf("[liberar] Nó %p (valor=%d) liberado\n", (void *)temp, temp->valor);
        free(temp);
    }
}

// Função para mostrar visualmente níveis de indireção
void mostrar_indirecao(struct s *lista, struct s **ptr2, struct s ***ptr3)
{
    printf("\n===== VISUALIZAÇÃO DE PONTEIROS =====\n");

    if (lista)
    {
        printf("* lista -> %p | valor=%d\n", (void *)lista, lista->valor);
    }
    else
    {
        printf("* lista -> NULL\n");
    }

    if (ptr2 && *ptr2)
    {
        printf("** ptr2 -> %p | valor = %d\n", (void *)*ptr2, (*ptr2)->valor);
    }
    else
    {
        printf("** ptr2 -> NULL\n");
    }

    if (ptr3 && *ptr3 && **ptr3)
    {
        printf("*** ptr3 -> %p | valor = %d\n", (void *)**ptr3, (**ptr3)->valor);
    }
    else
    {
        printf("*** ptr3 -> NULL\n");
    }

    printf("\nDiagrama de memória:\n");
    if (lista)
    {
        printf("lista (*) : %p -> [valor=%d | prox=%p]\n", (void *)lista, lista->valor, (void *)lista->proximo);
    }
    if (ptr2 && *ptr2)
    {
        printf("ptr2 (**) : %p -> *ptr2=%p -> valor=%d\n", (void *)ptr2, (void *)*ptr2, (*ptr2)->valor);
    }
    if (ptr3 && *ptr3 && **ptr3)
    {
        printf("ptr3 (***) : %p -> **ptr3=%p -> valor=%d\n", (void *)ptr3, (void *)**ptr3, (**ptr3)->valor);
    }
    printf("====================================\n\n");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    struct s *lista = NULL;
    struct lista minha_lista;

    // Criar e inserir nós
    lista = criar_no(10);
    inserir_inicio(&lista, 20);

    // Inicializar lista com ponteiro triplo
    struct s ***ptr_cabeca = inicializar_lista(&minha_lista);
    **ptr_cabeca = criar_no(30);

    // Mostrar visualmente os níveis de indireção
    struct s **ptr2 = &lista;
    mostrar_indirecao(lista, ptr2, ptr_cabeca);

    // Liberar memória
    liberar_lista(lista);
    liberar_lista(**ptr_cabeca);
    free(minha_lista.cabeca);

    return 0;
}
