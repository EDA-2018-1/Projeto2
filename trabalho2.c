/*
 *Integrantes:
 *  Rafael Braganca 10/0120181
 *  Cecília Dib 14/0134425
 *  Ícaro 15/0129807
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int *sorteiaTesteTreino(){
    srand(time(NULL));
    int *n = (int *)malloc(50*sizeof(int));

    int x = 1, y = 0, z = 0;
    n[0] = rand() % 50 + 1;
    do
    {
        n[x] = rand() % 50  + 1;
        y = 0;
        while(y < x)
        {
            if(n[y] == n[x])
            {
                --x;
                break;
            }
            ++y;
        }
        ++x;
    } while(x < 50);
    return n;
}

int salvaArquivos(int *array, int testeOuTreino, int gramaOuAsfalto){
    char nome[20];
    char diretorio[256];
    char linha[256];
    int i = 0;
    int tipo;

    if(testeOuTreino == 0 && gramaOuAsfalto == 0){
        strcpy(nome,"teste_grass.txt");
        strcpy(diretorio,"DataSet/grass/grass_");
        tipo = 0;
    }
    else if (testeOuTreino == 0 && gramaOuAsfalto == 1){
        strcpy(nome,"teste_asphalt.txt");
        strcpy(diretorio,"DataSet/asphalt/asphalt_");
        tipo = 1;
    }
    else if (testeOuTreino == 1 && gramaOuAsfalto == 0){
        strcpy(nome,"treino_grass.txt");
        strcpy(diretorio,"DataSet/grass/grass_");
        tipo = 2;
    }
    else if (testeOuTreino == 1 && gramaOuAsfalto == 1){
        strcpy(nome,"treino_asphalt.txt");
        strcpy(diretorio,"DataSet/asphalt/asphalt_");
        tipo = 3;
    }
    else{
        printf("ERRO");
    }
    printf("Criando: %s \n", nome);

    FILE *arquivo = NULL;
    arquivo = fopen(nome, "wt");

    int aux, aux2;
    char temp[50];

    for(i = 0; i < 25; i++){
         if(array[i]<10){
            aux = sprintf(temp, "%s0%d.txt\n", diretorio, array[i]);
            fprintf(arquivo, temp);
         }else if(array[i]>=10){
            aux = sprintf(temp, "%s%d.txt\n", diretorio, array[i]);
            fprintf(arquivo, temp);
        }
    }
    fclose(arquivo);
    return tipo;
}

void nomeArquivo(int codigoArquivo, char* nome){
    switch(codigoArquivo){
    case(0):
    strcpy(nome,"teste_grass.txt");
    break;

    case(1):
    strcpy(nome,"teste_asphalt.txt");
    break;

    case(2):
    strcpy(nome,"treino_grass.txt");
    break;

    case(3):
    strcpy(nome,"treino_asphalt.txt");
    break;
    }
}


void pegaLinhaNome(int codigoArquivo, int linha, char* filename, char* conteudoLinha){
    nomeArquivo(codigoArquivo, filename);
    FILE *fptr;

    fptr = fopen(filename, "r");
    rewind(fptr);
    int count = 0;
    char buffer[256];
    while (fgets(buffer, sizeof buffer, fptr))
    {
        if (count == linha){
            break;
        }
        else{
            count++;
        }
    }

    strtok(buffer, "\n");
    printf("este eh o buffer %s\n", buffer);
    strcpy(conteudoLinha, buffer);
    fclose(fptr);
}

int* calculaDimensao(char* filename){
    int *dimensaoMatriz = (int*) calloc (2,sizeof(int));

    printf(filename);

    FILE *arq;
    char c, end = '\n';
    int eol = 0;


    if ((arq = fopen(filename, "r")) == NULL) {
        printf("Erro ao abrir o arquivo.");
    }
    else {
        while(fread(&c, sizeof(char), 1, arq)) {
            if (c == '\n'){
              //  printf("%d",dimensaoMatriz[0]);
                dimensaoMatriz[0]++;
                eol = 1;
            }
            if(c == ';' && eol == 0){
                dimensaoMatriz[1]++;
            }
        }
    }
    dimensaoMatriz[1]++;

    sleep(1);
    printf("dimensao matriz %d\t %d", dimensaoMatriz[0], dimensaoMatriz[1]);

    fclose(arq);
    return dimensaoMatriz;
}

void calculaILBP(int mat[], int lin, int col){
    int i = 0;
    int j = 0;

    // for (i = 0 ;i<lin;i++){
    //     for(j=0;col;j++){
          printf("%d\t", (*mat + 0)+0 );
    //     }
    //     printf("\n");
    // }

   int* ilbp = (int *)calloc(pow(2, 9), sizeof(int));
   FILE* ilbp_file;
   fopen("ilpb.txt", "w");

/*matriz normal*/
	        // top line *(*(a+i)+j)
	        // *(*(aux+0)+0) = (i == 0 || j == 0) ? 0 : *(*(mat + ((i - 1) * col) + (j - 1)));
	        // *(*(aux+0)+1) = (i == 0) ? 0 : *(*(mat + ((i - 1) * col) + j));
	        // *(*(aux+0)+2) = (i == 0 || j == (col - 1)) ? 0 : *(*(mat + ((i - 1) * col) + (j + 1)));

	        // // center line
	        // *(*(aux+1)+0) = (j == 0) ? 0 : *(*(mat + (i * col) + (j - 1)));
	        // *(*(aux+1)+1) = *(*(mat + (i * col) + j)); // center piece
	        // *(*(aux+1)+2) = (j == (col - 1)) ? 0 : *(*(mat + (i * col) + (j + 1)));

	        // // botton line
	        // *(*(aux+2)+0) = (i == (lin - 1) || j == 0) ? 0 : *(*(mat + ((i + 1) * col) + (j - 1)));
	        // *(*(aux+2)+1) = (i == (lin - 1)) ? 0 : *(*(mat + ((i + 1) * col) + j));
	        // *(*(aux+2)+2) = (i == (lin - 1) || j == (col - 1)) ? 0 : *(*(mat + ((i + 1) * col) + (j + 1)));
/*matriz de ponteiro*/

// 	        // aux[0][0] = (i == 0 || j == 0) ? 0 : img[i-1][j-1];
// 	        // aux[0][1] = (i == 0) ? 0 : img[i-1][j];
// 	        // aux[0][2] = (i == 0 || j == (col - 1)) ? 0 : img[i-1][j+1];

// 	        // aux[1][0] = (j == 0) ? 0 : img[i][j-1];
// 	        // aux[1][1] = img[i][j];
// 	        // aux[1][2] = (j == (col - 1)) ? 0 : img[i][j+1];

// 	        // aux[2][0] = (i == (lin - 1) || j == 0) ? 0 : img[i+1][j-1];
// 	        // aux[2][1] = (i == (lin - 1)) ? 0 : img[i+1][j];
// 	        // aux[2][2] = (i == (lin - 1) || j == (col - 1)) ? 0 : img[i+1][j+1];

//             for (i=0; i<3; i++){
//                 for (j=0;j<3;j++){
//                     fprintf(ilbp_file, "%d", *(*(aux + i)+j));
//                 }
//                 printf("\n");
//             }
//                     printf("\n");
//     	}
}


void armazenaArquivoMatriz(char* filename){
    int* dimensaoMatriz;
    dimensaoMatriz = calculaDimensao(filename);
    int lin = dimensaoMatriz[0];
    int col = dimensaoMatriz[1];


    FILE *file;
    file = fopen(filename, "r");

    int **matrizImagem = (int**)calloc(lin,sizeof(int*));

    for(int i=0; i<lin; i++){
        matrizImagem[i]=(int*)calloc(col,sizeof(int));
    }

    rewind(file);

    if(file==NULL){
    printf("ERRO!\n");
    } else {
        for(int i=0; i<lin-1; i++){
          for(int j=0; j<col-1; j++){
     	       fscanf(file, "%d%*c", &matrizImagem[i][j]);
	        }
        }
    }
	sleep(1);
	//printf("Preparando imagem pro ILPB...");
	sleep(1);
    calculaILBP(matrizImagem, lin, col);

    printf("\n");

/*descomentar pra ver matrizes*/

    // for (int i=1;i<dimensaoMatriz[0]-1;i++){
    //     for(int j=1;j<dimensaoMatriz[1]-1;j++){
    //       printf("%d\t",matrizImagem[i][j] );
    //     }
    //     printf("\n");
    // }

    fclose(file);
}


int main () {
    int * ordemImagensAsfalto;
    int * ordemImagensGrama;

    ordemImagensAsfalto = sorteiaTesteTreino();
    sleep(1);
    ordemImagensGrama = sorteiaTesteTreino();

    int asfaltoTreino[25] = {0};
    int asfaltoTeste[25] = {0};
    int gramaTreino[25] = {0};
    int gramaTeste[25] = {0};

    int i;

    printf("Sorteando arquivos de Treino... \n");
    for(i = 0; i < (25); ++i){
        asfaltoTreino[i] = *(ordemImagensAsfalto+i);
        gramaTreino[i] = *(ordemImagensGrama+i);
    }

    sleep(1);

    printf("Sorteando arquivos de Teste...\n");
    for(; i < 50; ++i){
        asfaltoTeste[i - 25] = *(ordemImagensAsfalto+i);
        gramaTeste[i - 25] = *(ordemImagensGrama+i);
    }

    sleep(1);
    printf("Criando arquivos...\n");

    sleep(1);
    int listaArquivosTesteGrama = salvaArquivos(gramaTeste, 0, 0);

    sleep(1);
    int listaArquivosTesteAsfalto = salvaArquivos(asfaltoTeste, 0, 1);

    sleep(1);
    int listaArquivosTreinoGrama = salvaArquivos(gramaTreino, 1, 0);

    sleep(1);
    int listaArquivosTreinoAsfalto = salvaArquivos(asfaltoTreino, 1, 1);

    char arquivoNome[50];
    char conteudoLinha[256];

    int linha, codigoArquivo;

    //treinamento do sistema

    for (codigoArquivo = 2; codigoArquivo < 4; codigoArquivo++){
        for (linha = 0; linha < 25; linha++){
            pegaLinhaNome(codigoArquivo, linha, arquivoNome, conteudoLinha);
            sleep(1);
           armazenaArquivoMatriz(conteudoLinha);
        }
    }

    return 0;
}
