/** Em processo... */
#include <stdio.h>
#include <setjmp.h>

/**
 * <setjmp.h>: Presentes funções e tipos e constantes que são capazes de manipular
 * o fluxo de execução de um programa. Portanto, trata-se de um cabeçalho do qual seus
 * recursos devem ser utilizados apenas em situações nas quais estes são a única opção,
 * caso o código escrito esteja seguindo o paradigma de programação estruturada,
 * uma vez que os efeitos das funções presentes neste cabeçalho assemelham-se ao uso de
 * goto's no código.
 * 
 * SETJMP: Salva o contexto de execução (ou seja, o estado atual do programa, como a pilha,
 * os registradores, etc.). Quando chamada, setjmp() retorna 0.
 * 
 * LONGJMP: Faz o programa "voltar" para o ponto onde setjmp() foi chamada, mas com um valor diferente.
 * Se longjmp() for chamada, a execução "salta" para o ponto em que setjmp() foi chamado, mas retorna 
 * um valor diferente de 0.
 */