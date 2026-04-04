# 📌 Variações de Estruturas de Dados

As estruturas de dados podem ser modificadas e adaptadas para atender diferentes requisitos.
A complexidade do código, características e o comportamento das operações podem variar,
dependendo da variação da estrutura adotada. Abaixo estão algumas variações populares com
suas características, vantagens e desvantagens.

---

## 📜 LISTAS

### 🔗 Listas Encadeadas

- **Estrutura**: Cada nó contém um valor e um ponteiro para o próximo nó na lista.

✅ Vantagens:

- Inserção e remoção eficientes, pois não há necessidade de mover elementos, como em arrays.

⚠️ Desvantagens:

- Acesso aos elementos é mais lento comparado a arrays, já que não há acesso direto por índice.

---

### 🔄 Lista Duplamente Encadeada (Doubly Linked List)

- **Estrutura**: Cada nó possui dois ponteiros: um para o próximo nó e outro para o nó anterior.

✅ Vantagens:

- Inserção e remoção mais eficientes do que em listas simples, especialmente quando é necessário adicionar ou remover no meio da lista.
- Navegação bidirecional: você pode percorrer a lista tanto do início ao fim quanto do fim ao início.

⚠️ Desvantagens:

- Maior uso de memória devido ao ponteiro adicional (para o nó anterior).

---

### 🔁 Lista Circular (Circular Linked List)

- **Estrutura**: O último nó da lista encadeada aponta para o primeiro nó, criando um ciclo contínuo.

✅ Vantagens:

- **Ciclo infinito**: útil em aplicações circulares, como buffers de dados e agendadores de processos.

⚠️ Desvantagens:

- Mais difícil de implementar, pois é necessário lidar com a condição de ciclo no final da lista, tornando a lógica mais complexa.

---

## 🚶🚶‍♀️🚶‍♂️ FILA (QUEUE)

### 🔄 Fila Circular (Circular Queue)

- **Estrutura**: Variante da fila, onde, ao alcançar o final, o ponteiro da fila volta ao início, reutilizando o espaço livre após a remoção de elementos.

✅ Vantagens:

- **Eficiência no uso de memória**: reutiliza o espaço de forma eficiente.
- **Desempenho constante (O(1))**: operações de inserção e remoção são rápidas, sem necessidade de mover elementos quando a fila é cheia.
- Ideal para **buffers de dados** em sistemas de I/O e transmissão de dados.

⚠️ Desvantagens:

- **Controle de tamanho**: necessita de monitoramento constante do tamanho da fila e de lógica adicional para gerenciar condições de fila cheia ou vazia.

---

### ⚖️ Fila de Prioridade (Priority Queue)

- **Estrutura**: Fila onde os elementos são removidos com base em sua prioridade, não na ordem de inserção.

✅ Vantagens:

- **Controle de prioridade**: elementos de maior prioridade são processados primeiro.
- Usada em algoritmos como **Dijkstra**, onde a busca leva em consideração prioridades ou custos.
- **Flexibilidade**: operações de inserção e remoção podem ser baseadas na prioridade dos elementos.

⚠️ Desvantagens:

- **Complexidade de implementação**: pode envolver estruturas mais complexas como **heaps** (min-heap ou max-heap).
- **Desempenho inferior** a filas simples (O(log n) para inserções e remoções em heaps).
- Pode ser necessário **ordenar os elementos** pela prioridade, o que aumenta o custo.

---

### ⬆️ Deque (Double-Ended Queue)

- **Estrutura**: Fila que permite inserção e remoção de elementos tanto no início quanto no fim (FIFO e LIFO).

✅ Vantagens:

- **Flexibilidade**: permite manipulação dos dois lados da fila, o que torna a estrutura mais versátil.
- **Desempenho constante (O(1))** para operações de inserção e remoção em ambas as extremidades.
- Excelente para **algoritmos de janela deslizante** ou **busca em largura** (BFS), onde a manipulação de ambos os lados é necessária.

⚠️ Desvantagens:

- **Maior complexidade** que uma fila simples, especialmente quando implementado de forma genérica.
- **Uso de memória maior**: precisa manter referências para ambos os extremos.

---

## 📚 PILHAS (STACK)

### ⚠️ Observação: Pilha de Tamanho Fixo

- **Estrutura**: Pilha com capacidade limitada, onde se atingir o limite, uma exceção é gerada ou a pilha precisa ser expandida.

✅ Vantagens:

- Evita problemas de estouro de memória em situações controladas.

⚠️ Desvantagens:

- A pilha fica limitada, e a implementação de expansão ou controle de exceções pode tornar o código mais complexo.

---

## 💡 Dicas de Aplicação

- Lista Dupla: Ideal para navegação reversa (ex: histórico de navegação).
- Fila Circular: Sistemas embarcados com memória limitada.
- Fila de Prioridade: Algoritmos de Dijkstra, sistemas de tarefas.
- Deque: Algoritmos de janela deslizante, caches LRU

---

## 🔮 Tendências Modernas

- Estruturas Persistentes: Versões imutáveis para programação funcional.
- Estruturas Concurrentes: Para programação paralela (ex: deque thread-safe).
- Estruturas Compressas: Para big data (ex: listas encadeadas com compactação).
