#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct No {
    int dado;
    struct No* anterior;
    struct No* proximo;
} No;

type def struct ListaDupla {
    No* cabeca;
    No* cauda;
    int tamanho
} ListaDupla;

// Funções básicas
ListaDupla* criarListaDupla();
void destruirListaDupla(ListaDupla* lista);
int estaVazia(ListaDupla* lista);
int tamanho(ListaDupla* lista);

// Operações de inserção
void inserirInicio(ListaDupla* lista, int valor);
void inserirFim(ListaDupla* lista, int valor);
void inserirPosicao(ListaDupla* lista, int valor, int posicao);

// Operações de remocao
int removerInicio(ListaDupla* lista);
int removerFim(ListaDupla* lista);
int removerPosicao(ListaDupla* lista, int posicao);
int removerValor(ListaDupla* lista, int valor);

// Operações de busca
No* buscar(ListaDupla* lista, int valor);
int buscarPosicao(ListaDupla* lista, int valor);

// Operações de exibição
void exibirFrente(ListaDupla* lista);
void exibirTras(ListaDupla* lista);

#endif