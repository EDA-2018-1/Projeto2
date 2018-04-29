#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>  
#include<unistd.h> 

void foo(int *buf, int count) {
    for(int i = 0; i < count; ++i)
        buf[i] = i;
}

/* sorteiaTesteTreino
    params: 
null
    return: 
retorna um array de 50 posições unicas dos 50 arquivos que serão de teste ou leitura
*/
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
    }while(x < 50);

    return n;
}

/* salvaArquivos
    params: 
int imagemTreino = array para numeros dos arquivos de teste 
int imagemTeste = array para numeros dos arquivos de treino
int testeOuTreino: 0 teste 1 treino
int gramaOuAsfalto: 0 grama 1 asphalt
*/

FILE* salvaArquivos(int *array, int testeOuTreino, int gramaOuAsfalto){
    char diretorio[256];
    char linha[256];
    char nome[10];
    int i = 0;
    
    for (i=0; i<25; i++){
        printf("%d\n", array[i]);
    }

    if(testeOuTreino == 0 && gramaOuAsfalto == 0){
        strcpy(nome,"teste_grass.txt");
        strcpy(diretorio,"DataSet/grass/grass_");
    }
    else if (testeOuTreino == 0 && gramaOuAsfalto == 1){
        strcpy(nome,"teste_asphalt.txt");
        strcpy(diretorio,"DataSet/asphalt/asphalt_");
    }
    else if (testeOuTreino == 1 && gramaOuAsfalto == 0){
        strcpy(nome,"treino_grass.txt");
        strcpy(diretorio,"DataSet/grass/grass_");
    }
    else if (testeOuTreino == 1 && gramaOuAsfalto == 1){
        strcpy(nome,"treino_asphalt.txt");
        strcpy(diretorio,"DataSet/asphalt/asphalt_");
    }
    else{
        printf("ERRO");
    }
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
            printf(temp);
        }
    } 
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

    for(i = 0; i < (25); ++i){
        asfaltoTreino[i] = *(ordemImagensAsfalto+i);
        gramaTreino[i] = *(ordemImagensGrama+i);
    }
    for(; i < 50; ++i){
        asfaltoTeste[i - 25] = *(ordemImagensAsfalto+i);
        gramaTeste[i- 25] = *(ordemImagensGrama+i);
    }
    
    FILE* listaArquivosTesteGrama = salvaArquivos(gramaTeste, 0, 0);
    sleep(1);
    FILE* listaArquivosTesteAsfalto = salvaArquivos(asfaltoTeste, 0, 1);
    sleep(1);
    FILE* listaArquivosTreinoGrama = salvaArquivos(gramaTreino, 1, 0);
    sleep(1);
    FILE* listaArquivosTreinoAsfalto = salvaArquivos(asfaltoTreino, 1, 1);

   return 0;
}

/* calculaDimensaoArquivo
    params: 
char* NomeArquivo = nome do arquivo
FILE** arquivo = arquivo a ser aberto 
    return: 
int dimensaoMatriz = retorna um array com o número de linhas(dimensaoMatriz[0]) e colunas(dimensaoMatriz[1])
*/

// int* calculaDimensaoArquivo(char* nomeArquivo, FILE** arquivo){
// }

/* fazMatriz
    params: 
int*** matriz = matriz que vai ser passsada para ser alocada dinamicamente
int* dimensaoMatriz = array com o número de linhas(dimensaoMatriz[0]) e colunas(dimensaoMatriz[1])
    return: 
matrizAlocada = matriz alocada com sucesso;
return 0 = alocacao deu certo; 
return 1 = alocacao falhou;
*/
//int fazMatriz(int*** matriz, int* dimensaoMatriz){}

/* armazenaArquivo
    params: 
char* NomeArquivo = nome do arquivo
FILE** arquivo = arquivo a ser aberto 
    return: 
arquivoMatriz = retorna arquivo armazenado numa matriz
*/
//int armazenaArquivo(char* nomeArquivo, FILE** arquivo){}


