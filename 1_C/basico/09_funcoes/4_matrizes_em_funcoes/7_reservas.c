#include <stdio.h>
#include <string.h>

#define MAX_RESERVAS 10  /**< Máximo de reservas na lista */
#define MAX_NOME 50      /**< Tamanho máximo de cada nome */
#define MAX_ATIVIDADE 30 /**< Tamanho máximo da atividade */
#define MAX_HORARIO 20   /**< Tamanho máximo do horário */

int num_reservas = 0; /**< Contador de reservas atuais */

/**
 * @brief Array de reservas, onde cada linha armazena um nome, atividade e horário
 *
 * A estrutura é [3] para Nome, Atividade, Horário. Cada linha contém:
 * - [0]: Nome do participante
 * - [1]: Atividade reservada
 * - [2]: Horário da reserva
 */
char reservas[MAX_RESERVAS][3][MAX_NOME] = {0}; /**< Array de reservas */

char (*ptrReservas)[3][MAX_NOME] = reservas; /**< Ponteiro para as reservas */

/**
 * @brief Função para adicionar uma reserva
 *
 * Esta função adiciona uma reserva à lista, copiando os dados de nome, atividade e horário.
 * Se o número de reservas atingir o máximo permitido, uma mensagem de erro é exibida.
 *
 * @param nome Nome do participante
 * @param atividade Atividade reservada
 * @param horario Horário da reserva
 */
void adicionar_reserva(const char *nome, const char *atividade, const char *horario)
{
    if (num_reservas < MAX_RESERVAS)
    {
        strcpy(ptrReservas[num_reservas][0], nome);      /**< Copia o nome do participante */
        strcpy(ptrReservas[num_reservas][1], atividade); /**< Copia a atividade */
        strcpy(ptrReservas[num_reservas][2], horario);   /**< Copia o horário da reserva */
        num_reservas++;
        printf("Reserva de '%s' para a atividade '%s' às %s adicionada!\n", nome, atividade, horario);
    }
    else
    {
        printf("Lista de reservas cheia! Não é possível adicionar a reserva de '%s'.\n", nome);
    }
}

/**
 * @brief Função para excluir uma reserva
 *
 * Esta função exclui a reserva de um participante. A exclusão é feita movendo as reservas
 * subsequentes para a posição anterior, "fechando a lacuna" deixada pela reserva excluída.
 *
 * @param nome Nome do participante cuja reserva será excluída
 */
void excluir_reserva(const char *nome)
{
    int encontrado = 0;

    // Procurando a reserva na lista
    for (int i = 0; i < num_reservas; i++)
    {
        if (strcmp(ptrReservas[i][0], nome) == 0)
        {
            encontrado = 1;

            // "Excluindo" a reserva (movendo os elementos para a esquerda)
            for (int j = i; j < num_reservas - 1; j++)
            {
                strcpy(ptrReservas[j][0], ptrReservas[j + 1][0]);
                strcpy(ptrReservas[j][1], ptrReservas[j + 1][1]);
                strcpy(ptrReservas[j][2], ptrReservas[j + 1][2]);
            }

            // Limpa a última reserva
            memset(ptrReservas[num_reservas - 1], 0, 3 * MAX_NOME);
            num_reservas--;
            printf("Reserva de '%s' excluída da lista.\n", nome);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Reserva de '%s' não encontrada.\n", nome);
    }
}

/**
 * @brief Função para imprimir a lista de reservas
 *
 * Esta função imprime todas as reservas na lista, mostrando nome, atividade e horário
 * de cada reserva. Se não houver reservas, uma mensagem indicando isso será exibida.
 */
void imprimir_reservas()
{
    printf("\nLista de Reservas:\n");
    if (num_reservas == 0)
    {
        printf("Nenhuma reserva na lista.\n");
    }
    else
    {
        for (int i = 0; i < num_reservas; i++)
        {
            printf("%d. %s - Atividade: %s - Horário: %s\n", i + 1, ptrReservas[i][0], ptrReservas[i][1], ptrReservas[i][2]);
        }
    }
}

int main(int argc, char **argv)
{
    // Testando as funções de reserva
    adicionar_reserva("Carlos", "Futebol", "14:00");
    adicionar_reserva("Ana", "Natação", "15:00");
    adicionar_reserva("João", "Academia", "16:00");
    adicionar_reserva("Maria", "Tênis", "17:00");

    // Exibe a lista inicial de reservas
    imprimir_reservas();

    // Exclui uma reserva
    excluir_reserva("Ana"); // Excluindo a reserva de Ana

    // Exibe a lista após exclusão
    imprimir_reservas();

    // Adiciona uma nova reserva
    adicionar_reserva("Pedro", "Futebol", "18:00");

    // Exibe a lista após adicionar Pedro
    imprimir_reservas();

    return 0;
}
