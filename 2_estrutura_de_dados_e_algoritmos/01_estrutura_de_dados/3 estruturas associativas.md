# 📌 Estruturas Associativas

As estruturas associativas são tipos de dados que associam **chaves a valores**. Cada chave
é **única** e mapeia para um valor específico. Essas estruturas são altamente eficientes
para **busca, inserção e remoção**, sendo implementadas de diferentes formas, como
**tabelas de hash**, **árvores balanceadas**, entre outras.

Principais estruturas:

- Hash Tables (Tabelas de Dispersão)
- Maps (Mapas Associativos)
- Dicts (Dicionários)
- Sets (Conjuntos)

---

✅ Vantagens

- Acesso direto e eficiente por meio de chaves (lookup geralmente O(1)).
- Armazenamento intuitivo de pares chave-valor.
- Suporte a funcionalidades como contagem, agrupamento e prioridade.
- Utilidade em algoritmos como memorização, contagem de frequência e cache.
- Variantes ordenadas (como `OrderedMap`) mantêm os dados organizados automaticamente.

⚠️ Desvantagens

- Ordem dos elementos não garantida em estruturas baseadas em hash.
- Maior uso de memória para manter o desempenho.
- Iteração ordenada pode não ser eficiente ou disponível.
- Implementação complexa em casos como `multimap` ou `priority_queue` com comparadores.
- Chaves precisam ser comparáveis ou "hashable", limitando os tipos aceitos.

---

## 📖 Dicionário (ou Mapa Associativo)

- **Estrutura**: Pares chave-valor com chaves únicas.
- **Implementação comum**: Tabela de hash ou árvore de busca.

✅ Vantagens

- Acesso, inserção e remoção rápidos (O(1) em média).
- Simples e amplamente suportado.

⚠️ Desvantagens

- Degradação de desempenho em caso de colisões.
- Ordem dos elementos não garantida (exceto em versões ordenadas).

---

## 📦 Set (Conjunto)

- **Estrutura**: Coleção de elementos únicos e não ordenados.
- **Implementação comum**: Tabela de hash ou árvore balanceada.

✅ Vantagens

- Verificação de existência eficiente (O(1)).
- Garante unicidade dos elementos.
- Suporte a operações como união, interseção e diferença.

⚠️ Desvantagens

- Sem ordenação (em `HashSet`, por exemplo).
- Uso de memória maior que arrays.
- Aceita apenas tipos `hashable` (geralmente imutáveis).

---

## 🔢 Tabela de Dispersão (Hash Table)

- **Estrutura**: Usa função hash para mapear chaves a índices em um array.
- **Desempenho**: O(1) em média; O(n) no pior caso (colisões).

✅ Vantagens

- Acesso, inserção e remoção muito rápidos.
- Base para dicionários em muitas linguagens.

⚠️ Desvantagens

- Necessita de estratégia para resolução de colisões (ex: encadeamento).
- Qualidade da função hash impacta desempenho.
- Não mantém ordem dos elementos.

---

## 🗺️ Mapa Ordenado (Tree Map / Ordered Map)

- **Estrutura**: Implementado com árvore binária de busca balanceada (AVL ou Rubro-Negra).
- **Desempenho**: O(log n) para inserção, busca e remoção.

✅ Vantagens

- Mantém os elementos ordenados.
- Permite operações baseadas em intervalos (mínimo, máximo, sucessor, etc.).

⚠️ Desvantagens

- Mais lento que hash tables para acessos diretos.
- Requer mais memória e lógica para balanceamento.

---

## 🧠 Tabela de Símbolos (Symbol Table)

- **Estrutura**: Usada principalmente em compiladores; mapeia identificadores a dados (tipo, escopo, etc.).
- **Implementação**: Pode ser feita com hash tables ou árvores.

✅ Vantagens

- Essencial para análise semântica e controle de escopo em compiladores.
- Suporte a escopos aninhados (por pilhas de dicionários, por exemplo).

⚠️ Desvantagens

- Implementação mais complexa com múltiplos escopos.
- Uso específico (não é uma estrutura de uso geral).

---

## 🚀 Aplicações Práticas

- Caches: Hash tables para acesso rápido a dados.
- Contagem de frequência: Dicionários para contar ocorrências.
- Bancos de dados: Índices como estruturas associativas.
- Compiladores: Tabelas de símbolos para análise semântica.
- Sistemas distribuídos: Mapeamento de chaves a nós

---

## ❗ Considerações de Implementação

- Escolha de função hash: Crucial para desempenho em tabelas de dispersão.
- Tratamento de colisões: Encadeamento vs. endereçamento aberto.
- Balanceamento de árvores: AVL vs. Rubro-Negras para mapas ordenados.
- Tipos de chaves: Necessidade de serem comparáveis ou hashables.

---

## 🔮 CONCLUSÃO

As estruturas associativas continuam evoluindo, mantendo-se essenciais para algoritmos
e sistemas eficientes.
