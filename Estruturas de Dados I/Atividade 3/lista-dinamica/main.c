#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "biblioteca-lista-dinamica.h"

int main() {
    AcervoDinamico minhaBiblioteca;
    criarAcervoDinamico(&minhaBiblioteca);

    clock_t inicio, fim;
    double tempo;
    Exemplar novoExemplar, exemplarEncontrado;

    // Define os volumes de livros para cada ciclo de teste
    int volumesDeTeste[] = {10, 500, 5000};  
    int numTestes = sizeof(volumesDeTeste) / sizeof(volumesDeTeste[0]);

    for (int t = 0; t < numTestes; t++) {
        int n = volumesDeTeste[t];
        printf("\n=== INICIANDO TESTE DE PERFORMANCE COM %d EXEMPLARES ===\n", n);

        // Limpa e recria o acervo para garantir um teste isolado
        liberarAcervo(&minhaBiblioteca);
        criarAcervoDinamico(&minhaBiblioteca);

        // --- Medição de tempo para INSERÇÃO ---
        inicio = clock();
        for (int i = 1; i <= n; i++) {
            sprintf(novoExemplar.titulo, "Titulo do Livro %d", i);
            sprintf(novoExemplar.autor, "Autor do Livro %d", i);
            sprintf(novoExemplar.codigoISBN, "ISBN%05d", i); 
            novoExemplar.anoPublicacao = 1980 + (i % 40);
            novoExemplar.status = DISPONIVEL;
            novoExemplar.nomeLeitor[0] = '\0';
            novoExemplar.dataEmprestimo[0] = '\0';

            inserirExemplar(&minhaBiblioteca, novoExemplar);
        }
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para inserir %d exemplares: %.6f segundos\n", n, tempo);

        // --- Medição de tempo para BUSCA (pior caso) ---
        char isbnBusca[25];
        sprintf(isbnBusca, "ISBN%05d", n);

        inicio = clock();
        int indice = pesquisarPorCodigo(&minhaBiblioteca, isbnBusca, &exemplarEncontrado);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para buscar o ultimo exemplar: %.6f segundos\n", tempo);
        if (indice != -1) {
            printf("... Exemplar '%s' encontrado no indice %d.\n", exemplarEncontrado.titulo, indice);
        } else {
            printf("... Exemplar com ISBN %s nao foi encontrado.\n", isbnBusca);
        }

        // --- Medição de tempo para EMPRÉSTIMO (pior caso) ---
        inicio = clock();
        int sucessoEmprestimo = registrarEmprestimo(&minhaBiblioteca, isbnBusca, "Leitor de Teste", "05/09/2025");
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para emprestar o ultimo exemplar: %.6f segundos\n", tempo);
        printf("... Emprestimo %s\n", sucessoEmprestimo ? "realizado com sucesso" : "falhou");

        // --- Medição de tempo para DEVOLUÇÃO (pior caso) ---
        inicio = clock();
        int sucessoDevolucao = registrarDevolucao(&minhaBiblioteca, isbnBusca);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para devolver o ultimo exemplar: %.6f segundos\n", tempo);
        printf("... Devolucao %s\n", sucessoDevolucao ? "realizada com sucesso" : "falhou");
    }

    // Libera a memória alocada ao final de todos os testes
    liberarAcervo(&minhaBiblioteca);
    
    printf("\n--- FIM DOS TESTES ---\n");
    return 0;
}