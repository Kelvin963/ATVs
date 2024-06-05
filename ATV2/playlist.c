#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

// LDEnc: Lista Duplamente Encadeada
LDEnc* createPlaylist() {
    LDEnc* playlist = (LDEnc*) malloc(sizeof(LDEnc)); 
    playlist->head = NULL;
    playlist->tail = NULL;
    return playlist;
}

// Criação do nó
Node* createNode(char* artista, char* musica) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->song.musica, musica);
    strcpy(newNode->song.artista, artista); 
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Adicionar uma música
void addSong(LDEnc* playlist, char* artista, char* musica) {
    Node* newNode = createNode(artista, musica);
    if (playlist->head == NULL) {
        playlist->head = newNode;
        playlist->tail = newNode;
    } else {
        playlist->tail->next = newNode;
        newNode->prev = playlist->tail;
        playlist->tail = newNode;
    }
}      

// Remover uma música
void removeSong(LDEnc* playlist, char* musica) {
    Node* temp = playlist->head;
    while (temp != NULL) {
        if (strcmp(temp->song.musica, musica) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                playlist->head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            } else {
                playlist->tail = temp->prev;
            }
            free(temp);
            printf("Musica removida com sucesso.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Musica nao encontrada na playlist.\n");
    system("pause");
    system("cls");
}

// Mostrar a playlist
void showPlaylistIO(LDEnc* playlist) { //ShowPlaylistInOrder
    printf("PlayList em ordem de cadastro:\n");
    Node* temp = playlist->head;
    while (temp != NULL) {
        printf("%s;%s\n", temp->song.artista, temp->song.musica);
        temp = temp->next;
    }
    system("pause");
    system("cls");
}

void showPlaylistSN(LDEnc* playlist) { //ShowPlaylistSongName
    printf("Playlist ordenada pelo nome das musicas:\n");

    // Copia os nos da lista para um array para facilitar a ordenação
    int count = 0;
    Node* temp = playlist->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    Node* songsArray[count];
    temp = playlist->head;
    for (int i = 0; i < count; i++) {
        songsArray[i] = temp;
        temp = temp->next;
    }

    int compareSongs(const void* a, const void* b) {
        Node* nodeA = *((Node**)a);
        Node* nodeB = *((Node**)b);
        return strcmp(nodeA->song.musica, nodeB->song.musica);
    }

    // Ordena o array de musicas pelo nome das musicas
    qsort(songsArray, count, sizeof(Node*), compareSongs);

    // Exibe as musicas ordenadas
    for (int i = 0; i < count; i++) {
        printf("%s;%s\n", songsArray[i]->song.musica, songsArray[i]->song.artista);
    }
    system("pause");
    system("cls");
}

// Tocar próxima música
void playNext(Node** current) {
    if (*current != NULL && (*current)->next != NULL) {
        *current = (*current)->next;
    } else {
        printf("Nao ha uma proxima musica.\n");
    }
    system("pause");
    system("cls");
}

// Tocar música anterior
void playPrev(Node** current) {
    if (*current != NULL && (*current)->prev != NULL) {
        *current = (*current)->prev;
    } else {
        printf("Nenhuma musica anterior.\n");
    }
    system("pause");
    system("cls");
}

// Mostrar música atual
void currentSong(Node* current) {
    if (current != NULL) {
        printf("Atualmente tocando: %s;%s\n", current->song.artista, current->song.musica);
        system("pause");
        system("cls");
    } else {
        printf("Nenhuma musica está tocando atualmente\n");
        system("pause");
        system("cls");
    }
}

// Ler arquivo para inserção de novas músicas na playlist
void readFile(LDEnc* playlist, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
        system("pause");
        system("cls");
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        // Remover o caractere de nova linha (\n) do final da linha (se houver)
        char* novalinha = strchr(linha, '\n');
        if (novalinha != NULL) {
            *novalinha = '\0';
        }

        // Separar o título do artista
        char* delimiter = strchr(linha, ';');
        if (delimiter != NULL) {
            *delimiter = '\0'; // Separa o título do artista
            addSong(playlist, linha, delimiter + 1); // Adiciona à playlist
        }
    }
    fclose(file);
}

// Função para buscar uma música na playlist
void searchSong(LDEnc* playlist, char* musica) {
    Node* temp = playlist->head;
    while (temp != NULL) {
        if (strcmp(temp->song.musica, musica) == 0) {
            printf("Musica encontrada: %s;%s\n", temp->song.artista, temp->song.musica);
            return;
        }
        temp = temp->next;
    }
    printf("Musica não encontrada na playlist.\n");
}