<!-- @format -->

# Header `<complex.h>`

A header `<complex.h>` fornece suporte nativo da linguagem C para **números complexos**,
seguindo o padrão **C99** e a especificação **IEEE 754** para aritmética de ponto flutuante.

De forma semelhante à `<math.h>`, essa biblioteca disponibiliza funções matemáticas,
porém voltadas para valores do tipo **complexo**, permitindo trabalhar diretamente com
números da forma:

[z = a + bi]

onde:

- `a` é a parte real
- `b` é a parte imaginária

---

## Tipos de dados complexos

O C define os seguintes tipos complexos:

| Tipo                  | Descrição                      |
| --------------------- | ------------------------------ |
| `float complex`       | Complexo de precisão simples   |
| `double complex`      | Complexo de precisão dupla     |
| `long double complex` | Complexo de precisão estendida |

Esses tipos são baseados no tipo interno `_Complex`.

```c
#include <complex.h>

double complex z = 3.0 + 4.0 * I;
```

> 🔹 `I` representa a unidade imaginária (√−1)

---

## Acesso às partes real e imaginária

```c
double real = creal(z);
double imag = cimag(z);
```

---

## Principais operações matemáticas

A biblioteca `<complex.h>` fornece versões complexas de várias funções matemáticas,
geralmente utilizando o **prefixo `c`** em relação às funções da `<math.h>`.

| Função                    | Descrição                 |
| ------------------------- | ------------------------- |
| `cabs`                    | Módulo do número complexo |
| `carg`                    | Argumento (ângulo)        |
| `conj`                    | Conjugado                 |
| `csqrt`                   | Raiz quadrada             |
| `cexp`                    | Exponencial               |
| `clog`                    | Logaritmo natural         |
| `cpow`                    | Potência                  |
| `csin`, `ccos`, `ctan`    | Funções trigonométricas   |
| `casin`, `cacos`, `catan` | Trigonométricas inversas  |

---

## Exemplo completo

```c
#include <stdio.h>
#include <complex.h>

int main() {
    double complex z = 3.0 + 4.0 * I;

    printf("z = %.2f + %.2fi\n", creal(z), cimag(z));
    printf("Modulo: %.2f\n", cabs(z));
    printf("Argumento: %.2f\n", carg(z));

    double complex w = conj(z);
    printf("Conjugado: %.2f + %.2fi\n", creal(w), cimag(w));

    return 0;
}
```

---

## Relação com `<math.h>`

- `<math.h>` trabalha com **números reais**
- `<complex.h>` trabalha com **números complexos**
- Muitas funções possuem equivalentes diretos, mas **não são as mesmas funções**
- O comportamento matemático segue as definições do **plano complexo**
- Em sistemas Unix-like, geralmente é necessário compilar com a flag **`-lm`**,
  pois as funções matemáticas e complexas ficam na biblioteca `libm`
- As funções possuem sufixos para trabalhar com diferentes precisões:
  - Sem sufixo → `double complex` (ex: `cpow()`)
  - `f` → `float complex` (ex: `cpowf()`)
  - `l` → `long double complex` (ex: `cpowl()`)

---

📘 **Conclusão**

A `<complex.h>` introduz suporte matemático avançado diretamente na linguagem C,
eliminando a necessidade de bibliotecas externas para cálculos com números complexos.
Seu uso é essencial em áreas como processamento de sinais, física, engenharia elétrica
e computação científica.
