<!-- @format -->

# Header `<fenv.h>`

A header `<fenv.h>` fornece mecanismos para **controle do ambiente de ponto flutuante (Floating-Point Environment)**.
Embora complemente a `<math.h>`, ela possui uma responsabilidade distinta: controlar **modos de arredondamento**
e **exceções de ponto flutuante**, conforme o padrão **IEEE 754**.

Essa separação aumenta a **modularidade**, a **portabilidade** e o **controle numérico** em aplicações que exigem
precisão matemática rigorosa, como sistemas científicos, financeiros e embarcados.

---

## Exemplo de uso básico

```c
#include <stdio.h>
#include <math.h>
#include <fenv.h>

#pragma STDC FENV_ACCESS ON

fesetround(FE_UPWARD); // Arredondamento para +∞

double x = sqrt(2.0);

// Testa se a operação gerou resultado inexato
if (fetestexcept(FE_INEXACT)) {
    printf("Operação inexata\n");
}
```

---

## Exceções de ponto flutuante (Floating-Point Exceptions)

> Essas macros representam condições excepcionais ocorridas durante operações de ponto flutuante.

| Macro           | Descrição                           |
| --------------- | ----------------------------------- |
| `FE_INVALID`    | Operação inválida (ex: `0.0 / 0.0`) |
| `FE_DIVBYZERO`  | Divisão por zero                    |
| `FE_OVERFLOW`   | Overflow (resultado muito grande)   |
| `FE_UNDERFLOW`  | Underflow (resultado muito pequeno) |
| `FE_INEXACT`    | Resultado inexato (arredondamento)  |
| `FE_ALL_EXCEPT` | Todas as exceções acima             |

---

## Modos de arredondamento

> Definem como os valores são arredondados quando o resultado não é representável exatamente.

| Macro           | Descrição                                                           |
| --------------- | ------------------------------------------------------------------- |
| `FE_TONEAREST`  | Arredonda para o mais próximo (ties para par) — **padrão IEEE 754** |
| `FE_UPWARD`     | Arredonda em direção a +∞                                           |
| `FE_DOWNWARD`   | Arredonda em direção a −∞                                           |
| `FE_TOWARDZERO` | Arredonda em direção a zero                                         |

```c
fesetround(FE_TONEAREST); // Modo padrão
```

---

## Funções principais de `<fenv.h>`

| Função            | Descrição                       |
| ----------------- | ------------------------------- |
| `feclearexcept()` | Limpa flags de exceção          |
| `fetestexcept()`  | Testa exceções ocorridas        |
| `fesetround()`    | Define o modo de arredondamento |
| `fegetround()`    | Obtém o modo atual              |
| `feholdexcept()`  | Salva e limpa o ambiente        |
| `fesetenv()`      | Restaura ambiente salvo         |

---

## 💡 Dica IMPORTANTE

Sempre use:

```bash
#pragma STDC FENV_ACCESS ON
```

> Sem isso, o compilador pode ignorar completamente as alterações do ambiente FP por otimizações.

📘 **Conclusão**

A `<fenv.h>` não altera diretamente a precisão dos tipos numéricos, mas fornece controle
fino sobre **como os cálculos de ponto flutuante se comportam** em relação a arredondamento
e exceções. Seu uso é essencial em aplicações que exigem previsibilidade, conformidade com
o IEEE 754 e rigor matemático.
