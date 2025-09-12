#ifndef BIBLIOTECA_LISTA_ENCADEADA_H
#define BIBLIOTECA_LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    LIVRE,
    RETIRADO
} Disponibilidade;

typedef struct {
    char titulo[150];
    char autor[150];
    char codigoISBN[25];
    int anoPublicacao;
    Disponibilidade status;
    char nomeDoLeitor[150];
    char dataDeRetirada[11]; // Formato DD/MM/AAAA
} ItemAcervo;

typedef struct Elo {
    ItemAcervo item;          // A informação armazenada no nó
    struct Elo* seguinte;     // Ponteiro para o próximo elo da lista
} Elo;

typedef struct {
    Elo* primeiro;      // Ponteiro para o primeiro elo da lista
    int contagem;       // Quantidade total de itens no catálogo
} Catalogo;

void iniciarCatalogo(Catalogo* catalogo);

int registrarItem(Catalogo* catalogo, ItemAcervo item);

int consultarPorISBN(Catalogo* catalogo, const char* isbn, ItemAcervo* itemEncontrado);

int efetuarEmprestimo(Catalogo* catalogo, const char* isbn, const char* leitor, const char* data);

int confirmarDevolucao(Catalogo* catalogo, const char* isbn);

void exibirCatalogoCompleto(Catalogo* catalogo);

#endif