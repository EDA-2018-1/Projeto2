#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *arq;
    char c, end = '\n';
    int qtdLinhas = 0, qtdColunas = 1;
    char* filename = "DataSet/asphalt/asphalt_01.txt";
    int eol = 0;

    if ((arq = fopen(filename, "r")) == NULL) {
        printf("Erro ao abrir o arquivo.");         
    } else {
        while(fread(&c, sizeof(char), 1, arq)) {
            if (c == '\n'){
                qtdLinhas++;
                eol = 1;
            }
            if(c == ';' && eol == 0){
                qtdColunas++;
            } 
        }
    }

    printf("\nLinhas: %i\n", qtdLinhas);
    printf("Colunas: %i\n\n", qtdColunas);

    fclose(arq);

}

// DataSet/asphalt/asphalt_01.txt