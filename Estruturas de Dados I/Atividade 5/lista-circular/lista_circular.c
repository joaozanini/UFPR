#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

// Função para criar uma nova lista circular
ListaCircular* criarListaCircular() {
    ListaCircular* novaLista = (ListaCircular*)malloc(sizeof(ListaCircular));
    if (novaLista != NULL) {
        novaLista->ultimo = NULL;
        novaLista->tamanho = 0;
    }
    return novaLista;
}

// Função para destruir lista circular
void destruirListaCircular(ListaCircular* lista) {
    if (lista == NULL || lista->ultimo == NULL) {
        free(lista);
        return;
    }

    NoCircular* primeiro = lista->ultimo->proximo;
    NoCircular* atual = primeiro;
    NoCircular* proximo;

    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != primeiro);

    free(lista);
}

// Função para verificar se está vazia
int estaVaziaListaCircular(ListaCircular* lista) {
    return (lista == NULL || lista->ultimo == NULL);
}

// Função para obter o tamanho
int tamanhoCircular(ListaCircular* lista) {
    return (lista == NULL) ? 0 : lista->tamanho;
}

// Inserir no início
void inserirInicioCircular(ListaCircular* lista, int valor) {
    if (lista == NULL) return;

    NoCircular* novoNo = (NoCircular*)malloc(sizeof(NoCircular));
    if (novoNo == NULL) return;

    novoNo->dado = valor;

    if (estaVaziaListaCircular(lista)) {
        novoNo->proximo = novoNo;
        lista->ultimo = novoNo;
    } else {
        novoNo->proximo = lista->ultimo->proximo;
        lista->ultimo->proximo = novoNo;
    }

    lista->tamanho++;
}

// Inserir no final
void inserirFimCircular(ListaCircular* lista, int valor) {
    if (lista == NULL) return;

    NoCircular* novoNo = (NoCircular*)malloc(sizeof(NoCircular));
    if (novoNo == NULL) return;

    novoNo->dado = valor;

    if (estaVaziaListaCircular(lista)) {
        novoNo->proximo = novoNo;
        lista->ultimo = novoNo;
    } else {
        novoNo->proximo = lista->ultimo->proximo;
        lista->ultimo->proximo = novoNo;
        lista->ultimo = novoNo;
    }

    lista->tamanho++;
}

// Inserir em posição específica
void inserirPosicaoCircular(ListaCircular* lista, int valor, int posicao) {
    if (lista == NULL || posicao < 0 || posicao > lista->tamanho) return;

    if (posicao == 0) {
        inserirInicioCircular(lista, valor);
        return;
    }
    if (posicao == lista->tamanho) {
        inserirFimCircular(lista, valor);
        return;
    }

    NoCircular* novoNo = (NoCircular*)malloc(sizeof(NoCircular));
    if (novoNo == NULL) return;

    novoNo->dado = valor;
    NoCircular* atual = lista->ultimo->proximo;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
    lista->tamanho++;
}

// Remover do início
int removerInicioCircular(ListaCircular* lista) {
    if (lista == NULL || estaVaziaListaCircular(lista)) return -1;

    NoCircular* primeiro = lista->ultimo->proximo;
    int valor = primeiro->dado;

    if (lista->tamanho == 1) {
        free(primeiro);
        lista->ultimo = NULL;
    } else {
        lista->ultimo->proximo = primeiro->proximo;
        free(primeiro);
    }

    lista->tamanho--;
    return valor;
}

// Remover do fim
int removerFimCircular(ListaCircular* lista) {
    if (lista == NULL || estaVaziaListaCircular(lista)) return -1;

    if (lista->tamanho == 1) {
        return removerInicioCircular(lista);
    }

    NoCircular* penultimo = lista->ultimo->proximo;
    while (penultimo->proximo != lista->ultimo) {
        penultimo = penultimo->proximo;
    }

    int valor = lista->ultimo->dado;
    penultimo->proximo = lista->ultimo->proximo;
    free(lista->ultimo);
    lista->ultimo = penultimo;
    lista->tamanho--;

    return valor;
}

// Remover por posição
int removerPosicaoCircular(ListaCircular* lista, int posicao) {
    if (lista == NULL || estaVaziaListaCircular(lista) ||
        posicao < 0 || posicao >= lista->tamanho) return -1;

    if (posicao == 0) return removerInicioCircular(lista);
    if (posicao == lista->tamanho - 1) return removerFimCircular(lista);

    NoCircular* atual = lista->ultimo->proximo;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    NoCircular* removido = atual->proximo;
    int valor = removido->dado;
    atual->proximo = removido->proximo;
    free(removido);
    lista->tamanho--;

    return valor;
}

// Remover por valor
int removerValorCircular(ListaCircular* lista, int valor) {
    if (lista == NULL || estaVaziaListaCircular(lista)) return -1;

    NoCircular* atual = lista->ultimo->proximo;
    NoCircular* anterior = lista->ultimo;

    do {
        if (atual->dado == valor) {
            if (atual == lista->ultimo->proximo) return removerInicioCircular(lista);
            if (atual == lista->ultimo) return removerFimCircular(lista);

            anterior->proximo = atual->proximo;
            free(atual);
            lista->tamanho--;
            return valor;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != lista->ultimo->proximo);

    return -1;
}

// Buscar nó por valor
NoCircular* buscarCircular(ListaCircular* lista, int valor) {
    if (lista == NULL || estaVaziaListaCircular(lista)) return NULL;

    NoCircular* atual = lista->ultimo->proximo;
    do {
        if (atual->dado == valor) return atual;
        atual = atual->proximo;
    } while (atual != lista->ultimo->proximo);

    return NULL;
}

// Buscar posição por valor
int buscarPosicaoCircular(ListaCircular* lista, int valor) {
    if (lista == NULL || estaVaziaListaCircular(lista)) return -1;

    NoCircular* atual = lista->ultimo->proximo;
    int pos = 0;
    do {
        if (atual->dado == valor) return pos;
        atual = atual->proximo;
        pos++;
    } while (atual != lista->ultimo->proximo);

    return -1;
}

// Exibir lista circular
void exibirCircular(ListaCircular* lista) {
    if (lista == NULL || estaVaziaListaCircular(lista)) {
        printf("Lista vazia\n");
        return;
    }

    NoCircular* atual = lista->ultimo->proximo;
    do {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    } while (atual != lista->ultimo->proximo);
    printf("\n");
}
