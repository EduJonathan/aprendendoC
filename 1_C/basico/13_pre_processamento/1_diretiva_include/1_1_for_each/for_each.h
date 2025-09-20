#ifndef FOR_EACH_H
#define FOR_EACH_H

#include <stdio.h>

/**
 * @brief Itera sobre os elementos de um array, aplicando uma ação a cada elemento.
 *
 * @param arr Ponteiro para o array (qualquer tipo).
 * @param size Número de elementos no array.
 * @param action Expressão a ser aplicada a cada elemento, usando 'x' como o elemento atual.
 * @note O usuário deve garantir que 'arr' não seja NULL e que 'size' seja positivo.
 *
 * @note typeof() é um operador especial do compilador GCC (e outros compiladores compatíveis)
 * que permite obter o tipo de uma expressão ou variável em tempo de compilação.
 * No código: o (arr)[0] - pega o primeiro elemento do array
 * typeof((arr)[0]) - obtém o tipo desse elemento
 * Cria uma variável x do mesmo tipo que os elementos do array
 */
#define foreach(arr, size, action)              \
    do                                          \
    {                                           \
        if ((arr) != NULL && (size) > 0)        \
        {                                       \
            for (size_t i = 0; i < (size); i++) \
            {                                   \
                typeof((arr)[0]) x = (arr)[i];  \
                action;                         \
            }                                   \
        }                                       \
    } while (0)

/**
 * @brief Aplica uma função a cada elemento de um array.
 *
 * @param arr Ponteiro para o array.
 * @param size Número de elementos no array.
 * @param action Ponteiro para a função a ser aplicada.
 * @param size_elem Tamanho de cada elemento em bytes.
 */
void for_each(void *arr, size_t size, void (*action)(void *), size_t size_elem);

#endif

/**
 * A diretiva #ifndef protege contra a inclusão repetida do conteúdo do arquivo de cabeçalho.
 * Se FOR_EACH_H já estiver definido (ou seja, já foi incluído), as próximas
 * inclusões serão ignoradas. Esse padrão é conhecido como "guarda de inclusão" (include guard).
 *
 * @note O nome do include guard (FOR_EACH_H) não precisa ser exatamente o nome do arquivo.
 */
