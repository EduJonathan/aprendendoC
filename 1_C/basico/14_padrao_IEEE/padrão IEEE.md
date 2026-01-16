<!-- @format -->

# 📌 Padrão IEEE 754: Representação de Números de Ponto Flutuante

O padrão IEEE 754 é a norma universal para representação de números de ponto flutuante (fracionários)
em sistemas computacionais. Ele define como números como `3.14`, `-0.001` ou `6.022e23` são codificados em binário,
garantindo portabilidade e consistência entre diferentes hardwares e linguagens de programação, como C, C++, Python e outras.

---

## 🧩 Estrutura do IEEE 754

Um número em `IEEE 754` é dividido em três partes principais. Para precisão simples (float de 32 bits), a estrutura é:

| **Parte**    | **Bits** | **Descrição**                                                        |
| ------------ | -------- | -------------------------------------------------------------------- |
| Sinal (S)    | 1        | 0 para positivo, 1 para negativo.                                    |
| Expoente (E) | 8        | Representa a potência de 2, com bias de 127.                         |
| Mantissa (M) | 23       | Parte fracionária (significativa), com 1 implícito antes da vírgula. |

> **Fórmula Geral (números normalizados):** `valor = (-1)^S × 1.M × 2^(E - bias)`

`M` é tratada como uma fração binária (ex: `0.1001₂`), e o termo `1.M` representa o **1 implícito** seguido da parte fracionária.

---

## 🔢 Tipos de Precisão

O IEEE 754 suporta diferentes níveis de precisão, cada um com sua estrutura e faixa de valores:

| **Tipo**                 | **Bits** | **Expoente (Bits / Bias)** | **Mantissa (Bits)** | **Faixa Aproximada**      |
| ------------------------ | -------- | -------------------------- | ------------------- | ------------------------- |
| Precisão Simples (float) | 32       | 8 / 127                    | 23                  | ±1.18×10⁻³⁸ a ±3.4×10³⁸   |
| Precisão Dupla (double)  | 64       | 11 / 1023                  | 52                  | ±2.23×10⁻³⁰⁸ a ±1.8×10³⁰⁸ |
| Precisão Estendida       | 80       | 15 / 16383                 | 64                  | Usada por algumas FPUs    |

> **Nota:** O _épsilon de máquina_ é o menor número que, somado a 1, produz um valor diferente de 1.  
> Ele mede a **precisão relativa** do formato.

---

## 🎯 Exemplo: Codificação de -6.25 em 32 Bits

### 1. Converter para binário

- **Parte inteira:** `6 = 110₂`
- **Parte fracionária:** `0.25 = 0.01₂`
- **Total:** `110.01₂ = 1.1001₂ × 2²`

---

### 2. Determinar as partes

- **Sinal (S):** `1`
- **Expoente (E):** `2 + 127 = 129 = 10000001₂`
- **Mantissa (M):** `10010000000000000000000₂`

---

### 3. Representação final

- **Binário:** `1 10000001 10010000000000000000000`
- **Hexadecimal:** `0xC0C80000`

---

## Valores Especiais e Casos Extremos

O IEEE 754 padroniza a representação de situações que fogem do normal:

| **Caso**    | **Expoente** | **Mantissa** | **Representa**         |
| ----------- | ------------ | ------------ | ---------------------- |
| `Zero`      | 0            | 0            | +0 ou -0               |
| `Subnormal` | 0            | ≠ 0          | Números muito pequenos |
| `Infinito`  | 255          | 0            | ±∞                     |
| `NaN`       | 255          | ≠ 0          | Resultado indefinido   |

> **Importância**: Essas representações permitem que operações continuem de forma controlada, sem travar o programa,
> e são essenciais para detecção de erros. Existem dois tipos de NaN:

- NaN Silencioso (quiet NaN): Propaga através das operações sem gerar exceção
- NaN Sinalizador (signaling NaN): Gera uma exceção quando usado em operações

---

## 🔍 Problemas Comuns

### 1. Precisão Limitada

Números decimais não têm representação EXATA em binário, levando a erros de arredondamento.

```bash
# Exemplo:
float x = 0.1; # Na verdade, armazena ≈ 0.10000000149011612
```

```bash
# Exemplo famoso:
float a = 0.1;
float b = 0.2;
float c = a + b; # // c ≠ 0.3, mas algo como 0.300000004
```

> Isso ocorre porque `0.1` e `0.2` não são representáveis exatamente em binário, causando erros na soma.

---

### 2. Overflow e Underflow

- **Overflow:** Números muito grandes resultam em `±Inf` (infinito).
- **Underflow:** Números muito pequenos podem ser arredondados para zero ou para números subnormais.

---

### Não Associatividade

> Devido a arredondamentos, operações em ponto flutuante não são associativas:  
> operações como: `(a + b) + c` podem diferir de `a + (b + c)`

---

## 🔧 Ferramentas Online para IEEE 754

### 1. Conversores e Visualizadores

#### IEEE 754 Converter

[babbage.cs.qc.cuny.edu](https://babbage.cs.qc.cuny.edu/IEEE-754/)

#### FloatConverter

[h-schmidt.net](https://www.h-schmidt.net/FloatConverter/IEEE754.html)

#### IEEE-754 Analysis

[babbage.cs.qc.cuny.edu](https://babbage.cs.qc.cuny.edu/IEEE-754/analysis.xhtml)

---

### 2. Ferramentas Interativas

#### Float Exposed (Recomendado)

[float.exposed](https://float.exposed)

#### IEEE 754 Visualization ("Float Toy")

[evanw.github.io](https://evanw.github.io/float-toy/)

#### Binary Convert

[binaryconvert.com](https://www.binaryconvert.com)

---

### 3. Ferramentas para Casos Especiais

#### NaN Box Debugger

[bartaz.github.io](https://bartaz.github.io/nan-boxing/)

---

### 📚 Livros e Artigos

- `Computer Organization and Design` (David Patterson & John Hennessy)
- `What Every Computer Scientist Should Know About Floating-Point Arithmetic` (David Goldberg) - artigo fundamental
- `Numerical Recipes: The Art of Scientific Computing`

---

### Boas Práticas

- **Evite comparar floats:** com `==` Use tolerância relativa.

```c
#include <math.h>
#include <stdbool.h>

bool quase_igual(double a, double b, double epsilon) {
    return fabs(a - b) <= epsilon * fmax(fabs(a), fabs(b));
}

// Ou utilize a macro
#define EPSILON 1e-9

bool quase_igual(double a, double b) {
    return fabs(a - b) <= EPSILON * fmax(fabs(a), fabs(b));
}
```

- **Minimize operações:** Reduza o número de operações para limitar erros acumulados.
- **Use double para cálculos críticos:** Quando precisão extra é necessária.
- **Esteja ciente de cancelamentos catastróficos:** Em subtrações de números quase iguais.

---

## 🚀 Importância do IEEE 754

Entender o padrão IEEE 754 é crucial para:

- Evitar bugs sutis em cálculos numéricos
- Desenvolver aplicações robustas em áreas científicas, financeiras e de jogos
- Otimizar performance escolhendo o tipo correto de precisão
- Interpretar resultados de debuggers e analisadores de memória

O padrão garante portabilidade e consistência entre diferentes plataformas, mas exige cuidado com suas limitações
inerentes,como erros de arredondamento, casos especiais e comportamento não associativo.

> Lembre-se: Ponto flutuante é uma aproximação da matemática dos números reais, não uma implementação exata!
