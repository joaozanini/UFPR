#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca-lista-dinamica.h"

// Prepara o acervo para uso, alocando a memória inicial
void criarAcervoDinamico(AcervoDinamico *acervo) {
    // Aloca um bloco de memória inicial para a coleção de exemplares
    acervo->colecao = (Exemplar*) malloc(TAMANHO_INICIAL * sizeof(Exemplar));
    acervo->quantidade = 0;
    acervo->capacidade = TAMANHO_INICIAL;
}

// Redimensiona o array da coleção para uma nova capacidade
void expandirAcervo(AcervoDinamico *acervo, int novaCapacidade) {
    // Cria um novo array com a capacidade aumentada
    Exemplar *novaColecao = (Exemplar*) malloc(novaCapacidade * sizeof(Exemplar));
    
    // Copia os dados do array antigo para o novo
    for (int i = 0; i < acervo->quantidade; i++) {
        novaColecao[i] = acervo->colecao[i];
    }
    
    // Libera a memória do array antigo
    free(acervo->colecao);
    
    // Atualiza os ponteiros e a capacidade
    acervo->colecao = novaColecao;
    acervo->capacidade = novaCapacidade;
}

// Cadastra um novo exemplar na coleção
int inserirExemplar(AcervoDinamico *acervo, Exemplar exemplar) {
    // Se o acervo está cheio, dobra sua capacidade
    if (acervo->quantidade == acervo->capacidade) {
        expandirAcervo(acervo, acervo->capacidade * 2);
    }
    
    // Adiciona o novo exemplar na primeira posição livre
    acervo->colecao[acervo->quantidade] = exemplar;
    acervo->quantidade++;
    return 1; // Sucesso
}

// Busca um exemplar pelo código ISBN e retorna seu índice
int pesquisarPorCodigo(AcervoDinamico *acervo, const char *isbn, Exemplar *resultado) {
    for (int i = 0; i < acervo->quantidade; i++) {
        if (strcmp(acervo->colecao[i].codigoISBN, isbn) == 0) {
            *resultado = acervo->colecao[i];
            return i; // Retorna o índice onde o livro foi encontrado
        }
    }
    return -1; // Retorna -1 se não encontrar
}

// Altera o status de um exemplar para EMPRESTADO
int registrarEmprestimo(AcervoDinamico *acervo, const char *isbn, const char *leitor, const char *data) {
    for (int i = 0; i < acervo->quantidade; i++) {
        if (strcmp(acervo->colecao[i].codigoISBN, isbn) == 0) {
            // Verifica se o livro já não está emprestado
            if (acervo->colecao[i].status != DISPONIVEL) {
                return 0; // livro indisponível
            }
            
            // Atualiza o status e os dados do empréstimo
            acervo->colecao[i].status = EMPRESTADO;
            strncpy(acervo->colecao[i].nomeLeitor, leitor, sizeof(acervo->colecao[i].nomeLeitor) - 1);
            strncpy(acervo->colecao[i].dataEmprestimo, data, sizeof(acervo->colecao[i].dataEmprestimo) - 1);
            return 1; // Sucesso
        }
    }
    return 0; // livro não encontrado
}

// Altera o status de um exemplar para DISPONIVEL
int registrarDevolucao(AcervoDinamico *acervo, const char *isbn) {
    for (int i = 0; i < acervo->quantidade; i++) {
        if (strcmp(acervo->colecao[i].codigoISBN, isbn) == 0) {
            if (acervo->colecao[i].status == EMPRESTADO) {
                acervo->colecao[i].status = DISPONIVEL;
                acervo->colecao[i].nomeLeitor[0] = '\0';
                acervo->colecao[i].dataEmprestimo[0] = '\0';
                return 1; // Sucesso
            }
        }
    }
    return 0; // livro não encontrado ou já disponível
}

// Imprime a lista dos exemplares
void exibirColecaoCompleta(AcervoDinamico *acervo) {
    printf("\n--- CATALOGO DA BIBLIOTECA (%d/%d) ---\n", acervo->quantidade, acervo->capacidade);
    for (int i = 0; i < acervo->quantidade; i++) {
        printf("\n%d. %s - %s\n", i + 1, acervo->colecao[i].titulo, acervo->colecao[i].autor);
        printf("   ISBN: %s, Ano: %d\n", acervo->colecao[i].codigoISBN, acervo->colecao[i].anoPublicacao);
        printf("   Status: ");
        switch (acervo->colecao[i].status) {
            case DISPONIVEL: printf("Disponível"); break;
            case EMPRESTADO: 
                printf("Emprestado para %s (em %s)", acervo->colecao[i].nomeLeitor, acervo->colecao[i].dataEmprestimo);
                break;
            case RESERVADO: printf("Reservado"); break;
        }
        printf("\n");
    }
}

// Libera a memória
void liberarAcervo(AcervoDinamico *acervo) {
    free(acervo->colecao);
    acervo->colecao = NULL;
    acervo->quantidade = 0;
    acervo->capacidade = 0;
}