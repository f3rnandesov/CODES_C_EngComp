#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Funções de ordenação
void bubbleSort(int *v, int n);
int obterMin(int *v, int i, int n);
void selectionSort(int *v, int n);

// Funções auxiliares
void imprimir(int *v, int n);
int *createV(int n);
int *copy(int *v, int n);
int menu();

int main() {
    clock_t t1, t2;
    int *v1, *v2;
    int n=180000;

    printf("\nCriando Vetor 1...");
    v1=createV(n);
    v2=copy(v1,n);
    printf("\nCopiando Vetor 1 para Vetor 2...");

    int sair=0;
    do{
          switch(menu()){
            case 1:
                printf("\nbubbleSort: ordenando...");
                t1 = clock();
                bubbleSort(v1,n);
                t2 = clock();
                printf("\nTempo: %f segundos\n", ((double)(t2 - t1)) / CLOCKS_PER_SEC);
                system("pause");
              break;
            case 2:
                printf("\nselectionSort: ordenando...");
                t1 = clock();
                selectionSort(v2,n);
                t2 = clock();
                printf("\nTempo: %f segundos\n", ((double)(t2 - t1)) / CLOCKS_PER_SEC);
                system("pause");
              break;
            case 3:
                imprimir(v1,n);
              break;
            case 4:
                imprimir(v2,n);
              break;
            case 5:
                sair=1;
              break;
            default:
                printf("opcao invalida!");
        }
    }while(!sair);

	return 0;
}


void bubbleSort(int v[], int n) {
    for(int i=1; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            if( v[j]>v[j+1] ) {
                int x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
            }
        }
    }
}
// Encontra o índice do menor valor a partir de i até n
int obterMin(int v[], int i, int n) {
    int k=i;
    for(int j=i+1; j<n; j++) {
        if( v[k]>v[j] ) {
            k=j;
        }
    }
    return k;
}
void selectionSort(int v[], int n) { //Ordenação por seleção
    int k, x;
    for(int i=0; i<n-1; i++) {
        k = obterMin(v,i,n);
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }
}


void imprimir(int *vet, int n) {
    for(int i=0;i<n;i++) {
       printf("%d  ", vet[i]);
    }
}

int* createV(int n) {
    srand(time(NULL));  // Inicializa gerador de números aleatórios
    int *vet = (int*)malloc(n*sizeof(int));
	for (int i=0; i<n; i++) {
		vet[i] = rand() % n + 1;
	}
	return vet;
}

int *copy(int *v, int n) {
    int *copyVetor = (int*)malloc(n*sizeof(int));
    for(int i=0 ; i < n ; i++) {
        copyVetor[i] = v[i];
    }
    return copyVetor;
}

int menu() {
    printf("\n\n\n");
    printf("\n1. bubbleSort. ");
    printf("\n2. selectionSort. ");
    printf("\n3. Imprimir Vetor 1. ");
    printf("\n4. Imprimir Vetor 2. ");
    printf("\n5. Sair. ");
    printf("\nDigite a opcao desejada: ");
    int op;
    scanf("%d",&op);
    return op;
}
