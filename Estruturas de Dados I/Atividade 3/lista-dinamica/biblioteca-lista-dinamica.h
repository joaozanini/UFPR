#ifndef BIBLIOTECA_LISTA_DINAMICA_H
#define BIBLIOTECA_LISTA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_INICIAL 10

typedef enum {
    DISPONIVEL,
    EMPRESTADO,
    RESERVADO
} Disponibilidade;

typedef struct {
    char titulo[150];
    char autor[150];
    char codigoISBN[25];
    int anoPublicacao;
    Disponibilidade status;
    char nomeLeitor[150];
    char dataEmprestimo[11]; // Formato DD/MM/AAAA
} Exemplar;

typedef struct {
    Exemplar *colecao;     // Ponteiro para o array de exemplares
    int quantidade;        // Número de exemplares atualmente armazenados
    int capacidade;        // Capacidade atual do array 'colecao'
} AcervoDinamico;

// --- Protótipos das Funções ---

void criarAcervoDinamico(AcervoDinamico *acervo);

void expandirAcervo(AcervoDinamico *acervo, int novaCapacidade);

int inserirExemplar(AcervoDinamico *acervo, Exemplar exemplar);

int pesquisarPorCodigo(AcervoDinamico *acervo, const char *isbn, Exemplar *resultado);

int registrarEmprestimo(AcervoDinamico *acervo, const char *isbn, const char *leitor, const char *data);

int registrarDevolucao(AcervoDinamico *acervo, const char *isbn);

void exibirColecaoCompleta(AcervoDinamico *acervo);

void liberarAcervo(AcervoDinamico *acervo);

#endif