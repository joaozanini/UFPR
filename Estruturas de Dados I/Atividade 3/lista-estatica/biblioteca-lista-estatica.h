#ifndef BIBLIOTECA_LISTA_ESTATICA_H
#define BIBLIOTECA_LISTA_ESTATICA_H

#define CAPACIDADE_MAXIMA 5000

// Enumeração para o status de disponibilidade do livro
typedef enum
{
    DISPONIVEL,
    RESERVADO
} StatusLivro;

// Estrutura para representar um livro
typedef struct
{
    char titulo[151];
    char autor[151];
    int anoPublicacao;
    char codigoISBN[20];
    StatusLivro status;
    char nomeLeitor[151];      // Usuário que pegou o livro emprestado
    char dataRetirada[11];     // Formato DD/MM/AAAA
} Acervo;

// Estrutura para a lista de livros (acervo)
typedef struct
{
    Acervo colecao[CAPACIDADE_MAXIMA];
    int quantidadeAtual;
} Biblioteca;

// --- Protótipos das Funções ---

// Inicia a biblioteca, zerando a contagem de livros
void iniciarBiblioteca(Biblioteca *biblioteca);

// Adiciona um novo livro ao acervo
int adicionarNovoLivro(Biblioteca *biblioteca, char *titulo, char *autor, int ano, char *isbn);

// Busca um livro no acervo pelo código ISBN
Acervo *buscarLivroPorISBN(Biblioteca *biblioteca, char *isbn);

// Registra a retirada de um livro por um leitor
int registrarRetirada(Biblioteca *biblioteca, char *isbn, char *nomeLeitor, char *data);

// Registra a devolução de um livro
int registrarDevolucao(Biblioteca *biblioteca, char *isbn);

// Exibe todos os livros cadastrados na biblioteca
void exibirAcervoCompleto(Biblioteca *biblioteca);

#endif // BIBLIOTECA_LISTA_ESTATICA_H