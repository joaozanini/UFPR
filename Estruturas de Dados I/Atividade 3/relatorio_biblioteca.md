# Relatório Final da Atividade Prática Integradora — Estruturas de Dados

**Nome do Projeto:** Sistema de Biblioteca Universitária

---

## 1. Qual estrutura foi implementada?

Foram implementadas as três estruturas pedidas no enunciado:

- **Lista Estática:** usa um array de tamanho fixo (`CAPACIDADE_MAXIMA`). Os livros são guardados em sequência até o limite definido.
- **Lista Dinâmica:** usa um array que aumenta de tamanho quando fica cheio (geralmente dobra a capacidade). Assim, permite armazenar mais livros sem limite fixo.
- **Lista Encadeada:** formada por nós, onde cada nó guarda os dados de um livro e um ponteiro para o próximo. A memória é alocada separadamente para cada livro.

---

## 2. Quais funcionalidades foram concluídas?

Todas as funções pedidas foram feitas em cada estrutura:

- ✅ **Cadastrar livros:** adicionar novos livros.
- ✅ **Consultar pelo ISBN:** buscar um livro específico.
- ✅ **Emprestar livros:** marcar como "Emprestado" e registrar o leitor.
- ✅ **Devolver livros:** marcar como "Disponível".
- ✅ **Listar todos os livros:** mostrar todo o acervo.

---

## 3. O que foi mais fácil e mais difícil?

- **Mais fácil:** Lista Estática — simples de implementar, já que é só controlar os índices do array.
- **Mais difícil:** Lista Encadeada — foi necessário lidar com ponteiros, alocação dinâmica de memória e percorrer a lista para inserir ou modificar itens.

---

## 4. Quando cada estrutura é mais útil?

- **Lista Estática:** boa para quando o número de livros é pequeno e fixo, sem muitas mudanças. Exemplo: uma coleção pessoal. É rápida e simples.
- **Lista Dinâmica:** boa para quando o número de livros cresce aos poucos. Une rapidez no acesso e flexibilidade no tamanho.
- **Lista Encadeada:** funciona bem quando há muitas inserções e remoções. Apesar de ser lenta para buscas, é mais eficiente para gerenciar memória em situações com muitas mudanças.

---

## 5. Como foi o desempenho com 50, 500 e 5.000 livros?

### Cadastro
- **Estática e Dinâmica:** muito rápidas, inserção em tempo constante (O(1)).
    - A dinâmica só fica lenta quando precisa aumentar o array.
- **Encadeada:** mais lenta, pois precisa percorrer toda a lista para inserir no final (O(n)).

### Busca, Empréstimo e Devolução (pior caso)
- Nas três, o tempo foi parecido.
- Sempre é necessário percorrer a lista para encontrar o livro pelo ISBN (**O(n)**).
- Quanto mais livros, mais demorado.

---

## 6. Quais operações foram mais custosas?

- **Em todas:** a busca por ISBN foi a mais lenta, já que não há acesso direto.
- **Na Lista Dinâmica:** o redimensionamento do array foi pesado, mas aconteceu poucas vezes.
- **Na Lista Encadeada:** a inserção no final foi custosa, porque exige percorrer todos os elementos.

---

## 7. Usaria em um sistema real?

- **Lista Estática:** ❌ **Não.** O limite fixo não serve para uma biblioteca de verdade.
- **Lista Encadeada:** ❌ **Não.** A busca linear (O(n)) é muito lenta para milhares de livros.
- **Lista Dinâmica:** ⚠️ **Talvez.** Serve para um protótipo ou sistema pequeno, mas ainda tem o problema da busca lenta.

---

## Conclusão

Para um sistema real de biblioteca universitária, nenhuma dessas três é a melhor opção.  
O ideal seria usar uma **Árvore de Busca Balanceada** ou uma **Tabela Hash**, que permitem encontrar livros pelo ISBN muito mais rápido, em tempo médio constante (**O(1)**).

---

## Equipe

- Felipe Matheus Laskos
- João Vitor Zanini Pedro
