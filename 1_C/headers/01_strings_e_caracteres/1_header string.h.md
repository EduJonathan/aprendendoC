<!-- @format -->

# Header `<string.h>`

A header string.h (ou `<string.h>`) é parte da biblioteca padrão da linguagem C e fornece
funções prontas para operar principalmente com strings, que em C são representadas por arrays
de caracteres terminados por `\0` (null-terminated byte strings, ou NTBS).
Os tipos principais suportados são `char *` e `const char *`.

- As funções são categorizadas conforme operações típicas, abaixo temos:

---

## Cópias

| Função    | Assinatura                                              | Descrição                                |
| --------- | ------------------------------------------------------- | ---------------------------------------- |
| `strcpy`  | `char *strcpy(char *dest, const char *src);`            | Copia `src` para `dest` (inclui `'\0'`). |
| `strncpy` | `char *strncpy(char *dest, const char *src, size_t n);` | Copia até `n` caracteres de `src`.       |

---

## Concatenação

| Função    | Assinatura                                              | Descrição                           |
| --------- | ------------------------------------------------------- | ----------------------------------- |
| `strcat`  | `char *strcat(char *dest, const char *src);`            | Concatena `src` ao final de `dest`. |
| `strncat` | `char *strncat(char *dest, const char *src, size_t n);` | Concatena até `n` caracteres.       |

---

## Comparações

| Função        | Assinatura                                                   | Descrição                                                |
| ------------- | ------------------------------------------------------------ | -------------------------------------------------------- |
| `strcmp`      | `int strcmp(const char *s1, const char *s2);`                | Compara duas strings (sensível a maiúsculas/minúsculas). |
| `strncmp`     | `int strncmp(const char *s1, const char *s2, size_t n);`     | Compara até `n` caracteres.                              |
| `strcasecmp`  | `int strcasecmp(const char *s1, const char *s2);`            | Compara strings **ignorando maiúsculas/minúsculas**.     |
| `strncasecmp` | `int strncasecmp(const char *s1, const char *s2, size_t n);` | Compara até `n` caracteres, ignorando case.              |
| `strcoll`     | `int strcoll(const char *s1, const char *s2);`               | Compara strings considerando a _localização (locale)_.   |

---

O valor retornado pelas funções de comparação segue a regra:

- < 0 → a primeira string é lexicograficamente menor que a segunda
- == 0 → as strings são iguais
- \> 0 → a primeira string é lexicograficamente maior que a segunda

⚠️ O valor exato retornado não é garantido (podendo retornar até mesmo qualquer valor negativo(-3 por exemplo) ou positivo), apenas o sinal importa.

---

> strcasecmp e strncasecmp não fazem parte do padrão ISO C, são funções POSIX (Linux/Unix). Em Windows, equivalentes comuns são \_stricmp e \_strnicmp.

---

## Buscas

| Função    | Assinatura                                      | Descrição                                  |
| --------- | ----------------------------------------------- | ------------------------------------------ |
| `strchr`  | `char *strchr(const char *s, int c);`           | Primeira ocorrência de `c`.                |
| `strrchr` | `char *strrchr(const char *s, int c);`          | Última ocorrência de `c`.                  |
| `strstr`  | `char *strstr(const char *h, const char *n);`   | Localiza substring.                        |
| `strpbrk` | `char *strpbrk(const char *s, const char *a);`  | Busca qualquer caractere de `a`.           |
| `strspn`  | `size_t strspn(const char *s, const char *a);`  | Conta caracteres iniciais válidos.         |
| `strcspn` | `size_t strcspn(const char *s, const char *r);` | Conta até encontrar caracteres rejeitados. |

---

## Manipulação de Caracteres

| Função     | Assinatura                              | Descrição                             |
| ---------- | --------------------------------------- | ------------------------------------- |
| `strlen`   | `size_t strlen(const char *s);`         | Retorna tamanho da string.            |
| `strtok`   | `char *strtok(char *s, const char *d);` | Divide string em tokens (destrutiva). |
| `strerror` | `char *strerror(int errnum);`           | Mensagem textual de erro.             |

---

## Memória

| Função    | Assinatura                                              | Descrição                                  |
| --------- | ------------------------------------------------------- | ------------------------------------------ |
| `memset`  | `void *memset(void *s, int c, size_t n);`               | Preenche memória com `c`.                  |
| `memchr`  | `void *memchr(const void *s, int c, size_t n);`         | Procura byte em memória.                   |
| `memmove` | `void *memmove(void *dest, const void *src, size_t n);` | Copia `n` bytes com sobreposição segura.   |
| `memcmp`  | `int memcmp(const void *s1, const void *s2, size_t n);` | Compara blocos de memória.                 |
| `memcpy`  | `void *memcpy(void *dest, const void *src, size_t n);`  | Copia `n` bytes (não aceita sobreposição). |

> memcpy e memmove têm o mesmo propósito, porém memcpy é indefinido quando há sobreposição, enquanto memmove lida corretamente com esse caso.

---

## Outras funções

| Função     | Assinatura                                                    | Descrição                                                                                         |
| ---------- | ------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| `strcspn`  | `size_t strcspn(const char *s, const char *reject);`          | Retorna o comprimento do segmento inicial de `s` que **não contém** nenhum caractere de `reject`. |
| `strlen`   | `size_t strlen(const char *s);`                               | Retorna o tamanho da string (exclui o `'\0'`).                                                    |
| `strdup`   | `char *strdup(const char *s);`                                | Duplica uma string alocando memória dinamicamente (`malloc`).                                     |
| `strxfrm`  | `size_t strxfrm(char *dest, const char *src, size_t n);`      | Transforma `src` para uma forma apropriada para comparação com `strcoll`.                         |
| `snprintf` | `int snprintf(char *str, size_t size, const char *fmt, ...);` | Escreve uma string formatada em `str`, respeitando o limite de tamanho.                           |

> strdup, Não é ISO C padrão (é POSIX). A memória retornada deve ser liberada com free().  
> strxfrm, Usada em conjunto com strcoll. Depende do locale configurado (setlocale).  
> snprintf, É a alternativa segura ao sprintf. Sempre limita a escrita ao tamanho do buffer.

---

## Observações Gerais

- **Strings em C:** São sequências de bytes não-nulos terminadas por '\0'.
- **Buffer overflow:** Funções como strcpy, strcat e sprintf não verificam limites.
- **Alternativas mais seguras (C11):** strcpy_s, strcat_s, memcpy_s (nem sempre disponíveis).
- **Funções `n`:** Essas funções são as que determinam até onde a operação deva acontecer/checar.

- Tipos importantes:

  - **size_t:** tipo sem sinal para tamanhos
  - **NULL:** ponteiro nulo

- Retornos comuns:
  - Ponteiro para destino
  - size_t (tamanho)
  - int (comparação)
  - NULL em caso de falha
