<!-- @format -->

# Otimização de Algoritmos

## Introdução

Desde o surgimento da computação, percebeu-se que **todo processamento tem um custo** para o hardware
(tempo de CPU, memória RAM, consumo de energia, etc.). Com o crescimento exponencial da quantidade de dados e da complexidade dos problemas,
foram surgindo diversas **implementações e técnicas de otimização** baseadas em sólidos conceitos matemáticos e teóricos.

O objetivo central dessas técnicas é **reduzir o tempo de execução**, **diminuir o consumo de recursos** e **encontrar soluções viáveis ou ótimas**
dentro de limites aceitáveis de tempo e memória, especialmente em problemas reais como roteamento, alocação de recursos, machine learning e logística.

## Teorias e Conceitos Fundamentais

### Métodos Clássicos de Otimização

- **Algoritmo Simples**  
  Método direto e intuitivo que resolve o problema sem técnicas avançadas. Útil para problemas pequenos ou como baseline para comparação.

- **Método Big M**  
  Técnica usada em Programação Linear para tratar restrições de igualdade e desigualdade. Introduz uma variável artificial com um coeficiente muito grande (_M_) na função objetivo para forçar a solução viável.

- **Método das Duas Fases**  
  Alternativa ao Big M. Divide o problema em duas fases:  
  1ª fase: encontra uma solução básica viável;  
  2ª fase: otimiza a função objetivo real. Mais estável numericamente.

- **Método de Newton Multivariado**  
  Método iterativo baseado no gradiente e na matriz Hessiana. Resolve problemas de otimização não linear encontrando pontos críticos
  (mínimos, máximos ou pontos de sela) de forma quadrática convergente.

### Complexidade Computacional

- **Classes de Problemas**
  - **P** (Polynomial): problemas resolvíveis em tempo polinomial.
  - **NP** (Non-deterministic Polynomial): solução pode ser verificada em tempo polinomial.
  - **NP-Completo**: os problemas mais difíceis de NP. Se um for resolvido em tempo polinomial, todos os NP também serão.
  - **NP-Difícil**: pelo menos tão difíceis quanto os NP-completos, mas não necessariamente em NP.

### Tipos de Otimização

- **Otimização Linear**  
  Problemas onde a função objetivo e as restrições são lineares (ex.: Simplex, Programação Linear Inteira).

- **Otimização Não Linear**  
  Função objetivo ou restrições são não lineares. Requer métodos como Gradiente Conjugado, Newton ou metaheurísticas.

## Técnicas Algoritmicas

São abordagens práticas implementadas diretamente no código para melhorar o desempenho:

- **Loop Unrolling**  
  Técnica de otimização de compiladores que “desenrola” laços de repetição, reduzindo o overhead de controle (testes e saltos)
  e melhorando a paralelização do processador.

- **Tabelas de Consulta (Lookup Tables)**  
  Pré-calcula resultados de operações caras e armazena em uma tabela. Troca tempo de processamento por espaço de memória
  (ex.: seno, cosseno, fatorial).

- **Problema do Caixeiro Viajante (Traveling Salesman Problem – TSP)**  
  Encontrar o caminho mais curto que visita todas as cidades exatamente uma vez e retorna à origem.  
  **Complexidade**: NP-Completo. Soluções exatas são inviáveis para grandes instâncias; usa-se aproximação ou metaheurísticas.

- **Problema da Mochila (Knapsack Problem)**  
  Dado um conjunto de itens com peso e valor, maximizar o valor total sem exceder a capacidade da mochila.  
  Versões: 0/1 Knapsack, Fractional Knapsack.

- **Backtracking**  
  Explora todas as possibilidades de forma sistemática, “voltando atrás” quando encontra um caminho inviável. Base de muitos algoritmos de busca.

- **Branch and Bound**  
  Divide o problema em subproblemas (branch) e elimina ramos que não podem produzir solução melhor que a melhor encontrada até o momento (bound). Muito usado em problemas de otimização inteira.

- **Algoritmos Genéticos**  
  Metaheurística inspirada na evolução biológica. Usa seleção, cruzamento e mutação para evoluir uma população de soluções candidatas.

- **Memoization**  
  Técnica de programação dinâmica que armazena resultados de chamadas de função caras para evitar recalcular o mesmo subproblema.

- **Tail Call Optimization (Tail Recursion)**  
  Otimização do compilador que transforma recursão de cauda em iteração, economizando espaço na pilha de chamadas.

## Tipos de Programação / Paradigmas de Otimização

- **Programação Dinâmica**  
  Resolve problemas dividindo-os em subproblemas sobrepostos e resolvendo cada um apenas uma vez (princípio da subestrutura ótima).

- **Programação Dinâmica Recursiva (Top-Down)**  
  Abordagem recursiva com memoization. Começa do problema original e resolve os subproblemas conforme necessário.

- **Programação Dinâmica com Abordagem Regressiva (Bottom-Up)**  
  Constrói a solução de baixo para cima, preenchendo uma tabela iterativamente a partir dos casos base.

- **Algoritmo Guloso (Greedy Algorithm)**  
  Toma a melhor decisão local em cada etapa, esperando que isso leve à solução global ótima. Rápido, mas nem sempre garante o ótimo
  (ex.: Fractional Knapsack).

> Existem inúmeras outras formas de conceitos de otimização, mas deixo aqui uns dos conceito que mais passam despercibidos na programação
> códigos vão muito mais além do que criar códigos.
