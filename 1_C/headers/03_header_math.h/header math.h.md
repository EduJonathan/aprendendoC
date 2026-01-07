<!-- @format -->

# Header `<math.h>`

O header `<math.h>` tem como objetivo, na linguagem de programação C, fornecer funções
prontas para cálculos matemáticos **avançados**, trabalhando principalmente com
tipos numéricos de ponto flutuante (**float**, **double**, **long double**).

> As funções estão organizadas por categoria abaixo.

---

## 1. Funções Potenciais

| **Função**    | **Assinatura**                     | **Descrição**                         |
| ------------- | ---------------------------------- | ------------------------------------- |
| `cbrt(x)`     | `double cbrt(double x)`            | Raiz cúbica de _x_                    |
| `hypot(x, y)` | `double hypot(double x, double y)` | √(x² + y²) sem overflow intermediário |
| `pow(x, y)`   | `double pow(double x, double y)`   | xʸ                                    |
| `sqrt(x)`     | `double sqrt(double x)`            | Raiz quadrada de _x_                  |

---

## 2. Funções Exponenciais e Logarítmicas

| **Função**          | **Assinatura**                           | **Descrição**                                |
| ------------------- | ---------------------------------------- | -------------------------------------------- |
| `exp(x)`            | `double exp(double x)`                   | eˣ                                           |
| `exp2(x)`           | `double exp2(double x)`                  | 2ˣ                                           |
| `frexp(x, &exp)`    | `double frexp(double x, int *exp)`       | Decompõe _x_ em mantissa e expoente (base 2) |
| `ldexp(x, exp)`     | `double ldexp(double x, int exp)`        | x × 2ᵉˣᵖ                                     |
| `log(x)`            | `double log(double x)`                   | Logaritmo natural                            |
| `log2(x)`           | `double log2(double x)`                  | Logaritmo base 2                             |
| `log10(x)`          | `double log10(double x)`                 | Logaritmo base 10                            |
| `modf(x, &intpart)` | `double modf(double x, double *intpart)` | Separa parte inteira e fracionária           |

---

## 3. Funções Trigonométricas

> Todas recebem argumentos em **radianos**.

| **Função**    | **Assinatura**                     | **Descrição**                          |
| ------------- | ---------------------------------- | -------------------------------------- |
| `acos(x)`     | `double acos(double x)`            | Arco cosseno                           |
| `asin(x)`     | `double asin(double x)`            | Arco seno                              |
| `atan(x)`     | `double atan(double x)`            | Arco tangente                          |
| `atan2(y, x)` | `double atan2(double y, double x)` | Arco tangente considerando o quadrante |
| `cos(x)`      | `double cos(double x)`             | Cosseno                                |
| `sin(x)`      | `double sin(double x)`             | Seno                                   |
| `tan(x)`      | `double tan(double x)`             | Tangente                               |

---

## 4. Funções Hiperbólicas

| **Função** | **Assinatura**           | **Descrição**             |
| ---------- | ------------------------ | ------------------------- |
| `acosh(x)` | `double acosh(double x)` | Arco cosseno hiperbólico  |
| `asinh(x)` | `double asinh(double x)` | Arco seno hiperbólico     |
| `atanh(x)` | `double atanh(double x)` | Arco tangente hiperbólico |
| `cosh(x)`  | `double cosh(double x)`  | Cosseno hiperbólico       |
| `sinh(x)`  | `double sinh(double x)`  | Seno hiperbólico          |
| `tanh(x)`  | `double tanh(double x)`  | Tangente hiperbólica      |

---

## 5. Funções para Divisão e Valor Absoluto

| **Função**         | **Assinatura**                              | **Descrição**                                    |
| ------------------ | ------------------------------------------- | ------------------------------------------------ |
| `fabs(x)`          | `double fabs(double x)`                     | Valor absoluto                                   |
| `fmod(x, y)`       | `double fmod(double x, double y)`           | Resto da divisão real                            |
| `remainder(x, y)`  | `double remainder(double x, double y)`      | Resto com arredondamento ao inteiro mais próximo |
| `remquo(x, y, &q)` | `double remquo(double x, double y, int *q)` | Resto e parte do quociente                       |

---

## 6. Funções para Arredondamento

| **Função**   | **Assinatura**                | **Descrição**                                   |
| ------------ | ----------------------------- | ----------------------------------------------- |
| `ceil(x)`    | `double ceil(double x)`       | Arredonda para cima                             |
| `floor(x)`   | `double floor(double x)`      | Arredonda para baixo                            |
| `trunc(x)`   | `double trunc(double x)`      | Remove parte fracionária                        |
| `round(x)`   | `double round(double x)`      | Arredonda para o inteiro mais próximo           |
| `rint(x)`    | `double rint(double x)`       | Arredonda conforme modo de arredondamento atual |
| `lround(x)`  | `long lround(double x)`       | Arredondamento para `long`                      |
| `llround(x)` | `long long llround(double x)` | Arredondamento para `long long`                 |
| `lrint(x)`   | `long lrint(double x)`        | Arredondamento para `long` (modo atual)         |
| `llrint(x)`  | `long long llrint(double x)`  | Arredondamento para `long long` (modo atual)    |

---

## 7. Funções de Classificação e Comparação

| **Função**             | **Assinatura**                               | **Descrição**                |
| ---------------------- | -------------------------------------------- | ---------------------------- |
| `fpclassify(x)`        | `#define fpclassify(double x)`               | Classifica o valor flutuante |
| `isfinite(x)`          | `#define isfinite(double x)`                 | Verifica se é finito         |
| `isinf(x)`             | `#define isinf(double x)`                    | Verifica infinito            |
| `isnan(x)`             | `#define isnan(double x)`                    | Verifica NaN                 |
| `isnormal(x)`          | `#define isnormal(double x)`                 | Verifica número normal       |
| `isgreater(x, y)`      | `#define isgreater(double x, double y)`      | x > y                        |
| `isgreaterequal(x, y)` | `#define isgreaterequal(double x, double y)` | x ≥ y                        |
| `isless(x, y)`         | `#define isless(double x, double y)`         | x < y                        |
| `islessequal(x, y)`    | `#define islessequal(double x, double y)`    | x ≤ y                        |
| `islessgreater(x, y)`  | `#define islessgreater(double x, double y)`  | x ≠ y                        |
| `isunordered(x, y)`    | `#define isunordered(double x, double y)`    | Algum é NaN                  |

---

## Observações Importantes

- Em sistemas **Linux/Unix**, é necessário linkar manualmente a biblioteca matemática:

```bash
gcc programa.c -lm
```

---

- A maioria das funções possui **sufixos** que indicam o tipo do argumento:

  - Sem sufixo → `double` (ex: `pow`)
  - `f` → `float` (ex: `powf`)
  - `l` → `long double` (ex: `powl`)

- Algumas funções retornam valores especiais como **NaN** ou **±∞**,
  que devem ser tratados com `isnan()` e `isinf()`.
