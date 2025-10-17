#ifndef OCORRENCIAS_H
#define OCORRENCIAS_H

#include "estudantes.h"

// Autor: Felipe Laskos
// Registra nova ocorrencia para RA dado. Retorna 1 sucesso, 0 erro (RA inexistente ou falha).
int registrar_ocorrencia(ListaEstudantes *estudantes, int ra, Data data, TipoOcorrencia tipo, const char *descricao);

// Autor: Felipe Laskos
// Lista todas ocorrencias de um RA com navegacao interativa (n=proximo, p=anterior, q=sair).
void listar_ocorrencias_por_ra(ListaEstudantes *estudantes, int ra);

// Autor: Felipe Laskos
// Remove ocorrencia especifica por RA + data. Retorna 1 se removeu, 0 caso contrario.
int remover_ocorrencia(ListaEstudantes *estudantes, int ra, Data data);

// Autor: Felipe Laskos
// Filtra e imprime ocorrencias pelo tipo (todas dos estudantes) em ordem por estudante (simples).
void filtrar_por_tipo(ListaEstudantes *estudantes, TipoOcorrencia tipo);

#endif
