#include <stdio.h>
#include "playlist.h"

void criarPlaylist(Playlist *p) {
    p->total = 0;
}

int estaVazia(Playlist *p) {
    return p->total == 0;
}

int estaCheia(Playlist *p) {
    return p->total == MAX;
}

int adicionarMusica(Playlist *p, int idMusica) {
    if (estaCheia(p)) {
        return 0;
    }
    p->musicas[p->total] = idMusica;
    p->total++;
    return 1;
}

int removerMusica(Playlist *p, int posicao) {
    if (posicao < 0 || posicao >= p->total) {
        return 0;
    }
    for (int i = posicao; i < p->total - 1; i++) {
        p->musicas[i] = p->musicas[i + 1];
    }
    p->total--;
    return 1;
}

int buscarMusica(Playlist *p, int idMusica) {
    for (int i = 0; i < p->total; i++) {
        if (p->musicas[i] == idMusica) {
            return i;
        }
    }
    return -1;
}

void mostrarPlaylist(Playlist *p) {
    if (estaVazia(p)) {
        printf("Sua playlist está vazia!\n");
        return;
    }
    printf("=== SUA PLAYLIST ===\n");
    for (int i = 0; i < p->total; i++) {
        printf("Posição %d: Música %d\n", i, p->musicas[i]);
    }
    printf("Total: %d músicas\n", p->total);
}
