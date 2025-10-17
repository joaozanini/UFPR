#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct NoCircular {
    int dado;
    struct NoCircular* proximo;
} NoCircular;

typedef struct ListaCircular {
    NoCircular* ultimo;
    int tamanho;
} ListaCircular;

// Funções básicas
ListaCircular* criarListaCircular();
void destruirListaCircular(ListaCircular* lista);
int estaVaziaListaCircular(ListaCircular* lista);
int tamanhoCircular(ListaCircular* lista);

// Operações de inserção
void inserirInicioCircular(ListaCircular* lista, int valor);
void inserirFimCircular(ListaCircular* lista, int valor);
void inserirPosicaoCircular(ListaCircular* lista, int valor, int posicao);

// Operações de remoção
int removerInicioCircular(ListaCircular* lista);
int removerFimCircular(ListaCircular* lista);
int removerPosicaoCircular(ListaCircular* lista, int posicao);
int removerValorCircular(ListaCircular* lista, int valor);

// Operações de busca
NoCircular* buscarCircular(ListaCircular* lista, int valor);
int buscarPosicaoCircular(ListaCircular* lista, int valor);

// Operação de exibição
void exibirCircular(ListaCircular* lista);

#endif
