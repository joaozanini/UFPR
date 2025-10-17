#ifndef ESTUDANTES_H
#define ESTUDANTES_H

#include "lista.h"

typedef struct Estudante {
    int ra;
    char nome[100];
    char turma[20];
    ListaOcorrencias *ocorrencias; // lista duplamente encadeada de ocorrencias
    struct Estudante *next; // lista simples de estudantes
} Estudante;

typedef struct {
    Estudante *head;
    int tamanho;
} ListaEstudantes;

// Autor: Carlos Vital
// Inicializa lista de estudantes vazia.
void estudantes_init(ListaEstudantes *lista);

// Autor: Carlos Vital
// Adiciona novo estudante no inicio se RA ainda nao existe. Retorna 1 sucesso, 0 duplicado ou erro.
int estudantes_adicionar(ListaEstudantes *lista, int ra, const char *nome, const char *turma);

// Autor: João Zanini
// Busca estudante por RA. Retorna ponteiro ou NULL.
Estudante* estudantes_buscar(ListaEstudantes *lista, int ra);

// Autor: Carlos Vital
// Lista todos os estudantes (apenas cabecalhos) em stdout.
void estudantes_listar(ListaEstudantes *lista);

// Autor: Cayo Vinícius
// Libera memoria de todos os estudantes e suas listas de ocorrencias.
void estudantes_destruir(ListaEstudantes *lista);

#endif
