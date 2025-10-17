#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Autor: João Zanini
ListaOcorrencias* lista_criar() {
    ListaOcorrencias *lista = (ListaOcorrencias*) malloc(sizeof(ListaOcorrencias));
    if (!lista) return NULL;
    lista->sentinela = (OcorrenciaNode*) malloc(sizeof(OcorrenciaNode));
    if (!lista->sentinela) { free(lista); return NULL; }
    lista->sentinela->next = lista->sentinela->prev = lista->sentinela; // circular
    lista->tamanho = 0;
    return lista;
}

// Autor: João Zanini
void lista_destruir(ListaOcorrencias *lista) {
    if (!lista) return;
    OcorrenciaNode *s = lista->sentinela;
    OcorrenciaNode *atual = s->next;
    while (atual != s) {
        OcorrenciaNode *prox = atual->next;
        free(atual);
        atual = prox;
    }
    free(s);
    free(lista);
}

// Autor: João Manoel
static int eh_mais_recente(Data a, Data b) {
    if (a.ano != b.ano) return a.ano > b.ano;
    if (a.mes != b.mes) return a.mes > b.mes;
    return a.dia > b.dia;
}

// Autor: João Manoel
OcorrenciaNode* lista_inserir_ordenado(ListaOcorrencias *lista, Data data, TipoOcorrencia tipo, const char *descricao) {
    if (!lista) return NULL;
    OcorrenciaNode *novo = (OcorrenciaNode*) malloc(sizeof(OcorrenciaNode));
    if (!novo) return NULL;
    novo->data = data;
    novo->tipo = tipo;
    strncpy(novo->descricao, descricao, sizeof(novo->descricao)-1);
    novo->descricao[sizeof(novo->descricao)-1] = '\0';

    OcorrenciaNode *s = lista->sentinela;
    OcorrenciaNode *atual = s->next;
    // Inserir mantendo ordem desc (mais recente primeiro)
    while (atual != s && !eh_mais_recente(data, atual->data)) {
        // enquanto o atual for mais recente ou igual, avanca
        atual = atual->next;
    }
    // Inserir antes de 'atual'
    novo->next = atual;
    novo->prev = atual->prev;
    atual->prev->next = novo;
    atual->prev = novo;
    lista->tamanho++;
    return novo;
}

// Autor: Cayo Vinícius
int lista_remover_por_data(ListaOcorrencias *lista, Data data) {
    if (!lista) return 0;
    OcorrenciaNode *s = lista->sentinela;
    for (OcorrenciaNode *n = s->next; n != s; n = n->next) {
        if (n->data.dia == data.dia && n->data.mes == data.mes && n->data.ano == data.ano) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            free(n);
            lista->tamanho--;
            return 1;
        }
    }
    return 0;
}

// Autor: Cayo Vinícius
int lista_contar_por_tipo(ListaOcorrencias *lista, TipoOcorrencia tipo) {
    if (!lista) return 0;
    int count = 0;
    OcorrenciaNode *s = lista->sentinela;
    for (OcorrenciaNode *n = s->next; n != s; n = n->next) {
        if (n->tipo == tipo) count++;
    }
    return count;
}

// Autor: João Zanini
OcorrenciaNode* lista_primeiro(ListaOcorrencias *lista) {
    if (!lista || lista->tamanho == 0) return NULL;
    return lista->sentinela->next;
}

// Autor: João Zanini
OcorrenciaNode* lista_ultimo(ListaOcorrencias *lista) {
    if (!lista || lista->tamanho == 0) return NULL;
    return lista->sentinela->prev;
}

// Autor: João Manoel
int comparar_datas(Data d1, Data d2) {
    if (d1.ano != d2.ano) return (d1.ano > d2.ano) ? 1 : -1;
    if (d1.mes != d2.mes) return (d1.mes > d2.mes) ? 1 : -1;
    if (d1.dia != d2.dia) return (d1.dia > d2.dia) ? 1 : -1;
    return 0;
}

// Autor: Felipe Laskos
int parse_data(const char *str, Data *out) {
    if (!str || !out) return 0;
    int d,m,a;
    if (sscanf(str, "%d/%d/%d", &d,&m,&a) != 3) return 0;
    if (d < 1 || d > 31 || m < 1 || m > 12 || a < 1900 || a > 3000) return 0;
    out->dia = d; out->mes = m; out->ano = a;
    return 1;
}

// Autor: Felipe Laskos
char* data_to_string(Data d, char *buffer) {
    sprintf(buffer, "%02d/%02d/%04d", d.dia, d.mes, d.ano);
    return buffer;
}
