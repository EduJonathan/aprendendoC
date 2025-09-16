# 📌 Estruturas Não Lineares

As estruturas não lineares diferem das lineares porque os elementos **não seguem uma sequência única**.
Em vez disso, podem ter **múltiplas ligações entre si**, formando **relações hierárquicas ou interconectadas**, dependendo da estrutura.

---

## 🔎 Características das Estruturas Não Lineares

- **Hierarquia ou Relações Complexas**: Os elementos podem ter múltiplos predecessores e sucessores.
- **Acesso Não Sequencial**: Você pode precisar de técnicas mais complexas para acessar os elementos.
- **Organização Flexível**: Podem ser organizadas de maneira hierárquica ou baseada em relações de proximidade entre elementos.

---

## ✅ Vantagens

- Permitem modelar relações complexas entre dados (ex: árvores genealógicas, rotas, redes).
- Algumas estruturas oferecem ótimo desempenho para operações específicas (busca, ordenação).
- Adequadas para representar problemas do mundo real que não são sequenciais.

## ⚠️ Desvantagens

- Mais difíceis de implementar e entender, especialmente grafos complexos.
- Requerem algoritmos específicos para navegação (DFS, BFS, Dijkstra, etc.).
- Uso de memória pode ser maior, dependendo da estrutura (ex: matrizes de adjacência).

---

## 🌲 Árvores (Trees)

Uma **árvore** é uma estrutura hierárquica composta por nós, onde cada nó possui um valor e pode ter filhos.

Usada para representar:

- Sistemas de arquivos
- Árvores genealógicas
- Algoritmos de busca (como árvores binárias de busca)

---

## 1. **Árvore Binária**

- **Definição**: Cada nó tem no máximo dois filhos (esquerdo e direito).
- **Aplicações**: Base para outras estruturas como pilhas, filas e algoritmos de busca.
- **Vantagens**: Operações eficientes (O(log n)) em árvores balanceadas.
- **Desvantagens**: Pode se degenerar (ficar desbalanceada) e ter desempenho O(n).

---

## 2. **Árvore Binária de Busca (BST)**

- **Definição**: Para cada nó, os filhos à esquerda têm valores menores e os da direita maiores.
- **Aplicações**: Busca, inserção e remoção eficientes.
- **Vantagens**: Complexidade O(log n) quando balanceada.
- **Desvantagens**: Sem balanceamento, pode virar uma lista (O(n)).

---

## 3. **Árvore AVL**

- **Definição**: BST balanceada que garante que as alturas das subárvores de cada nó não diferem em mais de 1.
- **Aplicações**: Sistemas com muitas operações de inserção/remoção.
- **Vantagens**: Mantém O(log n) mesmo após muitas modificações.
- **Desvantagens**: Requer rotações e é mais complexa.

---

## 4. **Árvore Rubro-Negra**

- **Definição**: BST balanceada com nós coloridos (vermelho/preto) e regras para manter o balanceamento.
- **Aplicações**: Implementações de `map` e `set` em Java, C++, etc.
- **Vantagens**: Busca, inserção e remoção em O(log n).
- **Desvantagens**: Mais complexa; exige manipulação de cores e regras.

---

## 5. **Árvore de Patricia**

- **Definição**: Variante comprimida da árvore Trie, que comprime prefixos comuns em um único nó.
- **Aplicações**: Dicionários, autocompletes, busca de strings.
- **Vantagens**: Uso eficiente de espaço, busca rápida.
- **Desvantagens**: Implementação mais complexa.

---

## 6. **Busca em Largura (BFS)**

- **Definição**: Algoritmo de busca usado em árvores e grafos; percorre por níveis.
- **Aplicações**: Redes, caminhos mínimos, problemas de navegação.
- **Vantagens**: Boa para encontrar caminhos mais curtos.
- **Desvantagens**: Não ideal para estruturas muito profundas.

---

## ⚪➡🔴 Grafos (Graphs)

**Grafo** é uma estrutura composta por **vértices (nós)** e **arestas (ligações entre os nós)**. Pode ser:

- **Orientado** ou **não orientado**
- **Ponderado** (com pesos nas arestas) ou **não ponderado**

Usado para representar:

- Redes sociais
- Mapas e rotas
- Conexões web
- Algoritmos de recomendação

---

## 🔁 Variações de Grafos

- **Grafos Dirigidos**: Arestas têm direção.
- **Grafos Não Dirigidos**: Arestas são bidirecionais.
- **Grafos Pesados**: Arestas têm pesos.
- **Grafos Não Pesados**: Arestas sem pesos.
- **Grafos Cíclicos**: Contêm ciclos (caminhos que retornam ao mesmo nó).
- **Grafos Acíclicos**: Sem ciclos (ex: Árvores).

---

## 🚀 Uso Práticos

- Sistemas de Recomendação: Grafos para relacionar usuários e produtos.
- Sistemas de Arquivos: Árvores B/B+ para organização eficiente.
- Roteamento de Redes: Algoritmos como Dijkstra em grafos ponderados.
- Compiladores: Árvores sintáticas para análise de código.
- Inteligência Artificial: Grafos de conhecimento para representar relações.

---

## 👨🏻‍💻 Tendências Modernas

- Grafos de Conhecimento: Para sistemas de IA e buscas semânticas.
- Estruturas Persistentes: Versões imutáveis para programação funcional.
- Estruturas Distribuídas: Para processamento em larga escala (ex: Grafos no Spark).
- Estruturas Probabilísticas: Como árvores de decisão em machine learning.

---

## 🔮 CONCLUSÃO

As estruturas não lineares continuam sendo fundamentais para resolver problemas complexos
em computação, especialmente com o crescimento de aplicações que envolvem relações intrísicas
entre dados.
