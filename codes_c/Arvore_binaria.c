#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *left;
    struct No *right;
}NoArv;

NoArv *inserir_COM_return(NoArv *raiz, int valor){
    if(raiz == NULL){
        NoArv *novoNo = (NoArv *)malloc(sizeof(NoArv));
        novoNo->info = valor;
        novoNo->left = NULL;
        novoNo->right = NULL;
        return novoNo;
    }else{
        if(valor < raiz->info){
            raiz->left = inserir_COM_return(raiz->left, valor);
        }else{
            raiz->right = inserir_COM_return(raiz->right, valor);
        }
        return raiz;
    }
}

void inserir_SEM_return(NoArv **raiz, int valor){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->info = valor;
        (*raiz)->left = NULL;
        (*raiz)->right = NULL;
    }else{
        if(valor < (*raiz)->info){
            inserir_SEM_return(&((*raiz)->left), valor);
        }else{
            inserir_SEM_return(&((*raiz)->right), valor);
        }
    }
}



void *inserir_SEM_returnErecursivo(NoArv **raiz, int valor){
    NoArv *aux = *raiz;
    while(aux!=NULL){
        if(valor < aux->info){
            raiz = &aux->left;
        }else{
            raiz = &aux->right;
        }
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->info = valor;
    aux->left = NULL;
    aux->right = NULL;
    *raiz = aux;
}


NoArv *busca_recursiva(NoArv *raiz, int valor){
    if(raiz!=NULL){
        if(valor == raiz->info){
            return raiz;
        }else if(valor < raiz->info){
            return busca_recursiva(raiz->left, valor);
        }else{
            return busca_recursiva(raiz->right, valor);
        }
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz==NULL){
        return -1;
    }else{
        int left = altura(raiz->left);
        int right = altura(raiz->right);
        if(left > right){
            return left + 1;
        }else{
            return right + 1;
        }
    }
}

int quant_nos(NoArv *raiz){
    if(raiz==NULL){
        return 0;
    }else{
        return 1 + quant_nos(raiz->left) + quant_nos(raiz->right);
    }
}


int quant_folhas(NoArv *raiz){
    if(raiz==NULL){
        return 0;
    }else  if(raiz->left == NULL && raiz->right == NULL){
        return 1;
    }else{
        return quant_folhas(raiz->left) + quant_folhas(raiz->right);
    }
}

void pre_ordem(NoArv *raiz){
    if(raiz!=NULL){
        printf("%d ", raiz->info);
        pre_ordem(raiz->left);
        pre_ordem(raiz->right);
    }
}

void in_ordem(NoArv *raiz){
    if(raiz!=NULL){
        in_ordem(raiz->left);
        printf("%d ", raiz->info);
        in_ordem(raiz->right);
    }
}

int main(){
    NoArv *busca, *raiz = NULL;
    int op, valor;

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n4 - Altura\n5 - Nos\n6 - Folhas\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
               // raiz = inserir(raiz, valor);
               inserir_SEM_return(&raiz, valor);
                break;
            case 2:
                printf("\nPre Ordem: \n");
                pre_ordem(raiz);
                printf("\n");
                printf("\nIn Ordem: \n");
                in_ordem(raiz);
                printf("\n");
                break;
            case 3:
                printf("Digite o valor de busca: ");
                scanf("%d", &valor);
                busca = busca_recursiva(raiz, valor);
                if(busca){
                    printf("\n\tValor encontrado: %d\n\t", busca->info);
                }else{
                    printf("\n\tValor não encontrado\n\t");
                }
                break;
            case 4:
                printf("\nAltura da Arv: %d\n\n", altura(raiz));
                break;
            case 5:
                printf("\nQuantidade de nos: %d", quant_nos(raiz));
                break;
            case 6:
                printf("\nQuantidade de folhas: %d", quant_folhas(raiz));
                break;
            default:
                if(op!=0){
                    printf("\n\tInvalido\n");
                }
        }
    }while(op!=0);
    return 0;
}
