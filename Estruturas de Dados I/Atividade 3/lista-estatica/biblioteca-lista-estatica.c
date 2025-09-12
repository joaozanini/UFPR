#include <stdio.h>
#include <string.h>
#include "biblioteca-lista-estatica.h"

// Prepara a biblioteca para uso
void iniciarBiblioteca(Biblioteca *biblioteca)
{
    biblioteca->quantidadeAtual = 0;
}

// Insere um novo livro na coleção da biblioteca
int adicionarNovoLivro(Biblioteca *biblioteca, char *titulo, char *autor, int ano, char *isbn)
{
    // Verifica se a biblioteca atingiu a capacidade máxima
    if (biblioteca->quantidadeAtual >= CAPACIDADE_MAXIMA)
    {
        return 0; // Retorna 0 para indicar que a biblioteca está cheia
    }

    // Aponta para a próxima posição livre no array
    Acervo *novoAcervo = &biblioteca->colecao[biblioteca->quantidadeAtual];

    // Copia as informações para a nova estrutura de livro
    strcpy(novoAcervo->titulo, titulo);
    strcpy(novoAcervo->autor, autor);
    novoAcervo->anoPublicacao = ano;
    strcpy(novoAcervo->codigoISBN, isbn);
    novoAcervo->status = DISPONIVEL;
    strcpy(novoAcervo->nomeLeitor, "");
    strcpy(novoAcervo->dataRetirada, "");

    // Incrementa o contador de livros
    biblioteca->quantidadeAtual++;
    return 1; // Retorna 1 para indicar sucesso
}

// Localiza um livro específico pelo seu ISBN
Acervo *buscarLivroPorISBN(Biblioteca *biblioteca, char *isbn)
{
    for (int i = 0; i < biblioteca->quantidadeAtual; i++)
    {
        // Compara o ISBN fornecido com cada livro na coleção
        if (strcmp(biblioteca->colecao[i].codigoISBN, isbn) == 0)
        {
            return &biblioteca->colecao[i]; // Retorna o endereço do livro encontrado
        }
    }
    return NULL; // Retorna NULL se o livro não for encontrado
}

// Modifica o status de um livro para "RESERVADO"
int registrarRetirada(Biblioteca *biblioteca, char *isbn, char *nomeLeitor, char *data)
{
    Acervo *livro = buscarLivroPorISBN(biblioteca, isbn);

    if (livro == NULL)
    {
        return 0; // Código 0: livro não encontrado
    }
    if (livro->status == RESERVADO)
    {
        return -1; // Código -1: livro já está com outro leitor
    }

    // Atualiza as informações de retirada
    livro->status = RESERVADO;
    strcpy(livro->nomeLeitor, nomeLeitor);
    strcpy(livro->dataRetirada, data);
    return 1; // Sucesso
}

// Modifica o status de um livro para "DISPONIVEL"
int registrarDevolucao(Biblioteca *biblioteca, char *isbn)
{
    Acervo *livro = buscarLivroPorISBN(biblioteca, isbn);

    if (livro == NULL)
    {
        return 0; // Código 0: livro não encontrado
    }
    if (livro->status == DISPONIVEL)
    {
        return -1; // Código -1: livro já se encontrava disponível
    }

    // Limpa as informações de retirada
    livro->status = DISPONIVEL;
    strcpy(livro->nomeLeitor, "");
    strcpy(livro->dataRetirada, "");
    return 1; // Sucesso
}

// Imprime uma lista formatada de todos os livros no acervo
void exibirAcervoCompleto(Biblioteca *biblioteca)
{
    printf("\n--- Relatorio do Acervo da Biblioteca ---\n");
    for (int i = 0; i < biblioteca->quantidadeAtual; i++)
    {
        Acervo exemplar = biblioteca->colecao[i];
        printf("[%d] %s - %s (%d)\n", i + 1, exemplar.titulo, exemplar.autor, exemplar.anoPublicacao);
        printf("   ISBN: %s | Status: %s\n", exemplar.codigoISBN, exemplar.status == DISPONIVEL ? "Disponivel" : "Reservado");
        if (exemplar.status == RESERVADO)
        {
            printf("   Retirado por: %s em %s\n", exemplar.nomeLeitor, exemplar.dataRetirada);
        }
    }
    printf("=========================================\n");
}