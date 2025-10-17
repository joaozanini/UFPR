#include <stdio.h>
#include <string.h>
#include "ocorrencias.h"

// Autor: Felipe Laskos
int registrar_ocorrencia(ListaEstudantes *estudantes, int ra, Data data, TipoOcorrencia tipo, const char *descricao) {
    Estudante *e = estudantes_buscar(estudantes, ra);
    if (!e) return 0;
    if (!lista_inserir_ordenado(e->ocorrencias, data, tipo, descricao)) return 0;
    return 1;
}

static void imprimir_ocorrencia(OcorrenciaNode *n) {
    char buf[16];
    printf("Data: %s | Tipo: %s\nDescricao: %s\n", data_to_string(n->data, buf), tipo_to_string(n->tipo), n->descricao);
}

// Autor: Felipe Laskos
void listar_ocorrencias_por_ra(ListaEstudantes *estudantes, int ra) {
    Estudante *e = estudantes_buscar(estudantes, ra);
    if (!e) { printf("RA nao encontrado.\n"); return; }
    ListaOcorrencias *lista = e->ocorrencias;
    if (!lista || lista->tamanho == 0) { printf("Sem ocorrencias para este estudante.\n"); return; }
    printf("\n-- Navegacao de Ocorrencias (RA %d - %s) --\n", e->ra, e->nome);
    OcorrenciaNode *atual = lista_primeiro(lista);
    char comando[16];
    while (1) {
        imprimir_ocorrencia(atual);
        printf("[n] proxima | [p] anterior | [q] sair > ");
        if (!fgets(comando, sizeof(comando), stdin)) break;
        if (comando[0] == 'q') break;
        else if (comando[0] == 'n') {
            if (atual->next != lista->sentinela) atual = atual->next; else printf("(Fim da lista)\n");
        } else if (comando[0] == 'p') {
            if (atual->prev != lista->sentinela) atual = atual->prev; else printf("(Inicio da lista)\n");
        }
    }
}

// Autor: Felipe Laskos
int remover_ocorrencia(ListaEstudantes *estudantes, int ra, Data data) {
    Estudante *e = estudantes_buscar(estudantes, ra);
    if (!e) return 0;
    return lista_remover_por_data(e->ocorrencias, data);
}

// Autor: Felipe Laskos
void filtrar_por_tipo(ListaEstudantes *estudantes, TipoOcorrencia tipo) {
    printf("\n-- Ocorrencias do tipo %s --\n", tipo_to_string(tipo));
    for (Estudante *e = estudantes->head; e; e = e->next) {
        ListaOcorrencias *lista = e->ocorrencias;
        OcorrenciaNode *s = lista->sentinela;
        int encontrou = 0;
        for (OcorrenciaNode *n = s->next; n != s; n = n->next) {
            if (n->tipo == tipo) {
                if (!encontrou) {
                    printf("Estudante RA %d - %s (%s)\n", e->ra, e->nome, e->turma);
                    encontrou = 1;
                }
                char buf[16];
                printf("  - %s: %s\n", data_to_string(n->data, buf), n->descricao);
            }
        }
    }
}
