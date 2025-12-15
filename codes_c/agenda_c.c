#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    char nome[50];
    char telefone[20];
}Pessoa;

Pessoa agenda[MAX];
int qtd = 0;

//Ordenar por nome
void bubble_sort(Pessoa v[], int n){
    Pessoa temp;
    for (int i=0; i<n-1; i++){
        for (int j=0; i<n-i-1; j++){
            if(strcmp(v[j].nome, v[j+1].nome) > 0){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void selection_sort(Pessoa v[], int n){
    Pessoa temp;

    for(int i=0; i<n-1; i++){
        min = i;
        for (j = i+1; j<n; j++){
            if(strcmp(v[j].nome, v[min].nome) < 0){
                min = j;
            }
        }
        if (min != i){
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}
int busca_linear(Pessoa v[], int n, char nome[]){
    for (int i=0; i<n; ì++){
        if (strcmp(v[i].nome, nome) == 0){
            return i
        }
    }
    return -1;
}

int buscaBinaria(Pessoa v[], int n, char nome[]){
    int inicio =0; fim = n-1, meio;
    while (inicio<=fim){
        meio = inicio + (fim - inicio) / 2;
        int cmp = strcmp(v[meio].nome , nome);
        if (cmp == 0){
            return meio;
        }else if(cmp < 0){
            inicio = meio + 1;
        }else{
            fim  = meio - 1;
        }
    }
    return -1;
}

void excluir_pessoa(Pessoa v[], int *n, int id){
    int pos = buscaLinear(V, *n, id);
    if (pos == -1){
        printf("Pessoa com ID %d não encontrada!\n", id);
        return;
    }

    for (int i=pos; i<*n-1; i++){
        v[i] = v[i+1];
    }
    (*n)--;
    printf("Pessoa com ID %d excluida com sucesso!\n", id);
}

void mostrar_agenda(Pessoa v[], int n){
    if (n == 0){
        printf("Agenda Vazia\n");
        return;
    }
    printf("\n. Agenda:\n");
    for(int i=0; i<n; i++){
        printf("%d) Nome: %s | ....", v[i].nome..);
    }
}

void menu(){
    int op;
    char nome[50];

    do{
        printf("\n--MENU AGENDA--\n");
        printf("1 - Inserir pessoa\n");
        printf("2 - Mostrar agenda\n");
        printf("3 - Ordenar (BubbleSort)\n");
        printf("4 - Ordenar (SelectionSort)\n");
        printf("5 - Buscar (Linear)\n");
        printf("6 - Buscar (Binária)\n");
        printf("7 - Excluir pessoa\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (op){
            case 1:
                if (qtd == MAX){
                    printf("Agenda Cheia!\n");
                }else{
                    printf("Nome: ");
                    fgets(agenda[qtd].nome, 50, stdin);
                    agenda[qtd].nome[strcspn(agenda[qtd].nome, "\n")] = '\0';
                    printf("Telefone: ");
                }
            case 2:
                mostrar_agenda(agenda, qtd);
                break;
            case 3:
                bubbleSort(agenda, qtd);
                printf("Agenda ordenada (BubbleSort)!\n");
                break;

            case 4:
                selection_sort(agenda, qtd);
                printf("Agenda ordenada (selectionSort)!\n");
                break;

            case 5:
                printf("Nome para buscar: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                {
                    int pos = busca_linear(agenda, qtd, nome);
                    if(pos != -1){
                        printf("Encontrado: %s - %s\n", agenda[pos].nome, agenda[pos].telefone);
                    }else{
                        printf("pessoa não encontrada!\n");
                    }
                }
                break;
            case 6:

        }
    }

}








