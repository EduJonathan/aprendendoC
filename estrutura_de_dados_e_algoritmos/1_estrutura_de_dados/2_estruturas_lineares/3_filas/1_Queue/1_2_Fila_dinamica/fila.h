#ifndef FILA_H
#define FILA_H

// Definição das estruturas
typedef struct fila Fila;   // Definição da estrutura da fila
typedef struct lista Lista; // Definição da estrutura da lista

Fila *criar_fila();
void inserir(Fila *f, float v);
float remover(Fila *f);
int vazia(Fila *f);
void liberar(Fila *f);
void imprimir(Fila *f);

#endif
