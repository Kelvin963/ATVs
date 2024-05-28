#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLinhas 500

int main(){
    char linha[100];
    char *nlinhas[MaxLinhas];
    int contador = 0;

    FILE *arquivo = fopen ("artistas.txt", "r");

    if (arquivo == NULL){
        printf("Error ao abrir o arquivo \n"); 
        return 1;
    }

    while(fgets(linha, sizeof (linha), arquivo) != NULL && contador < MaxLinhas){
        nlinhas[contador] = malloc(strlen(linha) + 1); //malloc serve para alocar dinamicamente uma memoria para guardar cada linha lida mais abaixo. strlen calcula o tamanho da linha para malloc alocar a memoria
        if(nlinhas[contador] == NULL){

            printf("Error ao alocar memória\n");

            fclose (arquivo);

            return 1;
        }

        strcpy(nlinhas[contador], linha); //copia o conteudo de linha para cada posição de nlinhas
        contador++;
    }
        
    fclose (arquivo);

    for (int i = 0; i < contador; i++){
        printf(nlinhas[i]);
        free(nlinhas[i]);
    }






 



    return 0;
}