#include <stdio.h>

/**
 * ftell(): Retorna a posição atual do cursor de leitura/escrita em um arquivo.
 * A posição é dada em bytes a partir do início do arquivo.
 *
 * SINTAXE: long ftell(FILE *_File);
 *
 * @param _File Um ponteiro para um objeto FILE que identifica o arquivo para o qual
 * você deseja obter a posição do cursor.
 * @return A função retorna a posição atual do cursor no arquivo, em bytes, a partir do
 * início do arquivo.
 *
 * @note É uma maneira eficaz de monitorar e gerenciar a posição do cursor ao trabalhar com
 * arquivos em C.
 */
