# Algoritmos de Busca (Search)

Algoritmos de busca são métodos que permitem localizar um determinado valor dentro de uma estrutura de dados, como arrays, listas ou matrizes. Cada algoritmo possui características próprias, com vantagens, desvantagens e diferentes complexidades de tempo e espaço.

---

## Parâmetros principais em qualquer busca

1. **Valor alvo**: o elemento que queremos encontrar.
2. **Tamanho da estrutura**: geralmente denotado por `n`.
3. **Complexidade do algoritmo**: relacionada ao tempo de execução da busca.
4. **Principais tarefas de busca**:
   - **Comparações:** comparar o valor alvo com os elementos da estrutura (ex.: Busca Linear).
   - **Divisão:** dividir a estrutura para reduzir a área de pesquisa (ex.: Busca Binária).
   - **Acesso direto:** acessar o valor por meio de uma função de hash (ex.: Busca Hash).

---

## Tipos de algoritmos de busca

### 1. Busca Linear

- **Estrutura de dados:** qualquer lista ou array.
- **Complexidade:** O(n)
- **Descrição:** Percorre cada elemento até encontrar o valor alvo.
- **Vantagem:** Simples, funciona em listas não ordenadas.
- **Desvantagem:** Lenta em listas grandes.

### 2. Busca Binária

- **Estrutura de dados:** lista ou array ordenado.
- **Complexidade:** O(log n)
- **Descrição:** Divide a lista ao meio em cada passo, comparando o valor do meio com o alvo, reduzindo a área de busca.
- **Vantagem:** Muito rápida em listas ordenadas.
- **Desvantagem:** A lista precisa estar ordenada.

### 3. Busca em Tabela Hash

- **Estrutura de dados:** tabela hash.
- **Complexidade:** O(1) em média
- **Descrição:** Utiliza uma função de hash para acessar diretamente o valor alvo.
- **Vantagem:** Busca muito rápida.
- **Desvantagem:** Requer mais memória e cuidados com colisões.

> OBS.: Foram comentados os mais conhecidos porém eficientes porém existem outros algoritmos
