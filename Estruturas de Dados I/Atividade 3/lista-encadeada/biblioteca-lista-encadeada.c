#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca-lista-encadeada.h"

// Configura um novo catálogo para estar vazio
void iniciarCatalogo(Catalogo* catalogo) {
    catalogo->primeiro = NULL; // O ponteiro inicial aponta para nulo
    catalogo->contagem = 0;    // A contagem de itens começa em zero
}

// Insere um novo item no final da lista (catálogo)
int registrarItem(Catalogo* catalogo, ItemAcervo item) {
    // Aloca memória para o novo elo da lista
    Elo* novoElo = (Elo*) malloc(sizeof(Elo));
    if (novoElo == NULL) {
        // Falha na alocação de memória impede o registro
        return 0;
    }

    // Preenche os dados do novo elo
    novoElo->item = item;
    novoElo->seguinte = NULL; // Como será o último, aponta para nulo

    // Se o catálogo estiver vazio, o novo elo será o primeiro
    if (catalogo->primeiro == NULL) {
        catalogo->primeiro = novoElo;
    } else {
        // Caso contrário, percorre a lista até encontrar o último elo
        Elo* ponteiroAtual = catalogo->primeiro;
        while (ponteiroAtual->seguinte != NULL) {
            ponteiroAtual = ponteiroAtual->seguinte;
        }
        // Conecta o último elo existente ao novo elo
        ponteiroAtual->seguinte = novoElo;
    }

    catalogo->contagem++; // Incrementa o número de itens
    return 1; // Sucesso
}

// Localiza um item no catálogo pelo ISBN
int consultarPorISBN(Catalogo* catalogo, const char* isbn, ItemAcervo* itemEncontrado) {
    Elo* ponteiroAtual = catalogo->primeiro;
    int posicao = 0;

    while (ponteiroAtual != NULL) {
        if (strcmp(ponteiroAtual->item.codigoISBN, isbn) == 0) {
            if (itemEncontrado != NULL) {
                *itemEncontrado = ponteiroAtual->item; // Copia os dados se um ponteiro de resultado for fornecido
            }
            return posicao; // Retorna a posição do item encontrado
        }
        ponteiroAtual = ponteiroAtual->seguinte; // Avança para o próximo elo
        posicao++;
    }

    return -1; // Retorna -1 se o ISBN não for encontrado
}

// Altera o status de um item para "RETIRADO"
int efetuarEmprestimo(Catalogo* catalogo, const char* isbn, const char* leitor, const char* data) {
    Elo* ponteiroAtual = catalogo->primeiro;

    while (ponteiroAtual != NULL) {
        if (strcmp(ponteiroAtual->item.codigoISBN, isbn) == 0) {
            if (ponteiroAtual->item.status == RETIRADO) {
                // O item já está com outro leitor
                return 0;
            }

            // Atualiza o status e as informações do empréstimo
            ponteiroAtual->item.status = RETIRADO;
            strcpy(ponteiroAtual->item.nomeDoLeitor, leitor);
            strcpy(ponteiroAtual->item.dataDeRetirada, data);
            return 1; // Sucesso
        }
        ponteiroAtual = ponteiroAtual->seguinte;
    }

    return -1; // Item não encontrado no catálogo
}

// Altera o status de um item para "LIVRE"
int confirmarDevolucao(Catalogo* catalogo, const char* isbn) {
    Elo* ponteiroAtual = catalogo->primeiro;

    while (ponteiroAtual != NULL) {
        if (strcmp(ponteiroAtual->item.codigoISBN, isbn) == 0) {
            if (ponteiroAtual->item.status == LIVRE) {
                // O item já se encontrava disponível
                return 0;
            }

            // Limpa as informações de empréstimo e atualiza o status
            ponteiroAtual->item.status = LIVRE;
            ponteiroAtual->item.nomeDoLeitor[0] = '\0';
            ponteiroAtual->item.dataDeRetirada[0] = '\0';
            return 1; // Sucesso
        }
        ponteiroAtual = ponteiroAtual->seguinte;
    }

    return -1; // Item não encontrado
}

// Exibe todos os itens do catálogo de forma formatada
void exibirCatalogoCompleto(Catalogo* catalogo) {
    Elo* ponteiroAtual = catalogo->primeiro;

    if (ponteiroAtual == NULL) {
        printf("\nO catalogo esta vazio.\n");
        return;
    }

    printf("\n--- Itens Registrados no Catalogo (%d) ---\n", catalogo->contagem);
    while (ponteiroAtual != NULL) {
        printf("Titulo: %s | Autor: %s | ISBN: %s | Ano: %d | Status: %s\n",
            ponteiroAtual->item.titulo,
            ponteiroAtual->item.autor,
            ponteiroAtual->item.codigoISBN,
            ponteiroAtual->item.anoPublicacao,
            ponteiroAtual->item.status == LIVRE ? "Livre" : "Retirado");

        if (ponteiroAtual->item.status == RETIRADO) {
            printf("  > Retirado por: %s em %s\n",
                ponteiroAtual->item.nomeDoLeitor,
                ponteiroAtual->item.dataDeRetirada);
        }
        ponteiroAtual = ponteiroAtual->seguinte;
    }
    printf("-----------------------------------------\n");
}