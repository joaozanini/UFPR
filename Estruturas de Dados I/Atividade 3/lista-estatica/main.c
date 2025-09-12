#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "biblioteca-lista-estatica.h"

// Função principal para testes de performance
int main()
{
    Biblioteca minhaBiblioteca;
    iniciarBiblioteca(&minhaBiblioteca);

    clock_t tempoInicial, tempoFinal;
    double tempoDecorrido;
    Acervo exemplar, exemplarEncontrado;

    // Define os tamanhos dos lotes de teste
    int volumesParaTeste[] = {10, 500, 5000};
    int numTestes = sizeof(volumesParaTeste) / sizeof(volumesParaTeste[0]);

    for (int i = 0; i < numTestes; i++)
    {
        int quantidade = volumesParaTeste[i];
        printf("\n>>> Iniciando Teste de Carga com %d livros <<<\n", quantidade);

        // Garante que a biblioteca esteja vazia antes de cada teste
        iniciarBiblioteca(&minhaBiblioteca);

        // --- Medição do tempo de registro ---
        tempoInicial = clock();
        for (int j = 1; j <= quantidade; j++)
        {
            // Gera dados fictícios para cada livro
            sprintf(exemplar.titulo, "Titulo %d", j);
            sprintf(exemplar.autor, "Autor %d", j);
            sprintf(exemplar.codigoISBN, "ISBN%04d", j);
            exemplar.anoPublicacao = 1990 + (j % 30);
            
            adicionarNovoLivro(&minhaBiblioteca, exemplar.titulo, exemplar.autor, exemplar.anoPublicacao, exemplar.codigoISBN);
        }
        tempoFinal = clock();
        tempoDecorrido = (double)(tempoFinal - tempoInicial) / CLOCKS_PER_SEC;
        printf("Tempo para registrar %d livros: %.6f segundos\n", quantidade, tempoDecorrido);

        // --- Medição do tempo de busca (pior caso: último elemento) ---
        char isbnParaBusca[20];
        sprintf(isbnParaBusca, "ISBN%04d", quantidade);

        tempoInicial = clock();
        Acervo *ponteiroLivro = buscarLivroPorISBN(&minhaBiblioteca, isbnParaBusca);
        tempoFinal = clock();

        if (ponteiroLivro != NULL)
        {
            exemplarEncontrado = *ponteiroLivro; // Copia os dados para uma variável local
            printf("Livro encontrado:\n");
            printf("  - Titulo: %s\n", exemplarEncontrado.titulo);
            printf("  - Autor: %s\n", exemplarEncontrado.autor);
            printf("  - Ano: %d\n", exemplarEncontrado.anoPublicacao);
            printf("  - ISBN: %s\n", exemplarEncontrado.codigoISBN);
            printf("  - Status: %s\n", exemplarEncontrado.status == DISPONIVEL ? "Disponivel" : "Reservado");
        }
        else
        {
            printf("O livro com ISBN %s nao foi localizado.\n", isbnParaBusca);
        }
        tempoDecorrido = (double)(tempoFinal - tempoInicial) / CLOCKS_PER_SEC;
        printf("Tempo para buscar o ultimo livro: %.6f segundos\n", tempoDecorrido);

        // --- Medição do tempo de retirada (pior caso: último elemento) ---
        tempoInicial = clock();
        registrarRetirada(&minhaBiblioteca, isbnParaBusca, "Leitor Fantasma", "05/09/2025");
        tempoFinal = clock();
        tempoDecorrido = (double)(tempoFinal - tempoInicial) / CLOCKS_PER_SEC;
        printf("Tempo para retirar o ultimo livro: %.6f segundos\n", tempoDecorrido);

        // --- Medição do tempo de devolução (pior caso: último elemento) ---
        tempoInicial = clock();
        registrarDevolucao(&minhaBiblioteca, isbnParaBusca);
        tempoFinal = clock();
        tempoDecorrido = (double)(tempoFinal - tempoInicial) / CLOCKS_PER_SEC;
        printf("Tempo para devolver o ultimo livro: %.6f segundos\n", tempoDecorrido);
    }

    printf("\n--- Testes de desempenho finalizados ---\n");
    return 0;
}