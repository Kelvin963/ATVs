#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

// Função para ler uma música do terminal e adicioná-la à playlist
void readMusic(LDEnc* playlist) {
    char artista[40];
    char musica[40];

    // Solicita ao usuário que insira a musica e o artista
    printf("Digite o artista da musica: ");
    fgets(artista, sizeof(artista), stdin);
    artista[strcspn(artista, "\n")] = '\0'; // Remove a nova linha do final

    printf("Digite o nome da musica: ");
    fgets(musica, sizeof(musica), stdin);
    musica[strcspn(musica, "\n")] = '\0'; // Remove a nova linha do final

    // Adiciona a música à playlist
    addSong(playlist, artista, musica);

    printf("Musica adicionada a playlist.\n");
    system("pause");
    system("cls");
}

void menu(LDEnc* playlist){
    int opcao;
    char musica[40];
    Node* current = playlist->head;
    do {
    
        printf("\n================================================================================\n");
        printf("||_____1. Mostrar playlist em ordem de cadastro_______________________________||\n");
        printf("||_____2. Mostrar playlist ordenada pelo nome das musicas_____________________||\n");
        printf("||_____3. Adicionar musica____________________________________________________||\n");
        printf("||_____4. Remover musica______________________________________________________||\n");
        printf("||_____5. Buscar Musica_______________________________________________________||\n");
        printf("||_____6. Tocar proxima musica________________________________________________||\n");
        printf("||_____7. Tocar musica anterior_______________________________________________||\n");
        printf("||_____8. Mostrar musica atual________________________________________________||\n");
        printf("||_____0. Sair________________________________________________________________||\n");
        printf("================================================================================\n");
        printf("\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer de entrada
        system("cls");

        switch (opcao){
            case 1:
                showPlaylistIO(playlist); //ShowPlaylistInOrder
                break;
            case 2:
                showPlaylistSN(playlist); //ShowPlaylistSongName
                break;
            case 3:
                readMusic(playlist);
                break;
            case 4:
                printf("Digite o nome da musica a ser removida: ");
                fgets(musica, sizeof(musica), stdin);
                musica[strcspn(musica, "\n")] = '\0'; // Remove a nova linha do final
                removeSong(playlist, musica);

                system("pause");
                system("cls");
                break;
            case 5:
                printf("Digite o nome da musica que deseja buscar: ");
                fgets(musica, sizeof(musica), stdin);
                musica[strcspn(musica, "\n")] = '\0'; // Remove a nova linha do final
                searchSong(playlist, musica);
                system("pause");
                system("cls");
                break;
            case 6:
                playNext(&current);
                currentSong(current);
                break;
            case 7:
                playPrev(&current);
                currentSong(current);
                break;
            case 8:
                currentSong(current);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);


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