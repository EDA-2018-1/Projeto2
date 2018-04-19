#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *arq;
    char c, end = '\n';
    int qtdLinhas = 0, qtdColunas = 0;
    char* filename = "DataSet/asphalt/asphalt_01.txt";

    if ((arq = fopen(filename, "r")) == NULL) {
        printf("Erro ao abrir o arquivo.");         
    } else {
        //Lendo o arquivo 1 por 1
        while(fread(&c, sizeof(char), 1, arq)) {
            if(c == end) {
                qtdLinhas++;
            }
        }
    }

    printf("\nLinhas: %i\n", qtdLinhas);
    printf("Colunas: %i\n\n", qtdColunas);

    fclose(arq);

}


// DataSet/asphalt/asphalt_01.txt