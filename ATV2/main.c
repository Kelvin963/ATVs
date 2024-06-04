#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

// Função para ler uma música do terminal e adicioná-la à playlist
void readMusic(LDEnc* playlist) {
    char artista[40];
    char musica[40];

    // Solicita ao usuário que insira a musica e o artista
    printf("Digite o nome da musica: ");
    fgets(musica, sizeof(musica), stdin);
    musica[strcspn(musica, "\n")] = '\0'; // Remove a nova linha do final

    printf("Digite o artista da musica: ");
    fgets(artista, sizeof(artista), stdin);
    artista[strcspn(artista, "\n")] = '\0'; // Remove a nova linha do final

    // Adiciona a música à playlist
    addSong(playlist, artista, musica);

    printf("Musica adicionada a playlist: %s - %s\n", musica, artista);
}

void menu(LDEnc* playlist){
    int opcao;
    char musica[40];
    Node* current = playlist->head;
    do {
    
        printf("\n============ UNIVERSE PLAYLIST ================\n");
        printf("||_______1. Mostrar playlist___________________||\n");
        printf("||_______2. Adicionar musica___________________||\n");
        printf("||_______3. Remover musica_____________________||\n");
        printf("||_______4. Tocar proxima musica_______________||\n");
        printf("||_______5. Tocar musica anterior______________||\n");
        printf("||_______6. Mostrar musica atual_______________||\n");
        printf("||_______0. Sair_______________________________||\n");
        printf("=================================================\n");
        printf("\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer de entrada

        switch (opcao){
            case 1:
                showPlaylist(playlist);
                break;
            case 2:
                readMusic(playlist);
                break;
            case 3:
                printf("Digite o nome da musica a ser removida: ");
                fgets(musica, sizeof(musica), stdin);
                musica[strcspn(musica, "\n")] = '\0'; // Remove a nova linha do final
                removeSong(playlist, musica);
                break;
            case 4:
                playNext(&current);
                currentSong(current);
                break;
            case 5:
                playPrev(&current);
                currentSong(current);
                break;
            case 6:
                currentSong(current);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);


}

int main() {
    // Cria uma nova playlist
    LDEnc* playlist = createPlaylist();

    // Lê músicas do arquivo e as adiciona à playlist
    readFile(playlist, "playlist.txt");

    menu(playlist);

    // Libera a memória alocada para a playlist
    free(playlist);

    return 0;
}