#ifndef PRINTLN_H
#define PRINTLN_H

/**
 * @brief Função para imprimir uma string com quebra de linha ('\n') automática no final da string.
 * onde ao invés de utilizarmos `printf("string\n")`, utilizaremos `_println("string")`.
 *
 * O diferencial dessa função será sua implementação que em vez de utilizar escopo de função,
 * o controle dessa função será realizado pela linguagem assembly, linkada através da biblioteca dinâmica.
 * No momento o código assembly. E não possue implementação para outros formatores `(%d, %s, %c, etc)`.
 * Futuramente será implementado suporte para esses formatos.
 *
 * @param fmt A string de formato que pode conter especificadores de formato.
 * @param ... Argumentos adicionais para formatação, se necessário.
 * @return Retorna o número de caracteres impressos, excluindo o caractere nulo final.
 */
int _println(const char *, ...);

#endif // PRINTLN_H
