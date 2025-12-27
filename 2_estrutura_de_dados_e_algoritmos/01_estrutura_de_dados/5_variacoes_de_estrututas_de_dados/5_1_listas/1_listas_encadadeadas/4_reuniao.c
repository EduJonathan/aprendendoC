#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/**
 * @brief Estrutura para armazenar data e hora usando time.h
 */
typedef struct
{
    time_t timestamp;    /**< Timestamp em formato time_t para fácil manipulação */
    char descricao[100]; /**< Descrição formatada da data/hora */
} DataHora;

/**
 * @brief Estrutura para representar um evento
 */
typedef struct
{
    char nome[100];     /**< Nome do evento */
    DataHora data_hora; /**< Data e hora do evento */
} Evento;

/**
 * @brief Estrutura do nó da lista encadeada genérica
 */
typedef struct No
{
    void *dados;          /**< Ponteiro genérico para qualquer tipo de dado */
    size_t tamanho_dados; /**< Tamanho dos dados para gerenciamento de memória */
    char tipo;            /**< Tipo do dado ('e' para evento, 'i' para inteiro, etc.) */
    struct No *proximo;   /**< Ponteiro para o próximo nó */
} No;

/**
 * @brief Estrutura da lista encadeada
 */
typedef struct
{
    No *cabeca;     /**< Ponteiro para o primeiro nó da lista */
    size_t tamanho; /**< Quantidade de elementos na lista */
} ListaEncadeada;

/**
 * @brief Cria uma nova lista encadeada vazia
 *
 * @return Ponteiro para a lista criada
 */
ListaEncadeada *criar_lista()
{
    ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if (lista == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a lista\n");
        return NULL;
    }
    lista->cabeca = NULL;
    lista->tamanho = 0;
    return lista;
}

/**
 * @brief Converte uma estrutura tm para DataHora
 *
 * @param tempo Estrutura tm com a data/hora
 * @param descricao Descrição opcional (pode ser NULL)
 * @return Estrutura DataHora preenchida
 */
DataHora criar_data_hora(struct tm tempo, const char *descricao)
{
    DataHora dh;
    dh.timestamp = mktime(&tempo);

    if (descricao != NULL)
    {
        strncpy(dh.descricao, descricao, sizeof(dh.descricao) - 1);
        dh.descricao[sizeof(dh.descricao) - 1] = '\0';
    }
    else
    {
        strftime(dh.descricao, sizeof(dh.descricao), "%d/%m/%Y %H:%M", localtime(&dh.timestamp));
    }
    return dh;
}

/**
 * @brief Cria um novo evento
 *
 * @param nome Nome do evento
 * @param tempo Estrutura tm com a data/hora do evento
 * @return Evento criado
 */
Evento criar_evento(const char *nome, struct tm tempo)
{
    Evento evento;
    strncpy(evento.nome, nome, sizeof(evento.nome) - 1);
    evento.nome[sizeof(evento.nome) - 1] = '\0';
    evento.data_hora = criar_data_hora(tempo, NULL);
    return evento;
}

/**
 * @brief Cria um novo nó com dados genéricos
 *
 * @param dados Ponteiro para os dados
 * @param tamanho Tamanho dos dados em bytes
 * @param tipo Tipo do dado
 * @return Ponteiro para o nó criado
 */
No *criar_no(void *dados, size_t tamanho, char tipo)
{
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o nó\n");
        return NULL;
    }

    novo_no->dados = malloc(tamanho);
    if (novo_no->dados == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para os dados\n");
        free(novo_no);
        return NULL;
    }
    memcpy(novo_no->dados, dados, tamanho);
    novo_no->tamanho_dados = tamanho;
    novo_no->tipo = tipo;
    novo_no->proximo = NULL;
    return novo_no;
}

/**
 * @brief Insere um elemento no início da lista
 *
 * @param lista Lista onde o elemento será inserido
 * @param dados Ponteiro para os dados
 * @param tamanho Tamanho dos dados em bytes
 * @param tipo Tipo do dado
 * @return 1 em caso de sucesso, 0 em caso de erro
 */
int inserir_elemento(ListaEncadeada *lista, void *dados, size_t tamanho, char tipo)
{
    if (lista == NULL || dados == NULL)
    {
        fprintf(stderr, "Parâmetros inválidos\n");
        return 0;
    }

    No *novo_no = criar_no(dados, tamanho, tipo);
    if (novo_no == NULL)
    {
        return 0;
    }
    novo_no->proximo = lista->cabeca;
    lista->cabeca = novo_no;
    lista->tamanho++;
    return 1;
}

/**
 * @brief Exibe um evento
 *
 * @param dados Ponteiro para os dados do evento
 */
void exibir_evento(void *dados)
{
    Evento *evento = (Evento *)dados;
    printf("Evento: %-30s | Horario: %s\n", evento->nome, evento->data_hora.descricao);
}

/**
 * @brief Exibe um inteiro
 *
 * @param dados Ponteiro para o inteiro
 */
void exibir_inteiro(void *dados)
{
    int *valor = (int *)dados;
    printf("Valor inteiro: %d\n", *valor);
}

/**
 * @brief Exibe um float
 *
 * @param dados Ponteiro para o float
 */
void exibir_float(void *dados)
{
    float *valor = (float *)dados;
    printf("Valor float: %.2f\n", *valor);
}

/**
 * @brief Função genérica para exibir a lista
 *
 * @param lista Lista a ser exibida
 * @param exibir_dado Função específica para exibir cada tipo de dado
 */
void exibir_lista(ListaEncadeada *lista, void (*exibir_dado)(void *))
{
    if (lista == NULL || exibir_dado == NULL)
    {
        fprintf(stderr, "Parâmetros inválidos\n");
        return;
    }

    No *atual = lista->cabeca;
    if (atual == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nConteúdo da lista (%zu elementos):\n", lista->tamanho);
    printf("============================================\n");

    while (atual != NULL)
    {
        exibir_dado(atual->dados);
        atual = atual->proximo;
    }
    printf("============================================\n");
}

/**
 * @brief Exibe a lista identificando automaticamente os tipos
 * 
 * @param lista Lista a ser exibida
 */
void exibir_lista_automatico(ListaEncadeada *lista)
{
    if (lista == NULL)
    {
        fprintf(stderr, "Lista inválida\n");
        return;
    }

    No *atual = lista->cabeca;
    if (atual == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nLista com identificação automática de tipos:\n");
    printf("============================================\n");

    while (atual != NULL)
    {
        switch (atual->tipo)
        {
        case 'e': // Evento
            exibir_evento(atual->dados);
            break;

        case 'i': // Inteiro
            exibir_inteiro(atual->dados);
            break;

        case 'f': // Float
            exibir_float(atual->dados);
            break;

        default:
            printf("Tipo desconhecido\n");
            break;
        }
        atual = atual->proximo;
    }
    printf("============================================\n");
}

/**
 * @brief Libera a memória da lista
 * 
 * @param lista Lista a ser liberada
 */
void liberar_lista(ListaEncadeada *lista)
{
    if (lista == NULL)
        return;

    No *atual = lista->cabeca;
    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->proximo;
        free(temp->dados);
        free(temp);
    }
    free(lista);
}

int main(int argc, char **argv)
{
    // Configurar locale para caracteres em português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Criar lista
    ListaEncadeada *lista = criar_lista();
    if (lista == NULL)
    {
        return 1;
    }

    // Criar eventos usando time.h
    struct tm tempo1 = {0};
    tempo1.tm_year = 125; // 2025 - 1900
    tempo1.tm_mon = 8;    // Setembro (0-11)
    tempo1.tm_mday = 21;
    tempo1.tm_hour = 10;
    tempo1.tm_min = 30;

    struct tm tempo2 = {0};
    tempo2.tm_year = 125;
    tempo2.tm_mon = 8;
    tempo2.tm_mday = 22;
    tempo2.tm_hour = 14;
    tempo2.tm_min = 0;

    // Criar e adicionar eventos
    Evento evento1 = criar_evento("Reunião de equipe", tempo1);
    Evento evento2 = criar_evento("Planejamento mensal", tempo2);
    Evento evento3 = criar_evento("Apresentação de resultados",
                                  (struct tm){.tm_year = 125, .tm_mon = 8, .tm_mday = 25, .tm_hour = 9, .tm_min = 0});

    inserir_elemento(lista, &evento1, sizeof(Evento), 'e');
    inserir_elemento(lista, &evento2, sizeof(Evento), 'e');
    inserir_elemento(lista, &evento3, sizeof(Evento), 'e');

    // Adicionar outros tipos de dados
    int valor_int = 42;
    float valor_float = 3.14159f;

    inserir_elemento(lista, &valor_int, sizeof(int), 'i');
    inserir_elemento(lista, &valor_float, sizeof(float), 'f');

    // Exibir lista de diferentes formas
    printf("=== EXIBIÇÃO ESPECÍFICA ===\n");
    exibir_lista(lista, exibir_evento);

    printf("\n=== EXIBIÇÃO AUTOMÁTICA ===\n");
    exibir_lista_automatico(lista);

    // Demonstrar funcionalidades de time.h
    printf("\n=== INFORMAÇÕES DE DATA/HORA ===\n");
    time_t agora = time(NULL);
    printf("Data/hora atual: %s", ctime(&agora));

    // Calcular diferença entre eventos
    double diff_segundos = difftime(evento2.data_hora.timestamp, evento1.data_hora.timestamp);
    printf("Diferença entre evento1 e evento2: %.0f segundos (%.1f horas)\n",
           diff_segundos, diff_segundos / 3600);

    // Liberar memória
    liberar_lista(lista);

    printf("\nPrograma executado com sucesso!\n");
    return 0;
}
