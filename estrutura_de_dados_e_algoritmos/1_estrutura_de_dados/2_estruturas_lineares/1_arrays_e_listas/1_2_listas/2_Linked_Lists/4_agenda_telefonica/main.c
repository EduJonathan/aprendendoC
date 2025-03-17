#include "agenda.h"

int main(int argc, char **argv)
{
    struct Contato *listaTelefonica = NULL;

    // Inserindo contatos
    inserirContato(&listaTelefonica, "Carlos", "1234-5678");
    inserirContato(&listaTelefonica, "Ana", "2345-6789");
    inserirContato(&listaTelefonica, "Pedro", "3456-7890");

    // Imprimir listaTelefonica antes de procurar
    printf("Lista de Contatos:\n");
    imprimirLista(listaTelefonica);

    // Buscar contato
    struct Contato *encontrado = buscarContato(listaTelefonica, "Ana");
    printf("\nContato encontrado: %s | Telefone: %s\n", encontrado->nome, encontrado->telefone);

    // Excluir contato
    excluirContato(&listaTelefonica, "Pedro");

    printf("\nLista após exclusão de Pedro:\n");
    imprimirLista(listaTelefonica);

    // Liberar memória
    liberarMemoria(&listaTelefonica);
    return 0;
}
