<!-- @format -->

# Header `<ctype.h>`

O header `<ctype.h>` da linguagem C tem como propósito bem simples de **classificar e manipular caracteres**,
permitindo verificar se eles são **numéricos**, **alfabéticos**, **espaços em branco**, **símbolos**, entre outros.

Essas funções são amplamente utilizadas em validação de entrada, análise de texto e parsers.

---

## Funções da `<ctype.h>`

| **Função**   | **Assinatura**        | **Descrição**                                                 |
| ------------ | --------------------- | ------------------------------------------------------------- |
| **isascii**  | `int isascii(int c)`  | Verifica se o caractere pertence ao conjunto ASCII (0–127).   |
| **isalnum**  | `int isalnum(int c)`  | Verifica se é alfanumérico (`A–Z`, `a–z`, `0–9`).             |
| **isalpha**  | `int isalpha(int c)`  | Verifica se é uma letra do alfabeto.                          |
| **isblank**  | `int isblank(int c)`  | Verifica se é espaço em branco horizontal (`' '` ou `'\t'`).  |
| **iscntrl**  | `int iscntrl(int c)`  | Verifica se é um caractere de controle.                       |
| **isdigit**  | `int isdigit(int c)`  | Verifica se é um dígito decimal (`0–9`).                      |
| **isgraph**  | `int isgraph(int c)`  | Verifica se é imprimível, exceto espaço.                      |
| **islower**  | `int islower(int c)`  | Verifica se é letra minúscula.                                |
| **isprint**  | `int isprint(int c)`  | Verifica se é um caractere imprimível.                        |
| **ispunct**  | `int ispunct(int c)`  | Verifica se é um caractere de pontuação.                      |
| **isspace**  | `int isspace(int c)`  | Verifica se é espaço em branco (`' '`, `'\n'`, `'\t'`, etc.). |
| **isupper**  | `int isupper(int c)`  | Verifica se é letra maiúscula.                                |
| **isxdigit** | `int isxdigit(int c)` | Verifica se é um dígito hexadecimal (`0–9`, `A–F`, `a–f`).    |
| **tolower**  | `int tolower(int c)`  | Converte letra maiúscula para minúscula.                      |
| **toupper**  | `int toupper(int c)`  | Converte letra minúscula para maiúscula.                      |

---

## Observações Importantes

- As funções retornam:

  - **0** → falso
  - **valor diferente de 0** → verdadeiro

- O argumento deve ser: Um `unsigned char` convertido para `int`, **ou** o valor especial `EOF`
- A função isascii não é padrão C
- O conjunto **ASCII padrão** vai em intervalos de **0 a 127**
- O comportamento pode depender da **localização (`locale`)** ativa
