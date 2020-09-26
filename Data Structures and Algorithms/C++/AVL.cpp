#include <iostream>
using namespace std;

int grafo[10010][10010];
int vetor[10010];



void printgrafo(int x){
    int i,j;
    for(i=1;i<=x;i++){
        for(j=1;j<=x;j++){
            printf(" %i",grafo[i][j]);
        }
        printf("\n");
    }
}

int min(int tam,int aux[]){
    int i;
    int min = 10001;
    int mindex;

    for(i=1;i<=tam;i++){
        if(aux[i]==0 && vetor[i]<=min){
            min=vetor[i];
            mindex=i;
        }
    }
    return mindex;
}

void tuamae(int x,int tam){
    int aux[10010];
    int i,j;

    ///comecar zerado
    for(i=1;i<=tam;i++){
        aux[i]=0;
        vetor[i]=10001;
    }
    vetor[x]=0;
    ///
    for(i=1;i<tam;i++){
        int y=min(tam,aux);
        aux[y]=1;
        for(j=1;j<=tam;j++){
            if(!aux[j] && grafo[y][j] && vetor[y]!=10001 && vetor[y]+grafo[y][j]<vetor[j]){
                vetor[j]=vetor[y]+grafo[y][j];
            }
        }
    }


}

int main(){
    int i,j,l;
    int casos;
    int tam;
    int lig;
    int de,para,peso;

    scanf("%i",&casos);
    for(l=0;l<casos;l++){
        ///escanear tamanho
        scanf("%i %i",&tam,&lig);
        ///zerar o grafo e o vetor
        for(i=1;i<=tam;i++){
            vetor[i]=0;
            for(j=1;j<=tam;j++){
                grafo[i][j]=0;
            }
        }
        ///escanear ligacoes
        for(i=0;i<lig;i++){
            scanf("%i %i %i",&de,&para,&peso);
            grafo[de][para]=peso;
        }
        ///testes
/*
        printf("\n\nteste\n");
        for(i=1;i<=tam;i++){
            printf("%i ",vetor[i]);
        }
        printf("\n");
        printgrafo(tam);
*/
        ///ler pergunta
        scanf("%i %i",&de,&para);
        ///calcular distancia
        tuamae(de,tam);
        ///printar resposta
        if(vetor[para] == 10001){
            printf("NO\n");
        }
        else{
            printf("%i\n",vetor[para]);
        }

    }



    return 0;
}
