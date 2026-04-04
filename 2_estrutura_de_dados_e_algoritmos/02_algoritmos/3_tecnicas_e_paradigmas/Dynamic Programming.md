# Dynamic Programming

## 🔍 Programação Dinâmica (PD)

A Programação Dinâmica é um paradigma de solução de problemas que envolve a quebra de um
problema em subproblemas menores e a resolução de cada um desses subproblemas apenas uma vez,
armazenando suas soluções em uma tabela (memoization ou bottom-up).

Esse armazenamento evita a recomputação das mesmas soluções e, por isso,
é uma técnica extremamente eficiente.

Especialmente útil para problemas de otimização em que é necessário encontrar a
melhor solução entre várias possibilidades. Muitas vezes, a `PD` é aplicada a problemas
de recursão onde a solução pode ser expressa por meio de uma equação de recorrência.

---

🔹 Exemplos clássicos de uso da PD:

- Sequência de Fibonacci
- Problema da Mochila (Knapsack Problem)
- Caminho mínimo em matrizes (como em labirintos)
- Subsequência Comum Máxima (LCS)
- Problemas de corte de hastes, moedas, etc.

🔹 Principais abordagens:

- Top-down (com memoization): usa recursão com cache para armazenar subproblemas resolvidos.
- Bottom-up (com tabulação): resolve os subproblemas menores primeiro e usa esses resultados para construir soluções maiores.

---

## 🛠 Como Funciona a Programação Dinâmica?

1. Divisão do problema: O problema é dividido em subproblemas menores.
2. Armazenamento das soluções: As soluções dos subproblemas são armazenadas em uma tabela para evitar o cálculo repetido.
3. Resolução de subproblemas: Os subproblemas são resolvidos de maneira eficiente, e as soluções são combinadas
   para resolver o problema original.

---

## 🧠 Características dos Problemas que Usam PD

1. Sobreposição de subproblemas: O problema pode ser dividido em subproblemas menores, que são resolvidos
   de forma independente e reutilizados para resolver problemas maiores.
2. Ótima subestrutura: A solução para o problema pode ser construída a partir das soluções ótimas dos subproblemas.
3. Eficiência por cache: Na maioria dos casos, consultar um resultado previamente calculado é mais eficiente do que recalculá-lo, economizando ciclos de CPU.

---

## 📊 Como Programação Dinâmica se Encaixa nas Notações Assintóticas?

A Programação Dinâmica melhora a eficiência dos algoritmos, passando de soluções de força bruta
(geralmente exponenciais) para soluções mais eficientes, como tempo polinomial. Muitos problemas
de PD, que poderiam ter uma solução exponencial, têm uma complexidade de tempo que é
significativamente mais eficiente, por exemplo, O(n²), O(nlogn), O(n), dependendo do problema.

---

## 💡 Vantagens e Desvantagens da Programação Dinâmica

✅ Vantagens

- Otimização de performance: A PD pode reduzir a complexidade de tempo de muitos problemas, economizando tempo de execução.
- Solução ótima garantida: Quando aplicável, a PD sempre retorna a solução ótima.

⚠️ Desvantagens

- Consumo de memória: A PD pode exigir muito espaço para armazenar as soluções dos subproblemas,
  o que pode ser um problema em situações com grandes entradas.
- Dificuldade de implementação: Em alguns casos, entender a relação de recorrência e estruturar
  a solução usando PD pode ser desafiador.

---

## 🚀 Aplicações Práticas

- Bioinformática: Alinhamento de sequências de DNA.
- Processamento de Linguagem Natural: Comparação de textos.
- Sistemas de Recomendação: Otimização de escolhas.
- Finanças: Maximização de lucros em investimentos.
- Robótica: Planejamento de caminhos ótimos.

---

## ❗ Dica Final

Se você percebe que está resolvendo o mesmo subproblema repetidamente em uma função recursiva,
isso é um forte indicativo de que Programação Dinâmica pode (e deve) ser aplicada. Além de muitos
conceitos da matemática em si.
