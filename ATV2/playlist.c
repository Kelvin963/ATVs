#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

LDEnc* createPlaylist(){
    LDEnc* playlist = (LDEnc*) malloc(sizeof(LDEnc)); 
    playlist->head = NULL;
    playlist->tail = NULL;
    return playlist;
}

Node* createNode(char* artista, char* musica) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->song.musica, musica);
    strcpy(newNode->song.artista, artista); 
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}