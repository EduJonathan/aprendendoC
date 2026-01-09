# 📌 Padrão IEEE 754: Representação de Números de Ponto Flutuante

O padrão IEEE 754 é a norma universal para representação de números de ponto flutuante (fracionários)
em sistemas computacionais. Ele define como números como 3.14, -0.001 ou 6.022e23 são codificados em binário,
garantindo portabilidade e consistência entre diferentes hardwares e linguagens de programação, como C, C++, Python
e outras.

---

## 🧩 Estrutura do IEEE 754

Um número em IEEE 754 é dividido em três partes principais. Para precisão simples (float de 32 bits), a estrutura é:

| **Parte**    | **Bits** | **Descrição**                                                        |
| ------------ | -------- | -------------------------------------------------------------------- |
| Sinal (S)    | 1        | 0 para positivo, 1 para negativo.                                    |
| Expoente (E) | 8        | Representa a potência de 2, com bias de 127.                         |
| Mantissa (M) | 23       | Parte fracionária (significativa), com 1 implícito antes da vírgula. |

Fórmula Geral: `valor = (-1)^S × 1.M × 2^(E - bias)`

---

## 🔢 Tipos de Precisão

O IEEE 754 suporta diferentes níveis de precisão, cada um com sua estrutura e faixa de valores:

| **Tipo**                 | **Bits** | **Expoente (Bits/Bias)** | **Mantissa (Bits)** | **Faixa Aproximada**                |
| ------------------------ | -------- | ------------------------ | ------------------- | ----------------------------------- |
| Precisão Simples (float) | 32       | 8 / 127                  | 23                  | ±1.18×10⁻³⁸ a ±3.4×10³⁸             |
| Precisão Dupla (double)  | 64       | 11 / 1023                | 52                  | ±2.23×10⁻³⁰⁸ a ±1.8×10³⁰⁸           |
| Precisão Estendida       | 80       | 15 / 16383               | 64                  | Usada internamente por algumas FPUs |

---

## 🎯 Exemplo: Codificação de -6.25 em 32 Bits

Vamos codificar o número -6.25 em formato IEEE 754 de precisão simples:

### 1. Converter para binário

- Parte inteira: 6 = 110 (base 2).
- Parte fracionária: 0.25 = 0.01 (base 2, pois 0.25 = 2⁻²).
- Total: 110.01 (base 2) = 1.1001 × 2² (normalizado).

### 2. Determinar as partes

- Sinal (S): 1 (negativo).
- Expoente (E): 2 + 127 = 129 = 10000001 (base 2).
- Mantissa (M): 10010000000000000000000 (após remover o 1 implícito).

### 3. Representação final (32 bits)

`10000001 10010000000000000000000` Em hexadecimal: `0xC0C80000`.

---

## 🔍 Problemas Comuns

### Precisão Limitada

Números decimais como 0.1 não têm representação exata em binário, levando a erros de arredondamento.
Exemplo em C: `float x = 0.1;` // Na verdade, armazena ≈ 0.10000000149011612

```bash
# Exemplo famoso:

float a = 0.1;
float b = 0.2;
float c = a + b; # // c ≠ 0.3, mas algo como 0.300000004
```

Isso ocorre porque `0.1` e `0.2` não são representáveis exatamente em binário, causando erros na soma. 2. Overflow e Underflow

Overflow: Números muito grandes resultam em ∞ (infinito).
Underflow: Números muito pequenos são arredondados para `0.0`.

### Não Associatividade

Devido a arredondamentos, operações como `(a + b) + c` podem diferir de `a + (b + c)`

---

## 💻 Para Aprofundar

### 🌐 Ferramentas Online

- IEEE 754 Floating Point Converter: Visualize a representação binária de números.

### 📚 Livros

- Computer Organization and Design (David Patterson & John Hennessy).
- What Every Computer Scientist Should Know About Floating-Point Arithmetic (David Goldberg).

---

## 🚀 Importância do IEEE 754

Entender o padrão IEEE 754 é crucial para evitar bugs sutis em cálculos numéricos, especialmente
em aplicações científicas, jogos e sistemas financeiros. Ele garante precisão e portabilidade,
mas exige cuidado com limitações como erros de arredondamento e overflow/underflow.
