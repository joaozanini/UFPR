#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "biblioteca-lista-encadeada.h"

int main() {
    Catalogo meuCatalogo;
    iniciarCatalogo(&meuCatalogo);

    clock_t inicio, fim;
    double tempoGasto;
    ItemAcervo novoItem, itemEncontrado;

    // Define as quantidades de itens para os testes de performance
    int volumesDeTeste[] = {10, 500, 5000};
    int numTestes = sizeof(volumesDeTeste) / sizeof(volumesDeTeste[0]);

    for (int t = 0; t < numTestes; t++) {
        int quantidade = volumesDeTeste[t];
        printf("\n=== INICIANDO TESTE COM %d ITENS ===\n", quantidade);

        // Garante que o catálogo esteja vazio para cada novo teste
        // (A forma de "limpar" uma lista encadeada seria liberar todos os nós,
        // mas para este teste, simplesmente reiniciar a estrutura é suficiente)
        iniciarCatalogo(&meuCatalogo);

        // --- Medição de tempo para REGISTRO de itens ---
        inicio = clock();
        for (int i = 1; i <= quantidade; i++) {
            sprintf(novoItem.titulo, "Obra Literaria %d", i);
            sprintf(novoItem.autor, "Escritor %d", i);
            sprintf(novoItem.codigoISBN, "ISBN%04d", i);
            novoItem.anoPublicacao = 2000 + i;
            novoItem.status = LIVRE;
            novoItem.nomeDoLeitor[0] = '\0';
            novoItem.dataDeRetirada[0] = '\0';

            registrarItem(&meuCatalogo, novoItem);
        }
        fim = clock();
        tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para registrar %d itens: %.6f segundos\n", quantidade, tempoGasto);

        // --- Medição de tempo para CONSULTA do último item (pior caso) ---
        char isbnParaBusca[25];
        sprintf(isbnParaBusca, "ISBN%04d", quantidade);

        inicio = clock();
        consultarPorISBN(&meuCatalogo, isbnParaBusca, &itemEncontrado);
        fim = clock();
        tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para consultar o ultimo item: %.6f segundos\n", tempoGasto);
        printf("... Item encontrado: '%s'\n", itemEncontrado.titulo);

        // --- Medição de tempo para EMPRÉSTIMO do último item (pior caso) ---
        inicio = clock();
        efetuarEmprestimo(&meuCatalogo, isbnParaBusca, "Leitor de Teste", "05/09/2025");
        fim = clock();
        tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para emprestar o ultimo item: %.6f segundos\n", tempoGasto);
        
        // --- Medição de tempo para DEVOLUÇÃO do último item (pior caso) ---
        inicio = clock();
        confirmarDevolucao(&meuCatalogo, isbnParaBusca);
        fim = clock();
        tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para devolver o ultimo item: %.6f segundos\n", tempoGasto);
    }

    // Liberar a memória alocada seria ideal em um programa completo.
    printf("\n--- TESTES FINALIZADOS ---\n");
    return 0;
}