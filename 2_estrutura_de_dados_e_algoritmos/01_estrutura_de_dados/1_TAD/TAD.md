<!-- @format -->

# Tipos Abstratos De Dados (TADS)

## Referências

Conforme explicado por Embacados [neste artigo][ref-embarcados].

[ref-embarcados]: https://embarcados.com.br/ponteiro-em-c-tipo-de-dado-abstrato/ "Ponteiro em C: Tipo de Dado Abstrato"

---

## Conceito de TADS

A site utilizado como referência implementa o conceito de abstração de dados, proposto por `Barbara Liskov em 1974`,
como uma ideia da abstração criada por funções. Sendo assim, cria o objetivo de definir um tipo de dado que possa ser
independente de qualquer implementação específica e separado do utilizador da aplicação.
Dito de outra maneira, um tipo de dado abstrato é caracterizado por definir um conjunto de valores e de operações para
manipular esses valores.

---

## Módulos

Um módulo na linguagem C pode ser criado utilizando arquivos de cabeçalho e de implementação.
Vale ressaltar que um módulo não é um tipo abstrato de dados, pois pode ser utilizado para outros fins.
Abaixo segue a definição de cada tipo de arquivo:

- **Arquivo de cabeçalho**: Os arquivos `.h` são utilizados para especificar `assinaturas(protótipos)` de funções,
  definições de constantes, tipos de dados criados pelo usuário etc. De modo geral, os arquivos de cabeçalho
  tem como função definir a interface de um módulo.

- **Arquivo de implementação**: Os arquivos `.c` implementam as `funções` definidas na interface.
  De modo geral, esses arquivos são compostos por diversas funções e estruturas de dados utilizadas internamente.

---

## Exemplo

```h
// Arquivo cabeçalho(Event.h)
#ifndef EVENT_H
#define EVENT_H

/* pEvent - Ponteiro para struct tEvent (Estrutura opaca) */
typedef struct tEvent *pEvent;

/**
 * @brief Construtor para estrutura tEvent.
 *
 * @return Retorna um ponteiro para o tipo tEvent.
 */
pEvent Event_Create(int id, int timeout);

/**
 * @brief Destrutor estrutura tEvent.
 *
 * @return Recebe o endereço do Ponteiro pEvent (indireção múltipla!!)
 */
void Event_Destroy(pEvent *event);

/**
 * @brief Define um novo timeout para o evento.
 *
 * @return Recebe o endereço da estrutura e o timeout desejado.
 */
void Event_SetTimeout(pEvent event, int timeout);

/**
 * @brief Retorna o timeout definido para o evento.
 *
 * @return Recebe o endereço da estrutura.
 */
int Event_GetTimeout(pEvent event);

#endif // EVENT_H
```

> Note que qualquer arquivo que incluir a interface Event.h não terá acesso aos elementos internos da estrutura `tEvent`,  
> pois sua definição está restrita ao arquivo de implementação.

---

```c
// Arquivo de implementação dessas funções(Event.c).
#include <stdlib.h>
#include "Event.h"

struct tEvent
{
    int id;
    int timeout;
};


pEvent Event_Create(int id, int timeout)
{
    pEvent pt;

    pt = (pEvent)malloc(sizeof(struct tEvent));

    if(pt != NULL)
    {
        /*inicializa os elementos da estrutura*/
        pt->id = id;
        pt->timeout = timeout;
    }

    return pt;
}

void Event_Destroy(pEvent * event)
{
    if(event != NULL)
    {
        free(*event); /*event é o ponteiro que possui o endereço da estrutura que será liberada */

        /* A indireção múltipla é utilizada para permitir atribuir NULL ao ponteiro da aplicação */
        *event = NULL;
    }
}

void Event_SetTimeout(pEvent event, int timeout)
{
    if(event != NULL)
    {
        event->timeout = timeout;
    }
}

int Event_GetTimeout(pEvent event)
{
    if(event != NULL)
    {
        return event->timeout;
    }

    return -1;
}
```

---

> O teste do módulo é mostrado a seguir.

```c
// Arquivo principal de teste do modulo (Event_main.c)
#include <stdio.h>
#include <stdlib.h>
#include "Event.h"

int main()
{
    pEvent Event1;

    Event1 = Event_Create(1, 100);

    if(Event1 != NULL)
    {
        int timeout = Event_GetTimeout(Event1);
        printf("Timeout: %i\r\n", timeout);

        Event_SetTimeout(Event1, 200);

        timeout = Event_GetTimeout(Event1);
        printf("Timeout: %i\r\n", timeout);
    }

    Event_Destroy(&Event1);

    return 0;
}
```

> É importante lembrar que qualquer tentativa de acesso fora do arquivo Event.c causará um erro de compilação.  
> Por exemplo: `Event1->timeout = 1`;  
> `error: dereferencing pointer to incomplete type`

O erro de compilação indica que a composição da estrutura não é conhecida. De fato, essa era a intenção,
logo os dados só podem ser manipulados a partir das operações definidas na interface.

---

Ressaltando que, ao utilizar a modularização por meio de Tipos Abstratos de Dados,
torna-se indispensável o processo de compilação conjunta dos módulos. Isso ocorre porque o código principal (o `main`)
depende apenas da interface definida no arquivo de cabeçalho, enquanto as implementações concretas das operações
estão contidas no arquivo `Event.c`.
Dessa forma, o processo de build garante que a separação entre interface e implementação seja mantida,
reforçando o encapsulamento e a abstração dos dados.

> Nesse caso utilizem então para compilar: `gcc -std=c17 Event.c Event_main.c -o event`  
> `./event`

---

## Cuidados

- Em hipótese alguma inclua arquivos com extensão `.c` utilizando #include.
  Arquivos `.c` devem ser compilados separadamente e vinculados durante o processo de build ou compilação manual.
- Inclua apenas arquivos .h nos módulos que dependem da interface (Não inclua para funções).
- Não exponha a definição da estrutura no arquivo de cabeçalho, pois isso quebra o encapsulamento do TAD.
- Sempre forneça funções de criação e destruição para evitar vazamentos de memória.
- Evite acessar ponteiros sem validação (NULL), garantindo maior segurança.
