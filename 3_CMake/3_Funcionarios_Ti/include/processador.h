#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "pessoa.h"

/**
 * @brief Estrutura que define uma interface para processamento de pessoas.
 *
 * Contém dois ponteiros de função:
 * - @ref processar : Função chamada para processar cada pessoa.
 * - @ref finalizar : Função opcional chamada ao final do processamento.
 */
typedef struct
{
    /**
     * @brief Função de processamento aplicada a uma pessoa.
     *
     * @param p Ponteiro para a pessoa a ser processada.
     */
    void (*processar)(Pessoa *p);

    /**
     * @brief Função de finalização, chamada após o processamento.
     *
     * Pode ser usada para liberar recursos ou registrar logs finais.
     */
    void (*finalizar)(void);

    void *dados;
} ProcessadorPessoas;

/**
 * @brief Cria um processador que imprime informações das pessoas.
 *
 * @return Estrutura @ref ProcessadorPessoas configurada para impressão.
 */
ProcessadorPessoas criar_processador_impressao(void);

/**
 * @brief Cria um processador que aumenta o salário das pessoas.
 *
 * @param percentual Percentual de aumento aplicado ao salário (ex: 0.1 para 10%).
 * @return Estrutura @ref ProcessadorPessoas configurada para aumento de salário.
 */
ProcessadorPessoas criar_processador_aumento_salario(float percentual);

/**
 * @brief Cria um processador que gera logs das operações realizadas.
 *
 * @return Estrutura @ref ProcessadorPessoas configurada para logging.
 */
ProcessadorPessoas criar_processador_log(void);

void liberar_processador(ProcessadorPessoas *proc);

#endif // PROCESSADOR_H
