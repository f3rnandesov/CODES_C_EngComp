#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *left;
    struct No *right;
    int altura;
}NoArv;

NoArv *criar_no(int valor){
    NoArv novoNo = malloc(sizeof(NoArv));
    if (novoNo != NULL){
        novoNo->info = valor;
        novoNo->left = NULL;
        novoNo->right = NULL;
        novoNo->altura = 0;
    }else{
        printf("\nErro ao Alocar Memória!");
    }
    return novoNo;
}

int maior(int a, int b){
    return (a > b)? a: b;
}

int altura_no(NoArv *raiz){
    if (raiz == NULL){
        return -1;
    }else{
        return raiz->altura;  
    }
}

int fator_de_balanceamento(NoArv *raiz){
    if(raiz!=NULL){
        return (altura_no(raiz->left) - (altura_no(raiz->right));
    }else{
        return 0;
    }
}





