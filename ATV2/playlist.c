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

void addSong(LDEnc* playlist, char* artista, char* musica){
    Node* newNode = createNode(musica, artista);
    if(playlist->head == NULL){
        playlist->head = newNode;
        playlist->tail = newNode;
    }else{
        playlist->tail->next = newNode;
        newNode->prev = playlist->tail;
        playlist->tail = newNode;
    }
}      

void removeSong(LDEnc* playlist, char* musica){
    Node* temp = playlist->head;
    while(temp != NULL){
        if(strcmp(temp->song.musica, musica) == 0){
            if(temp->prev != NULL){
                temp->next->prev = temp->next;
            }else{
                playlist->head = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }else{
                playlist->tail = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Musica nao encontrada na playlist.\n");
}

