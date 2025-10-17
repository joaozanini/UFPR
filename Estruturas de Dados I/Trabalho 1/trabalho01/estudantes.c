#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudantes.h"

// Autor: Carlos Vital
void estudantes_init(ListaEstudantes *lista) {
    lista->head = NULL;
    lista->tamanho = 0;
}

// Autor: Carlos Vital
int estudantes_adicionar(ListaEstudantes *lista, int ra, const char *nome, const char *turma) {
    if (!lista) return 0;
    if (estudantes_buscar(lista, ra)) return 0; // RA duplicado
    Estudante *e = (Estudante*) malloc(sizeof(Estudante));
    if (!e) return 0;
    e->ra = ra;
    strncpy(e->nome, nome, sizeof(e->nome)-1); e->nome[sizeof(e->nome)-1] = '\0';
    strncpy(e->turma, turma, sizeof(e->turma)-1); e->turma[sizeof(e->turma)-1] = '\0';
    e->ocorrencias = lista_criar();
    if (!e->ocorrencias) { free(e); return 0; }
    e->next = lista->head;
    lista->head = e;
    lista->tamanho++;
    return 1;
}

// Autor: João Zanini
Estudante* estudantes_buscar(ListaEstudantes *lista, int ra) {
    for (Estudante *e = lista->head; e; e = e->next) {
        if (e->ra == ra) return e;
    }
    return NULL;
}

// Autor: Carlos Vital
void estudantes_listar(ListaEstudantes *lista) {
    printf("\n-- Estudantes cadastrados (%d) --\n", lista->tamanho);
    for (Estudante *e = lista->head; e; e = e->next) {
        printf("RA: %d | Nome: %s | Turma: %s | Ocorrencias: %d\n", e->ra, e->nome, e->turma, e->ocorrencias ? e->ocorrencias->tamanho : 0);
    }
}

// Autor: Cayo Vinícius
void estudantes_destruir(ListaEstudantes *lista) {
    Estudante *e = lista->head;
    while (e) {
        Estudante *prox = e->next;
        if (e->ocorrencias) lista_destruir(e->ocorrencias);
        free(e);
        e = prox;
    }
    lista->head = NULL;
    lista->tamanho = 0;
}
