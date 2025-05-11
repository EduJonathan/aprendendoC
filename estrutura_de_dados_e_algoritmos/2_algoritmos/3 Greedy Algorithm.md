# Greedy Algorithm

## ⚡ Algoritmo Guloso (Greedy)

Um algoritmo guloso (ou greedy) é um paradigma de solução de problemas que toma
decisões locais ótimas na esperança de que levem a uma solução global ótima. Em cada etapa,
o algoritmo escolhe a melhor opção disponível no momento, sem se preocupar com as consequências
futuras.

---

## 🧠 Como Funciona um Algoritmo Guloso?

Escolha gulosa: em cada passo, escolha a melhor alternativa disponível naquele momento.

1. Validação de viabilidade: certifique-se de que essa escolha leva a uma solução válida.
2. Combinação das escolhas: o resultado final é a combinação das decisões locais feitas ao longo do caminho.

---

## 📋 Características de Problemas Gulosos

Para que um algoritmo guloso funcione corretamente e encontre a solução ótima, o problema precisa ter:

1. Subestrutura ótima  
   A solução ótima do problema completo pode ser construída a partir das soluções ótimas dos subproblemas.

2. Propriedade de escolha gulosa  
   Uma escolha local ótima leva a uma solução ótima global.

⚠ Se qualquer um desses dois critérios falhar, o algoritmo guloso pode não funcionar corretamente.

---

🔹 Exemplos Clássicos

1. Troco com o menor número de moedas (quando as moedas seguem um sistema canônico).
2. Problema da Mochila Fracionária (Knapsack Fracionado).
3. Árvore Geradora Mínima (Prim e Kruskal).
4. Algoritmo de Dijkstra (para grafos com pesos não negativos).
5. Interval Scheduling (escalar o maior número de tarefas sem sobreposição)

---

## 📊 Comparação com Programação Dinâmica

| **Aspecto**                 | **Algoritmo Guloso**             | **Programação Dinâmica**           |
| --------------------------- | -------------------------------- | ---------------------------------- |
| **Escolha**                 | Melhor local (no momento)        | Com base em subproblemas           |
| **Otimalidade**             | Depende da estrutura do problema | Garante solução ótima se aplicável |
| **Complexidade**            | Geralmente menor                 | Pode ser maior (mais memória)      |
| **Reutilização de estados** | Não reutiliza (escolha única)    | Armazena soluções parciais         |

---

## 💡 Vantagens e Desvantagens

✅ Vantagens

- Implementação simples e rápida.
- Frequentemente mais eficiente em tempo e espaço.
- Útil para aproximações em problemas complexos.

❌ Desvantagens

- Nem sempre produz a solução ótima.
- Depende fortemente da estrutura do problema.
- Requer prova matemática para garantir corretude.

---

## ✅ Quando Usar Algoritmos Gulosos

1. O problema tem a propriedade da escolha gulosa.
2. A subestrutura ótima está presente.
3. Soluções aproximadas são aceitáveis (quando a otimalidade não é garantida).
4. Eficiência é crítica.

## 🧪 Prova de Corretude

Para demonstrar que um algoritmo guloso funciona, devemos:

1. Mostrar que a escolha gulosa é segura (não compromete a solução ótima).
2. Demonstrar a propriedade de subestrutura ótima.
3. Provar por indução que as escolhas locais levam a uma solução global ótima.

---

## 🛑 Limitações e Armadilhas

1. Nem sempre garantem a solução ótima global.
2. Aplicabilidade limitada a problemas específicos.
3. Requerem análise cuidadosa para verificar se as propriedades necessárias são satisfeitas.
4. Soluções aproximadas podem não ser suficientes para alguns problemas.

---

## 🔮 Conclusão

Algoritmos gulosos são ferramentas poderosas quando aplicadas a problemas adequados.
Sua simplicidade e eficiência os tornam ideais para muitas situações práticas, especialmente
quando combinados com provas de corretude que garantem sua efetividade.

---

## ❗ Dica Final

Se o problema permite decisões locais que garantem uma solução global ótima sem necessidade
de reavaliar decisões passadas, o algoritmo guloso é uma excelente escolha!
