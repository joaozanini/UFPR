#ifndef LISTA_OCORRENCIAS_H
#define LISTA_OCORRENCIAS_H

// Lista duplamente encadeada de ocorrências com nó sentinela.
// Cada ocorrência pertence a um estudante (RA) e é encadeada somente dentro
// da lista daquele estudante, permitindo navegação para frente e trás.

#include <time.h>

typedef enum {
    TIPO_ADVERTENCIA = 0,
    TIPO_ELOGIO = 1,
    TIPO_FALTA = 2
} TipoOcorrencia;

static inline const char* tipo_to_string(TipoOcorrencia t) {
    switch (t) {
        case TIPO_ADVERTENCIA: return "Advertencia"; // sem acento p/ facilitar
        case TIPO_ELOGIO: return "Elogio";
        case TIPO_FALTA: return "Falta";
        default: return "Desconhecido";
    }
}

typedef struct {
    int dia, mes, ano; // Representacao simples de data
} Data;

// Representa uma ocorrencia academica
typedef struct OcorrenciaNode {
    struct OcorrenciaNode *prev, *next;
    Data data;                // usado para ordenacao (mais recente primeiro)
    TipoOcorrencia tipo;
    char descricao[256];
} OcorrenciaNode;

// Lista com sentinela (circular). Se vazia: sentinela->next == sentinela.
typedef struct {
    OcorrenciaNode *sentinela;
    int tamanho;
} ListaOcorrencias;

// Autor: João Zanini
// Cria e inicializa lista duplamente encadeada vazia com sentinela.
ListaOcorrencias* lista_criar();

// Autor: João Zanini
// Libera todos os nos e a lista em si.
void lista_destruir(ListaOcorrencias *lista);

// Autor: João Manoel
// Insere ocorrencia de forma ordenada por data (mais recente primeiro).
// Datas mais recentes (ano maior ou, em igualdade, mes maior, depois dia) ficam no inicio.
// Retorna ponteiro para o novo nó ou NULL em falha de alocacao.
OcorrenciaNode* lista_inserir_ordenado(ListaOcorrencias *lista, Data data, TipoOcorrencia tipo, const char *descricao);

// Autor: Cayo Vinícius
// Remove a primeira ocorrencia que tenha a data especificada. Retorna 1 se removeu, 0 se nao achou.
int lista_remover_por_data(ListaOcorrencias *lista, Data data);

// Autor: Cayo Vinícius
// Conta quantos nos possuem o tipo informado.
int lista_contar_por_tipo(ListaOcorrencias *lista, TipoOcorrencia tipo);

// Autor: João Zanini
// Retorna primeiro no (mais recente) ou NULL se vazia.
OcorrenciaNode* lista_primeiro(ListaOcorrencias *lista);

// Autor: João Zanini
// Retorna ultimo no (mais antigo) ou NULL se vazia.
OcorrenciaNode* lista_ultimo(ListaOcorrencias *lista);

// Autor: João Manoel
// Compara datas: retorna <0 se d1 mais recente que d2? Vamos definir:
// Retorno: >0 se d1 MAIS RECENTE que d2, 0 igual, <0 se d1 mais ANTIGA (para facilitar ordenacao desc).
int comparar_datas(Data d1, Data d2);

// Autor: Felipe Laskos
// Converte string DD/MM/AAAA para Data. Retorna 1 se valido, 0 caso contrario.
int parse_data(const char *str, Data *out);

// Autor: Felipe Laskos
// Converte Data para string "DD/MM/AAAA" no buffer (tam >= 11). Retorna buffer.
char* data_to_string(Data d, char *buffer);

#endif
