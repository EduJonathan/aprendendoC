#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/** @struct FoodOrder
 *  @brief Representa um pedido de comida.
 */
typedef struct
{
    char *dishName; /**< Nome do prato */
    int prepTime;   /**< Tempo de preparo em minutos */
} FoodOrder;

/** @struct DrinkOrder
 *  @brief Representa um pedido de bebida.
 */
typedef struct
{
    char *drinkName; /**< Nome da bebida */
    char *size;      /**< Tamanho: "Pequeno", "Médio" ou "Grande" */
} DrinkOrder;

/** @struct Node
 *  @brief Nó do Deque, armazena ponteiro genérico para um pedido.
 */
typedef struct node
{
    void *data;        /**< Ponteiro genérico para FoodOrder ou DrinkOrder */
    char *type;        /**< Identifica o tipo do pedido ("Food" ou "Drink") */
    struct node *next; /**< Próximo nó */
    struct node *prev; /**< Nó anterior */
} Node;

/** @struct Deque
 *  @brief Estrutura principal do Deque (duplamente encadeado).
 */
typedef struct deque
{
    Node *front; /**< Ponteiro para o primeiro nó */
    Node *rear;  /**< Ponteiro para o último nó */
    int size;    /**< Quantidade de nós */
} Deque;

/**
 * @brief Cria um Deque vazio.
 * @return Ponteiro para o Deque criado.
 */
Deque *createDeque(void)
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}

/**
 * @brief Adiciona um pedido no início do Deque (VIP).
 *
 * @param deque Ponteiro para o Deque.
 * @param data  Ponteiro genérico para o pedido.
 * @param type  String que identifica o tipo ("Food" ou "Drink").
 */
void pushFront(Deque *deque, void *data, char *type)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->type = strdup(type);
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (deque->size == 0)
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    deque->size++;
}

/**
 * @brief Adiciona um pedido no fim do Deque (regular).
 *
 * @param deque Ponteiro para o Deque.
 * @param data  Ponteiro genérico para o pedido.
 * @param type  String que identifica o tipo ("Food" ou "Drink").
 */
void pushRear(Deque *deque, void *data, char *type)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->type = strdup(type);
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (deque->size == 0)
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    deque->size++;
}

/**
 * @brief Remove um pedido do início do Deque.
 * @param deque Ponteiro para o Deque.
 * @param type  Ponteiro para receber o tipo do pedido removido.
 * @return Ponteiro genérico para o pedido removido.
 */
void *popFront(Deque *deque, char **type)
{
    if (deque->size == 0)
    {
        printf("Nenhum pedido no Deque!\n");
        *type = NULL;
        return NULL;
    }

    Node *temp = deque->front;
    void *data = temp->data;
    *type = temp->type;

    deque->front = temp->next;
    if (deque->front != NULL)
    {
        deque->front->prev = NULL;
    }
    else
    {
        deque->rear = NULL;
    }

    free(temp);
    deque->size--;
    return data;
}

/**
 * @brief Libera toda a memória do Deque.
 * @param deque Ponteiro para o Deque.
 */
void freeDeque(Deque *deque)
{
    char *type = NULL;
    while (deque->size > 0)
    {
        void *data = popFront(deque, &type);
        if (data != NULL)
        {
            free(type);
            /*
             * Atenção: aqui não liberamos 'data' porque, neste exemplo,
             * ele aponta para variáveis locais. Se você alocar dinamicamente
             * cada pedido, deve liberar também.
             */
        }
    }
    free(deque);
}

/**
 * @brief Processa e exibe um pedido, de acordo com o tipo.
 * @param data Ponteiro genérico para o pedido.
 * @param type String com o tipo do pedido.
 */
void processOrder(void *data, char *type)
{
    if (strcmp(type, "Food") == 0)
    {
        FoodOrder *food = (FoodOrder *)data;
        printf("Processando pedido de comida: %s (Tempo: %d minutos)\n", food->dishName, food->prepTime);
    }
    else if (strcmp(type, "Drink") == 0)
    {
        DrinkOrder *drink = (DrinkOrder *)data;
        printf("Processando pedido de bebida: %s (%s)\n", drink->drinkName, drink->size);
    }
}

int main(int argc, char **argv)
{
    // Configurar locale para caracteres em português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    /* Semente para futuras funcionalidades que usem rand/time */
    srand((unsigned)time(NULL));

    Deque *orders = createDeque();

    FoodOrder food1 = {"Pizza Margherita", 15};
    FoodOrder food2 = {"Hambúrguer", 10};

    DrinkOrder drink1 = {"Coca-Cola", "Médio"};
    DrinkOrder drink2 = {"Suco de Laranja", "Grande"};

    printf("Adicionando pedidos...\n");
    pushFront(orders, &food1, "Food");
    pushRear(orders, &drink1, "Drink");
    pushFront(orders, &food2, "Food");
    pushRear(orders, &drink2, "Drink");

    printf("\nProcessando pedidos do início (VIP):\n");
    char *type = NULL;
    while (orders->size > 0)
    {
        void *order = popFront(orders, &type);
        if (order != NULL)
        {
            processOrder(order, type);
            free(type);
        }
    }

    freeDeque(orders);
    return 0;
}
