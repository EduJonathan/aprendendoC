# ESTRUTURAS DE DADOS

## 📌 INTRODUÇÃO

Estruturas de dados são abstrações utilizadas na programação para representar e organizar
informações de maneira eficiente. Elas permitem modelar dados do mundo real e são fundamentais
para a construção de algoritmos, pois impactam diretamente no desempenho das aplicações.
Compreender suas características e aplicabilidades é essencial para resolver
problemas de forma eficiente em qualquer linguagem de programação.

Essas estruturas podem representar modelos como:

1. Árvores, para hierarquias.
2. Listas, para sequências ordenadas.
3. Dicionários, para pares chave-valor.

Cada estrutura possui vantagens e desvantagens dependendo do tipo de operação desejada:

- inserção
- remoção
- busca
- ordenação.

---

## 📌 TIPOS DE ESTRUTURAS DE DADOS

### Estruturas Lineares

São aquelas onde os dados são armazenados de forma sequencial, isso significa que cada
elemento(exceto o primeiro e o último) tem um predecessor e um sucessor. Ou seja, a
estrutura é organizada como uma linha, onde os elementos podem ser acessados de forma
sequencial.
Exemplos incluem listas, pilhas, filas. Elas são ótimas para quando você precisa de acesso sequencial e ordem fixa.

✅ Vantagens das Estruturas Lineares

- São simples de implementar e entender, o que facilita o aprendizado e o uso.
- Permitem acesso sequencial e, em alguns casos, acesso direto (como em arrays).
- O uso da memória pode ser eficiente, especialmente em arrays.
- São úteis em algoritmos que exigem processamento em ordem definida como filas de tarefas
  ou pilhas de execução.

⚠️ Desvantagens das Estruturas Lineares

- Inserções e remoções frequentes podem ser ineficientes, especialmente em arrays.
- Em estruturas como listas encadeadas, o acesso aos elementos pode ser mais lento (tempo linear).
- Arrays de tamanho fixo exigem realocação quando precisam crescer.
- Menor flexibilidade comparada a estruturas mais complexas, como árvores ou grafos.

---

## 📜 Listas vs Listas Encadeadas

### 📃 LISTAS (Array ou Lista Dinâmica)

Em uma lista (ou array), os elementos são armazenados em blocos de memória contíguos.
Isso significa que a memória é alocada de forma contínua, e os elementos estão próximos
uns dos outros.  
Use Array quando: O tamanho é conhecido e fixo, Precisa de acesso rápido por índice,
Faz muitas buscas e poucas modificações.

### 🔗 LISTAS ENCADEADA

Em uma lista encadeada, os elementos (ou nós/nodes) são armazenados de forma descontínua
na memória. Cada nó contém um valor e uma referência (ou ponteiro) para o próximo nó na sequência.
Assim, a memória não precisa ser contígua; o próximo nó pode estar em qualquer parte da memória.  
Use Lista Encadeada quando: O tamanho é dinâmico, Faz muitas inserções/remoções, Não precisa
de acesso randômico frequente.

### DIFERENÇAS DAS LISTAS

| **Propriedade**      | **Lista (Array)**                                | **Lista Encadeada**                               |
| -------------------- | ------------------------------------------------ | ------------------------------------------------- |
| Armazenamento        | Memória contígua                                 | Memória não contígua (espaço livre na memória)    |
| Acesso aos Elementos | O(1) com índice                                  | O(n) (precisa percorrer a lista)                  |
| Inserção/Remoção     | O(n) no meio ou início                           | O(1) no início (mas O(n) se necessário percorrer) |
| Memória              | Mais eficiente em termos de uso                  | Requer mais memória por nó (ponteiro adicional)   |
| Desvantagens         | Realocação de memória, deslocamento de elementos | Acesso lento e uso de mais memória                |

---

## 📚 PILHAS (STACK)

A pilha segue o princípio LIFO (Last In, First Out): O último elemento adicionado é o primeiro
a ser removido. Pense em uma pilha de pratos ou uma pilha de livros — o último prato
colocado na pilha será o primeiro a ser retirado.
Use pilha quando precisar do comportamento LIFO, Implementando recursão ou undo/redo,
Processando expressões aninhadas.

- Características: Acesso apenas ao topo da pilha.
- Operações principais: push (empilhar) e pop (desempilhar).
- Aplicações: Recursão, controle de desfazer/refazer e avaliação de expressões matemáticas.
- Chamadas de função (call stack).
- Avaliação de expressões.

---

## 🚶🚶‍♀️🚶‍♂️ FILA (QUEUE)

A fila segue o princípio FIFO (First In, First Out): o primeiro elemento a ser adicionado
é o primeiro a ser removido. Uma fila funciona como a fila de espera em um banco ou a fila
de processos em um sistema operacional.
Use Fila quando: Precisa do comportamento FIFO, Gerencia recursos compartilhados,
Processa elementos na ordem de chegada.

- Características: Acesso apenas ao primeiro elemento da fila.
- Operações principais: enqueue (enfileirar) e dequeue (desenfileirar).
- Aplicações: Impressoras(gestão de tarefas), Filas de processos em sistemas operacionais e
  transmissão de pacotes em redes.

---

## 🌐 Sites online para Estruturas de Dados

Para praticar e visualizar diferentes algoritmos e estruturas de dados, você pode acessar os seguintes sites interativos:

### Este site oferece uma interface visual para explorar diversos algoritmos, como ordenação, busca, e estruturas de dados, permitindo ver como eles funcionam em tempo real à medida que os dados são processados

### 1. [VisuAlgo](https://visualgo.net/en)

VisuAlgo é uma plataforma muito popular para visualizar algoritmos e estruturas de dados de forma interativa. Ele cobre uma grande variedade de tópicos, desde buscas e ordenações até algoritmos de grafos e árvores binárias.

### 2. [Pythontutor](http://pythontutor.com/)

Embora o Pythontutor seja principalmente voltado para Python, ele permite que você visualize
a execução de qualquer código de maneira interativa. É ótimo para entender como variáveis
e estruturas de dados são manipuladas durante a execução.

### 3. [Algorithm Visualizer](https://algorithm-visualizer.org/)

Um site de código aberto que visualiza uma ampla gama de algoritmos. Oferece uma interface
fácil de usar para ver como os algoritmos funcionam e como as estruturas de dados mudam durante
a execução.

### 4. [Data Structure Visualizations](https://www.cs.usfca.edu/~galles/visualization/StacksQueue.html)

Esse site oferece uma boa visualização de diferentes estruturas de dados como
pilhas (stacks), filas (queues), listas duplamente encadeadas, entre outros.

### 5. [The Algorithm Design Manual](http://www.algorist.com/)

Embora seja mais focado em teoria, esse site oferece algumas visualizações e
recursos interativos que são úteis para quem quer estudar algoritmos com mais profundidade.

### 7. [GeeksforGeeks Visualizations](https://www.geeksforgeeks.org/data-structures/)

Embora o GeeksforGeeks seja mais conhecido por tutoriais e artigos, também oferece algumas
visualizações e implementações de estruturas de dados e algoritmos, o que pode ser muito
útil para quem está começando.

### 8. [LeetCode Visualizer](https://leetcode.com/)

Embora o LeetCode seja mais focado em desafios de programação, ele também oferece
uma ferramenta para visualizar soluções de algoritmos, o que pode ser útil para ver
como diferentes soluções se comportam em tempo real.

---

## 🎯 Conclusão

Dominar estruturas de dados lineares é fundamental para:

- Escrever código eficiente.
- Escolher a melhor solução para cada problema.
- Entender algoritmos mais complexos.
- Cada estrutura tem seu propósito ideal - entender suas características
  e saber quando aplicá-las para obter o melhor desempenho em seu código.
