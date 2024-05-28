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
typedef struct LDEnc {
    Node* head;  // ponteiros para o primeiro e ultimo nó da lista
    Node* tail;
} LDEnc;

//funções para manipulação
LDEnc* createPlaylist();
Node* createNode(char* artista, char* musica);
