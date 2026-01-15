<!-- @format -->

# Header `<stdlib.h>`

A header `<stdlib.h>` é uma das bibliotecas mais importantes da linguagem C, pois fornece
funcionalidades essenciais, sendo uma das principais o **controle manual da alocação de memória**,
uma característica marcante da linguagem C.

Essa biblioteca contém diversas funções, com destaque para as funções de **alocação dinâmica de memória**,
que permitem ao programa reservar e liberar memória **durante a execução**, por meio de ponteiros.

---

## `malloc` (Memory Allocation)

A função `malloc` é usada para alocar dinamicamente um bloco de memória de um tamanho específico.

- **O que faz:** Reserva um bloco contínuo de bytes na **Heap**.
- **Importante:** A memória **não é inicializada**; os valores contidos nela são indefinidos (lixo de memória).
- **Retorno:** Retorna um ponteiro do tipo `void*`, que deve ser convertido para o tipo desejado. Caso a alocação falhe, retorna `NULL`.

```c
int *ptr = (int*) malloc(5 * sizeof(int)); // Aloca espaço para 5 inteiros
```

---

## `realloc` (Re-allocation)

A função `realloc` demonstra a flexibilidade da linguagem C ao permitir alterar o tamanho de um bloco
de memória já alocado.

- **O que faz:** Redimensiona um bloco de memória previamente alocado.
- **Comportamento:**

  - Se houver espaço suficiente, o bloco pode ser expandido no mesmo local.
  - Caso contrário, um novo bloco é alocado, os dados antigos são copiados e o bloco anterior é liberado automaticamente.

- **Risco importante:** Se `realloc` falhar, ela retorna `NULL` **sem liberar o bloco original**.
  Por isso, o retorno deve ser atribuído a um ponteiro temporário.

```c
int *temp = (int*) realloc(ptr, 10 * sizeof(int));
if (temp != NULL) {
  ptr = temp;
}
```

---

## `calloc` (Contiguous Allocation)

A função `calloc` é semelhante ao `malloc`, mas possui uma diferença importante.

- **O que faz:** Aloca memória para um número específico de elementos de mesmo tamanho.
- **Diferencial:** Inicializa todos os bits com zero.
- **Sintaxe:** Recebe dois parâmetros:

  1. Quantidade de elementos
  2. Tamanho de cada elemento

```c
int *ptr = (int*) calloc(5, sizeof(int)); // Aloca 5 inteiros e inicializa todos com zero
```

---

> ⚠️ **Atenção:**
> Toda memória alocada dinamicamente deve ser liberada com a função `free()`.
> Caso contrário, ocorre um **Memory Leak (vazamento de memória)**, que consome recursos do sistema
> até comprometer o desempenho ou causar falhas no programa.

```c
free(ptr);  // Sempre libere a memória
ptr = NULL; // Boa prática
```

---

## Memória Heap vs Stack

Entender a diferença entre **Heap** e **Stack** é fundamental para o uso correto da memória em C.

### 🧱 Stack (Pilha)

- Gerenciada automaticamente pelo compilador.
- Armazena variáveis locais e chamadas de funções.
- Alocação e liberação são rápidas.
- Tamanho limitado.
- Tempo de vida curto (a variável deixa de existir ao sair do escopo).

```c
void func() {
  int x = 10; // Alocado na Stack
} // vida útil de x termina ao sair do bloco
```

---

### 🧠 Heap (Memória dinâmica)

- Gerenciada manualmente pelo programador.
- Usada pelas funções `malloc`, `calloc` e `realloc`.
- Maior capacidade de armazenamento.
- Alocação mais lenta.
- Tempo de vida controlado pelo programador.

```c
int *ptr = malloc(sizeof(int)); // Alocado na Heap
```

### 📌 Resumo

| **Stack**        | **Heap**              |
| ---------------- | --------------------- |
| Automática       | Manual                |
| Rápida           | Mais lenta            |
| Tamanho limitado | Grande capacidade     |
| Escopo curto     | Persiste até `free()` |

---

> O cabeçalho `<stdlib.h>` conta com diversas outras funções além das de alocação de memória,
> abrangendo **conversões de tipos**, **geração de números aleatórios** e **algoritmos de busca e ordenação**.

---

## Funções de conversão

Essas funções convertem strings em valores numéricos ou realizam operações matemáticas básicas.

| **Função** | **Assinatura**                                                      | **Descrição**                                        |
| ---------- | ------------------------------------------------------------------- | ---------------------------------------------------- |
| `abs`      | `int abs(int x);`                                                   | Retorna o valor absoluto de um inteiro               |
| `atof`     | `double atof(const char *nptr);`                                    | Converte uma string para `double`                    |
| `atoi`     | `int atoi(const char *nptr);`                                       | Converte uma string para `int`                       |
| `atol`     | `long atol(const char *nptr);`                                      | Converte uma string para `long`                      |
| `div`      | `div_t div(int numer, int denom);`                                  | Realiza divisão inteira retornando quociente e resto |
| `strtod`   | `double strtod(const char *nptr, char **endptr);`                   | Converte string para `double` com controle de erro   |
| `strtol`   | `long strtol(const char *nptr, char **endptr, int base);`           | Converte string para `long`                          |
| `strtoul`  | `unsigned long strtoul(const char *nptr, char **endptr, int base);` | Converte string para `unsigned long`                 |

> ⚠️ **Observação:**
> Funções como `atoi`, `atof` e `atol` **não possuem verificação de erro**.
> Prefira `strtol`, `strtod`, etc., em código profissional.
> função `itoa` não é padrão da linguagem.

---

## Funções de geração de números aleatórios

Essas funções permitem gerar valores pseudoaleatórios.

| **Função** | **Assinatura**                   | **Descrição**                                         |
| ---------- | -------------------------------- | ----------------------------------------------------- |
| `rand`     | `int rand(void);`                | Retorna um número pseudoaleatório                     |
| `srand`    | `void srand(unsigned int seed);` | Inicializa a semente do gerador de números aleatórios |

```c
#include <stdlib.h>
#include <time.h>

srand(time(NULL));     // Inicializa a semente
int n = rand() % 100;  // Número entre 0 e 99
```

---

## Funções algorítmicas

Funções genéricas para **ordenação** e **busca binária**.

| **Função** | **Assinatura**                                                                                                     | **Descrição**                           |
| ---------- | ------------------------------------------------------------------------------------------------------------------ | --------------------------------------- |
| `qsort`    | `void qsort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));`                           | Ordena um array genérico                |
| `bsearch`  | `void *bsearch(const void *key, const void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));` | Realiza busca binária em array ordenado |

---

| Pergunta                             | Resposta           |
| ------------------------------------ | ------------------ |
| `qsort` é Quick Sort?                | ❌ Não é garantido |
| Algoritmo é definido pelo padrão?    | ❌ Não             |
| `bsearch` precisa de `qsort`?        | ❌ Não             |
| `bsearch` precisa de array ordenado? | ✅ Sim             |
| `qsort` + `bsearch` juntos é comum?  | ✅ Sim             |

---

📘 **Conclusão**

O poder da linguagem C está no controle direto da memória e dos dados, mas esse poder exige
responsabilidade. Compreender corretamente o uso da **Heap**, da **Stack** e das funções da
`<stdlib.h>` é essencial para escrever programas eficientes, seguros e confiáveis.
