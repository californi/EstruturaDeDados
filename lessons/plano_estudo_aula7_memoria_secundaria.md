### Aula 7: Estruturas de Dados em Memória Secundária: Organização de Arquivos, Representação e Manipulação de Dados, e Indexação

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender a necessidade de estruturas de dados em memória secundária.
*   Entender os conceitos básicos de organização de arquivos (sequencial, direto, indexado).
*   Conhecer as técnicas de representação e manipulação de dados em disco.
*   Dominar os princípios de indexação para acesso eficiente a dados.
*   Compreender o funcionamento de Árvores B e suas generalizações (B+, B*).
*   Entender as técnicas de espalhamento (Hash Tables) para armazenamento e recuperação de dados.
*   Analisar a complexidade de tempo das operações em diferentes estruturas de dados em memória secundária.

---

#### 1. Introdução à Memória Secundária e Organização de Arquivos (20 minutos)

**1.1. Por que Memória Secundária?**

Até agora, focamos em estruturas de dados que residem principalmente na memória principal (RAM). No entanto, a memória principal é volátil (perde dados ao desligar) e limitada em capacidade. Para armazenar grandes volumes de dados de forma persistente, utilizamos a **memória secundária** (discos rígidos, SSDs, etc.).

**Desafios da Memória Secundária:**
*   **Latência:** Acesso a dados em disco é ordens de magnitude mais lento que na RAM.
*   **Blocos/Páginas:** Dados são lidos e escritos em blocos ou páginas, não byte a byte.
*   **Persistência:** Dados permanecem mesmo após o desligamento.

**1.2. Organização de Arquivos:**

A forma como os registros são armazenados em um arquivo afeta diretamente a eficiência das operações de acesso, inserção, remoção e atualização.

*   **Arquivos Sequenciais:** Registros são armazenados um após o outro, em ordem de inserção ou por uma chave. Acesso a um registro específico requer a leitura de todos os registros anteriores (O(N)). Bom para processamento em lote.
*   **Arquivos Diretos (ou Hashing):** A posição de um registro é determinada por uma função de hashing aplicada à sua chave. Permite acesso muito rápido (O(1) em média) se não houver colisões. Discutiremos mais em Hash Tables.
*   **Arquivos Indexados:** Mantém um índice separado que aponta para a localização dos registros no arquivo principal. O índice é geralmente menor e pode ser mantido em memória principal ou em estruturas eficientes como árvores B. Permite acesso rápido a registros específicos.

**Exemplo Conceitual (Organização Sequencial):**

Imagine um arquivo `alunos.txt` onde cada linha é um registro:

```
ID:101,Nome:Ana,Curso:Engenharia
ID:102,Nome:Bruno,Curso:Medicina
ID:103,Nome:Carla,Curso:Direito
```

Para encontrar 

