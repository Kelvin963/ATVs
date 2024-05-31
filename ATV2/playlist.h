#ifndef PLAYLIST_H
#define PLAYLIST_H 

//estrutura para representar a linha 
typedef struct song {
    char artista[40];
    char musica[40];
} song;

//estrutura para o nó na lista
typedef struct Node {
    song song
    struct Node* next;
    struct Node* prev;
} Node;

//estrutura para a lista duplamente encadeada
typedef struct LDEnc {                          // LDEnc: Lista Duplamente Encadeada
    Node* head;                                 // Ponteiros para o primeiro e ultimo nó da lista
    Node* tail;
} LDEnc;

//funções para manipulação
LDEnc* createPlaylist();
Node* createNode(char* artista, char* musica);
void addSong(LDEnc* playlist, char* artista, char* musica);
void removeSong(LDEnc* playlist, char* musica);
void showPlaylist(DoublyLinkedList* playlist);
void playNext(Node** current);
void playPrev(Node** current);
void currentSong(Node* current);