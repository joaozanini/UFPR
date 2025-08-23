#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX 20 

typedef struct {
    int musicas[MAX]; 
    int total;         
} Playlist;

// Funções básicas
void criarPlaylist(Playlist *p);
int estaVazia(Playlist *p);
int estaCheia(Playlist *p);
int adicionarMusica(Playlist *p, int idMusica);
int removerMusica(Playlist *p, int posicao);
int buscarMusica(Playlist *p, int idMusica);
void mostrarPlaylist(Playlist *p);

#endif
