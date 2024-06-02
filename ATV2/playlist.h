#ifndef PLAYLIST_H
#define PLAYLIST_H 

// Estrutura para representar a linha
typedef struct Song {
    char artista[40];
    char musica[40];
} Song;

// Estrutura para o nó da lista
typedef struct Node {
    Song song;
    struct Node* next;
    struct Node* prev;
} Node;

// Estrutura para a lista duplamente encadeada
typedef struct LDEnc {  // LDEnc: Lista Duplamente Encadeada
    Node* head;         // Ponteiros para o primeiro e último nó da lista
    Node* tail;
} LDEnc;

// Funções para manipulação
LDEnc* createPlaylist();
Node* createNode(char* artista, char* musica);
void addSong(LDEnc* playlist, char* artista, char* musica);
void removeSong(LDEnc* playlist, char* musica);
void showPlaylist(LDEnc* playlist);
void playNext(Node** current);
void playPrev(Node** current);
void currentSong(Node* current);
void readFile(LDEnc* playlist, const char* filename);

#endif