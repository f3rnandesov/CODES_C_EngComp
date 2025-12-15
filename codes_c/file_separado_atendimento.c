#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int info;
    struct no *prox;
}Lista;

Lista *criar_lista(){
    return NULL;
}


//ITERATIVA
Lista *retirar(Lista *l, int valor){
    Lista *ant = NULL;
    Lista *p = l;
    while(p!=NULL && p->info!=valor){
        ant = p;
        p = p->prox;
    }
    //Verifica se achou o elemento
    if(p==NULL){
        return l;
    }
    //retirar o elemento
    if(ant==NULL){
        l = p->prox; //retirar o elemento do inicio
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}
Lista *retirar(Lista *l, int v){
    if(l==NULL) return NULL;
    Lista *ant = NULL;
    Lista *p = l;

    while(p!=NULL && p->info!=v){
        ant = p;
        p = p->prox;
    }

    if(p==NULL){
        return l;
    }
    if(ant==NULL){
        l=p->prox;
    }else{
        ant->prox=p->prox;
    }
    free(p);
    return l;
}


//ITERATIVA
Lista *busca(Lista *l, int v){
    Lista *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->info==v){
            return p;
        }
    }
}

//RECURSIVA
Lista *buscaR(Lista *l, int v){
    if (l==NULL){
        return NULL;
    }
    if(l->info==v){
        return l;
    }
    return buscaR(l->prox, v);
}


//ITERATIVA
int *contar(Lista *l){
    Lista *p;
    int q = 0;
    for(p=l; p!=NULL; p=p->prox){
        q++;
    }
    return q;
}
//RECURSIVA
int contarRR(Lista *l){
    if(l==NULL){
        return 0;
    }
    return 1+contarRR(l->prox);
}


void *liberar(Lista *l){
    Lista *p = l;
    while(p!=NULL){
        Lista *t = p->prox;
    }
}

//ITERATIVO
void *liberar(Lista *l){
    Lista *p=l;
    while(p!=NULL){
        p = l->prox;
        free(l);
        l = p;
    }
    return NULL;
}

//ITERATIVO
Lista *no_maior_valor(Lista *l){
    if(l==NULL){
        return NULL;
    }
    Lista *pMaior=l;
    for(Lista *p=l->prox; p!=NULL; p=p->prox){
        if(pMaior->info<p->info){
            pMaior = p;
        }
    }
    return pMaior;
}


//RECURSIVO
Lista *no_maior_valor_recursivo(Lista *l){
    if(l==NULL || l->prox==NULL){
        return l;
    }

    Lista *maior = no_maior_valor_recursivo(l->prox);

    if(l->info > maior->info){
        return l;
    }else{
        return maior;
    }
}
//ITERATIVO
Lista *no_m(Lista *l){
    if(l==NULL){
        return NULL;
    }

    Lista *pMaior=l;
    for(Lista *p=l->prox; p!=NULL; p=p->prox){
        if(p->info > pMaior->info){
            pMaior = p;
        }
    }
    return pMaior;
}

//RECURSIVO
Lista *no_m_recursivo(Lista *l){
    if(l==NULL || l->prox==NULL){
        return l;
    }

    Lista *maior = no_m_recursivo(l->prox);

    if(l->info > maior->info){
        return l;
    }else{
        return maior;
    }
}


/*
Implemente as funções para:
      a) retornar o número total de nós da lista.
      b) inserir um nó no final da lista.
      c) remover todos nós que contenha um valor específico.
      d) inserir um nó em ordem crescente
*/
//A - ITERATIVA
int *retornar_total(Lista *l){
    Lista *p;
    int quant = 0;
    for(p=l; p!=NULL; p=p->prox){
        quant++;
    }
    return quant;
}
//A - RECURSIVA
int *listar_recursiva(Lista *l){
    if(l==NULL){
        printf("[%d]", l->info);
        listar_recursiva(l->prox);
    }
}



//B
Lista *inserir_final_no_lista(Lista *l, int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;

    if(l==NULL){
        return novo;
    }else{
        Lista *p;
        for(p=l; p->prox!=NULL; p=p->prox);// Vai chegar no ultimo nó
        p->prox = novo;// Quando tiver no ultimo nó vai fazer a ligação
        return l;// Retornar a lista
    }
}

//C - Inserir nó de forma crescente

Lista *no_crescente(Lista *l, int valor){
    Lista *novo_crescente = (Lista *)malloc(sizeof(Lista));
    novo_crescente->info = valor;
    novo_crescente->prox = NULL;

    if (l==NULL || valor < l->info){//Se a lista estiver vazia ou o valor é menor que o primeiro nó da lista
        novo_crescente->prox = l;
        return novo_crescente;
    }else{
        Lista *ant;//Nó anterior
        Lista *p = l->prox;//Nó proximo do anterior
        while(p!=NULL || p->info < valor){
            ant = p;
            p = p->prox;
        }// avança ate onde o valor deve entrar
        novo_crescente->prox = p;
        ant->prox = novo_crescente;
    }
    return l;
}

//D - Remover todos os nós que tenha um valor especifico

Lista *remover_especifico_todos(Lista *l, int v){
    Lista *p = l;
    Lista *ant = NULL;

    while(p!=NULL){
        if(p->info == v){
            if(ant == NULL){//Caso 1: Se o valor específico é o primeiro
                l = p->prox;
                free(p);
                p=l;
            }else{//Caso 2: Se o valor estiver no meio ou no final
                ant->prox = p->prox;
                free(p);
                p = ant->prox;
            }
        }else{
            ant = p;
            p=p->prox;
        }
    }
    return l;
}

Lista *re_no_todos(Lista *l, int v){
    Lista *p=l;
    Lista *ant=NULL;
    while(p!=NULL){
        if(p->info == v){
            if(ant == NULL){
                l=p->prox;
                free(p);
                p=l;
            }else{
                ant->prox = p->prox;
                free(p);
                p = ant->prox;
            }
        }else{
            ant = p
            p = p->prox;
        }
    }
    return l;
}

/*
a) Reverter a Lista
Implemente uma função que inverta a ordem dos nós da lista encadeada. Se a lista for [1, 2, 3,4], após a reversão ela deve ser [4,3,2,1]. A reversão deve ser feita sem criar uma nova lista.

b) Remover Nós Duplicados
Implemente uma função que remova todos os nós duplicados de uma lista ordenada. Exemplo: se a lista for [1,2,2,3,4,4], a lista resultante deve ser [1,2,3,4]. A função deve manter apenas uma ocorrência de cada valor.

c) Intercalar duas listas
Dado duas listas, intercala seus elementos para formar uma nova lista (exemplo: [1,3,5] e [2, 4, 6] → [1,2,3,4,5,6]).
*/


//A - Reverter a lista

Lista *reverter_lista(Lista *l){
    Lista *anterior = NULL;
    Lista *proximo = NULL;
    Lista *p = l;

    while(p!=NULL){
        proximo = p->prox; //guarda o proximo nó
        p->prox = anterior;//Move o anterior para o atual
        anterior = p;//avança para o proximo nó
        p = proximo;
    }
    return anterior;//novo inicio da lista
}

Lista *rever(Lista *l){
    Lista *anterior = NULL;
    Lista *proximo = NULL;
    Lista *p = l;

    while(p!=NULL){
        proximo = p->prox;
        p->prox = anterior;
        anterior = p;
        p = proximo;
    }
    return anterior;
}

//B - Remover nós duplicados
Lista *remover_duplicados(Lista *l, int v){
    if(l==NULL) return l;
    if(l->prox==NULL) return l;

    Lista *p=l;
    while(p!=NULL){
        if(p->info == p->prox->info){
            Lista *temp = p->prox;
            p->prox = temp->prox;
            free(temp);
        }else{
            p = p->prox;
        }
    }
    return l;
}


//C - Intercalar duas listas
Lista *inter_listas(Lista *l1, Lista *l2){
    //Cria um nó sentinela (não faz parte do nó final)
    Lista NoInicio;
    NoInicio.prox = NULL;
    Lista *NoFim = &NoInicio;

    while(l1 != NULL && l2 != NULL){
        //Adiciona um nó de l1
        NoFim->prox = l1;
        l1 = l1->prox;
        NoFim = NoFim->prox;

        //Adiciona um nó de l2
        NoFim->prox = l2;
        l2 = l2->prox;
        NoFim = NoFim->prox;
    }
    if(l1!=NULL) NoFim->prox = l1;
    if(l2!=NULL) NoFim->prox = l2;
    return NoInicio.prox;
}

Lista *i_l(Lista *l1, Lista *l2){
    Lista InicioNo;
    InicioNo.prox = NULL;
    Lista *FimNo = &InicioNo;

    while(l1 != NULL && l2 != NULL){
        FimNo->prox = l1;
        l1 = l1->prox;
        FimNo = FimNo->prox;

        FimNo->prox = l2;
        l2 = l2->prox;
        FimNo = FimNo->prox;
    }
    if(l1==NULL) FimNo->prox = l1;
    if(l2==NULL) FimNo->prox = l2;
    return InicioNo.prox;
}

/*
Implemente uma função em C chamada isIgual que receba duas listas encadeadas e verifique se as listas são iguais.
*/
typedef struct{
    int info;
    struct no *prox;
}Lista1;

typedef struct{
    int info;
    struct no *prox;
}Lista2;

int *isIgual(Lista1 *l1, Lista2 *l2){
    Lista *p1=l1, *p2=l2

    while(p1!=NULL && p2!=NULL){
        if(p1->info!=p2->info){
            return 0;//Não são iguais
        }
        p1=p1->prox;
        p2=p2->prox;
    }
    //Se uma das listas ainda tiver elementos, estas não são iguais
    if(p1!=NULL || p2!=NULL){
        return 0;
    }
    return 1;
}


int *is(Lista *l1, Lista *l2){
    Lista *p1=l1, *p2=l2;

    while(p1!=NULL && p2!=NULL){
        if(p1->info!=p2->info){
            return 0;
        }
        p1=p1->prox;
        p2=p2->prox;
    }
    if(p1!=NULL || p2!=NULL){//
        return 0;
    }
}

int *i(Lista *l1, Lista *l2){
    Lista *p1=l1, *p2=l2;

    while(p1!=NULL && p2!=NULL){
        if(p1->info!=p2->info){
            return 0;
        }
        p1=p1->prox;
        p2=p2->prox;
    }
    if(p1!=NULL || p2!=NULL){
        return 0;
    }

    return 1;
}

//QUICK SORT
void quick_sort(int *v, int left, int right){
    int i, j;
    int pivo;
    pivo = v[(left+right)/2];
    do  {
        while(v[i]<pivo && i<right) i++;
        while(v[j]>pivo && j>left) j--;
            if (i<=j){
                int x = v[i];
                v[i] = v[j];
                v[j] = x;
                i++; j++;
            }
    }while(i<=j);
        if(left < j){
            quicksort(v, left, j);
        }
        if(right > i){
            quicksort(v, i, right);
        }
}

void quicksort(int v[], int left, int right){
    int i,j,pivo;
    pivo = v[(left+right)/2];
    do{
        while(v[i]<pivo&&i<right){
            i++;
        }
        while(v[j]>pivo&&j<left){
            j--;
        }
        if(i<=j){
            int aux = v[i];
            v[i] = v[j]
            v[j] = aux;
            i++;
            j--;
        }
    }while(i<=j);
        if(left < j){
            quicksort(v, left, j);
        }
        if(right>i){
            quicksort(v, i, right);
        }

}

void quicksort(int v[], int left, int right){
    int i, j, pivo;
    i = left;
    j = right;
    pivo = v[(left+right)/2];
    do{
        while(v[i]<pivo &&i<right) i++;
        while(v[j]>pivo&&j<left) j--;
        if(i<=j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j){
        quicksort(v, left, j);
    }
    if(right>i)
    {
        quicksort(v, i, right);
    }

}







































