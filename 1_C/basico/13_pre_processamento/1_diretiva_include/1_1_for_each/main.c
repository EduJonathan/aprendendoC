#include "for_each.h"

// "": quando uma biblioteca .h está em "", significa que é diretório de projeto de sua máquina.
// <>: quando se encontra em abre '<' e fecha '>', significa que é uma biblioteca do compilador.

// Funções callback para a função for_each
void print_int(void *elem) { printf("%d ", *(int *)elem); }
void print_double(void *elem) { printf("%.2f ", *(double *)elem); }

void square_int(void *elem)
{
    int value = *(int *)elem;
    printf("%d ", value * value);
}

void for_each(void *arr, size_t size, void (*action)(void *), size_t size_elem)
{
    if (arr == NULL || size == 0 || action == NULL)
        return;

    for (size_t i = 0; i < size; i++)
    {
        action((char *)arr + i * size_elem);
    }
}

int main(int argc, char **argv)
{
    // Teste com array de inteiros
    int arr_int[] = {1, 2, 3, 4, 5};
    size_t size_int = sizeof(arr_int) / sizeof(arr_int[0]);

    printf("Teste com macro foreach (inteiros):\n");
    printf("Array: ");
    foreach(arr_int, size_int, printf("%d ", x));
    printf("\n");

    printf("Quadrados: ");
    foreach(arr_int, size_int, printf("%d ", x * x));
    printf("\n");

    printf("\nTeste com função for_each (inteiros):\n");
    printf("Array: ");
    for_each(arr_int, size_int, print_int, sizeof(int));
    printf("\n");

    printf("Quadrados: ");
    for_each(arr_int, size_int, square_int, sizeof(int));
    printf("\n");

    // Teste com array de doubles
    double arr_double[] = {1.5, 2.5, 3.5};
    size_t size_double = sizeof(arr_double) / sizeof(arr_double[0]);

    printf("\nTeste com macro foreach (doubles):\n");
    printf("Array: ");
    foreach(arr_double, size_double, printf("%.2f ", x));
    printf("\n");

    printf("\nTeste com função for_each (doubles):\n");
    printf("Array: ");
    for_each(arr_double, size_double, print_double, sizeof(double));
    printf("\n");

    return 0;
}
