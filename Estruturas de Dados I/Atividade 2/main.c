#include <stdio.h>
#include "playlist.h"

int main() {
    Playlist p;
    criarPlaylist(&p);

    int opcao, idMusica, posicao;

    do {
        printf("\n=== MINHA PLAYLIST ===\n");
        printf("1. Adicionar música\n");
        printf("2. Remover música\n");
        printf("3. Buscar música\n");
        printf("4. Mostrar playlist\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID da música: ");
                scanf("%d", &idMusica);
                if (adicionarMusica(&p, idMusica))
                    printf("Música %d adicionada!\n", idMusica);
                else
                    printf("Playlist cheia! Não foi possível adicionar.\n");
                break;

            case 2:
                printf("Digite a posição para remover: ");
                scanf("%d", &posicao);
                if (removerMusica(&p, posicao))
                    printf("Música da posição %d removida!\n", posicao);
                else
                    printf("Posição inválida!\n");
                break;

            case 3:
                printf("Digite o ID da música para buscar: ");
                scanf("%d", &idMusica);
                posicao = buscarMusica(&p, idMusica);
                if (posicao != -1)
                    printf("Música %d encontrada na posição %d!\n", idMusica, posicao);
                else
                    printf("Música %d não encontrada!\n", idMusica);
                break;

            case 4:
                mostrarPlaylist(&p);
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    return 0;
}
