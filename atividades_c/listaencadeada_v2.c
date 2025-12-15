#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int info;
   struct no *prox;
}Lista;

Lista* crialista() {
    return NULL;
}

Lista* insere(Lista *l, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

void imprime (Lista *l) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        printf("[%d]%s", p->info, (p->prox!=NULL?"->":"->NULL"));
    }
    printf("\n");
}

void imprimeR(Lista *l) {
    if (l != NULL) {
      printf("[%d]%s", l->info, (l->prox!=NULL?"->":"->NULL"));
      imprimeR(l->prox);
    }
    printf("\n");
}

int estavazia(Lista *l) {
    return (l == NULL);
}

Lista* busca (Lista *l, int valor) {
    Lista* p;
    for (p=l; p!=NULL; p=p->prox) {
        if (p->info == valor) {
            return p;
        }
    }
    return NULL; /* não achou o elemento */
}

Lista *buscaR(Lista *l, int v) {
    if (l==NULL){
        return NULL;
    }
    if (l->info==v) {
        return l;
    }
    buscaR(l->prox, v);
}

Lista *retira(Lista *l, int v) {
    Lista *ant=NULL;
    Lista *p=l;
    while (p!=NULL  &&  p->info!=v) {
        ant = p;
        p=p->prox;
    }

    if (p==NULL) {
        return l;
    }

    if (ant==NULL) {
        l = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

int contaIte(Lista *l) {
    int x=0;
    Lista *p = l;
    while (p != NULL) {
        p = p->prox;
        x++;
    }
    return x;
}

int contaR(Lista *l) {
    if (l==NULL) {
        return 0;
    }
    return 1+contaR(l->prox);
}

Lista *insereOrdenado(Lista *l, int v) {
    Lista *ant=NULL;
    Lista *p=l;
    while(p!=NULL && p->info<v) {
        ant=p;
        p=p->prox;
    }
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info=v;
    if (ant==NULL) { //quando a lista está vazia, ou seja, o 1º nó é inserido
        novo->prox=l;
        l=novo;
    } else { //para os demais nós
        novo->prox=ant->prox;
        ant->prox=novo;
    }
    return l;
}

Lista* libera(Lista* l) {
    Lista *p = l;
    while (p != NULL) {
        p = l->prox;
        free(l);
        l = p;
    }
    return NULL;
}



int main() {
    Lista *myLista;

    myLista = crialista();

    myLista = insere(myLista, 12);
    myLista = insere(myLista, 45);
    myLista = insere(myLista, 10);
    myLista = insere(myLista, 20);

    imprime(myLista);
    imprimeR(myLista);

    Lista *p  = busca(myLista, 45);
    if (p!=NULL) {
        printf("\n\nNO com o valor %d encontrado.", p->info);
    }
    p  = buscaR(myLista, 20);
    if (p!=NULL) {
        printf("\n\nNO com o valor %d encontrado.", p->info);
    }
    myLista = retira(myLista,45);
    myLista = retira(myLista,12);

    printf("\n\n");
    imprimeR(myLista);

    myLista = insere(myLista, 60);
    myLista = insere(myLista, 51);
    myLista = insere(myLista, 42);
    myLista = insere(myLista, 10);
    myLista = insere(myLista, 31);
    myLista = insere(myLista, 22);

    printf("\n\n");
    imprimeR(myLista);


    Lista *myListaOrd = crialista();
    myListaOrd = insereOrdenado(myListaOrd, 8);
    myListaOrd = insereOrdenado(myListaOrd, 10);
    myListaOrd = insereOrdenado(myListaOrd, 9);
    myListaOrd = insereOrdenado(myListaOrd, 11);

    printf("\n\nInsere elemento em ordem:\n");
    imprime(myListaOrd);

    return 0;
}

