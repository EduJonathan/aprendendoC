#include <stdio.h>

/**
 * fwrite(): grava dados de um buffer para um arquivo aberto. Ela escreve um número
 * específico de elementos de um determinado tamanho para o arquivo.
 *
 * SINTAXE: 
 * size_t fwrite(const void *__restrict__ _Str, size_t _Size, size_t _Count, FILE *__restrict__ _File);
 *
 * @param ptr: Um ponteiro para o buffer que contém os dados a serem gravados.
 * @param size: O tamanho, em bytes, de cada elemento a ser escrito.
 * @param count: O número de elementos a serem escritos.
 * @param stream: Um ponteiro para o objeto FILE
 * @return A função retorna o número de elementos efetivamente gravados. Isso pode ser
 * menor que count se ocorrer um erro ou se o final do arquivo for alcançado.
 * 
 * @note A função fwrite() pode ser usada para gravar os dados de um arquivo binario.
 */
