# 🎲 Algoritmos de Ordenação (Sort)

Algoritmos de ordenação são responsáveis por organizar os elementos de uma estrutura de dados,
como arrays ou listas, em uma sequência definida (crescente, decrescente ou outro critério).
Assim como os algoritmos de busca, os de ordenação possuem características próprias e diferentes eficiências,
dependendo da estrutura de dados e do caso de uso.

---

## Parâmetros principais para análise

1. **Número de elementos (`n`)**: determina o tamanho da entrada e influencia a complexidade do algoritmo.
2. **Complexidade do algoritmo**: relacionada ao tempo de execução necessário para ordenar os elementos.
3. **Principais tarefas de ordenação**:
   - **Comparações**: verificam se dois elementos estão na ordem correta (ex.: Bubble Sort, Quick Sort).
   - **Trocas**: realocam elementos de posição; o número de trocas impacta a eficiência (ex.: Bubble Sort, Quick Sort).
   - **Inserções**: inserem elementos na posição correta dentro de uma parte já ordenada (ex.: Insertion Sort).
   - **Divisão e Conquista**: divide a lista em partes menores e reorganiza de forma eficiente (ex.: Merge Sort, Quick Sort).

---

## Tipos de algoritmos de ordenação

### 1. Bubble Sort

- **Estrutura:** qualquer lista ou array.
- **Complexidade:** O(n²) no pior caso
- **Descrição:** Compara elementos adjacentes e troca-os se estiverem na ordem errada, repetindo o processo até a lista estar ordenada.
- **Vantagem:** Fácil de implementar.
- **Desvantagem:** Ineficiente para listas grandes.

### 2. Insertion Sort

- **Estrutura:** qualquer lista ou array.
- **Complexidade:** O(n²) no pior caso, O(n) no melhor caso
- **Descrição:** Insere cada elemento na posição correta dentro da parte já ordenada da lista.
- **Vantagem:** Eficiente para listas pequenas ou quase ordenadas.
- **Desvantagem:** Lento para listas grandes.

### 3. Merge Sort

- **Estrutura:** listas ou arrays.
- **Complexidade:** O(n log n)
- **Descrição:** Usa a estratégia dividir e conquistar: divide a lista em duas metades, ordena cada metade recursivamente e depois combina as duas partes.
- **Vantagem:** Eficiente mesmo para listas grandes.
- **Desvantagem:** Usa memória extra para criar sublistas.

### 4. Quick Sort

- **Estrutura:** listas ou arrays.
- **Complexidade:** O(n log n) médio, O(n²) pior caso
- **Descrição:** Escolhe um pivô, divide os elementos menores à esquerda e maiores à direita, e aplica recursivamente.
- **Vantagem:** Muito rápido na prática.
- **Desvantagem:** Pior caso ocorre quando a lista já está ordenada de forma desfavorável.

> OBS.: Assim como algoritmos de buscas, foram comentados os mais conhecidos, e ordenações possuem muitos outros algoritmos
