#ifndef AGENDA_H
#define AGENDA_H

#define TAMANHO_TABELA 101

/**
 * @brief Estrutura que representa um contato telefônico
 */
struct contato
{
    char nome[50];           /**< Nome do contato */
    char telefone[15];       /**< Número de telefone */
    struct contato *proximo; /**< Próximo contato na lista encadeada */
};

/**
 * @brief Estrutura principal da agenda telefônica
 */
struct agenda
{
    struct contato *tabela[TAMANHO_TABELA]; /**< Tabela hash de contatos */
};

// Protótipos das funções

/**
 * @brief Calcula o hash para um nome
 * @param nome Nome para calcular o hash
 * @return Índice na tabela hash
 */
unsigned int hash(const char *nome);

/**
 * @brief Cria um novo contato
 * @param nome Nome do contato
 * @param telefone Número do telefone
 * @return Ponteiro para o contato criado ou NULL em caso de erro
 */
struct contato *criar_contato(const char *nome, const char *telefone);

/**
 * @brief Inicializa uma nova agenda
 * @return Ponteiro para a agenda criada ou NULL em caso de erro
 */
struct agenda *inicializar_agenda();

/**
 * @brief Insere ou atualiza um contato na agenda
 * @param agenda Ponteiro para a agenda
 * @param nome Nome do contato
 * @param telefone Número do telefone
 * @return Ponteiro para o contato inserido/atualizado ou NULL em caso de erro
 */
struct contato *inserir_contato(struct agenda *agenda, const char *nome, const char *telefone);

/**
 * @brief Busca um contato na agenda
 * @param agenda Ponteiro para a agenda
 * @param nome Nome do contato a ser buscado
 * @return Ponteiro para o contato encontrado ou NULL se não encontrado
 */
struct contato *buscar_contato(struct agenda *agenda, const char *nome);

/**
 * @brief Remove um contato da agenda
 * @param agenda Ponteiro para a agenda
 * @param nome Nome do contato a ser removido
 * @return Ponteiro para o próximo contato na lista ou NULL se não encontrado
 */
struct contato **remover_contato(struct agenda *agenda, const char *nome);

/**
 * @brief Coleta todos os contatos da agenda ordenados por nome
 * @param agenda Ponteiro para a agenda
 * @param num_contatos Ponteiro para armazenar o número de contatos coletados
 * @return Array de ponteiros para contatos ordenados ou NULL em caso de erro
 */
struct contato **coletar_contatos(struct agenda *agenda, int *num_contatos);

/**
 * @brief Lista todos os contatos da agenda em ordem alfabética
 * @param agenda Ponteiro para a agenda
 */
void listar_contatos(struct agenda *agenda);

/**
 * @brief Libera toda a memória alocada para a agenda
 * @param agenda Ponteiro para a agenda a ser liberada
 */
void liberar_agenda(struct agenda *agenda);

#endif // AGENDA_H
