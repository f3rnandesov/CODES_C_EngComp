#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	int info;
	struct no *prox;
}Lista;

Lista* crialista() {
    return NULL;
}

Lista* insere(Lista *list, int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = list;
    return novo;
}

void imprime (Lista *list) {
    Lista *p;
    printf("\n\n");
    for (p = list; p != NULL; p = p->prox) {
        if (p->prox!=NULL) {
            printf("[ %d | %x ]->", p->info, p->prox);
        }
    }
    printf("\n\n");
}

int estavazia(Lista *list) {
    return (list == NULL);
}

Lista* busca (Lista *list, int valor) {
    Lista* p;
    for (p=list; p!=NULL; p=p->prox) {
        if (p->info == valor) {
            return p;
        }
    }
    return NULL; /* não achou o elemento */
}


Lista *retirar(Lista *l, int v) {
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
    }
    else {
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

Lista* libera(Lista* lista) {
    Lista *p = lista;
    while (p != NULL) {
        lista = p->prox;
        free(p);
        p = lista;
    }
    return NULL;
}




int main() {
    Lista *minhalista = crialista();

    minhalista = insere(minhalista, 12);
    minhalista = insere(minhalista, 45);
    minhalista = insere(minhalista, 10);
    minhalista = insere(minhalista, 20);

    imprime(minhalista);

    Lista *r  = busca(minhalista, 45);

    if (r!=NULL) {
        printf("\nNO com o valor %d encontrado.", r->info);
    }

    minhalista = insere(minhalista, 600);
    minhalista = insere(minhalista, 510);
    minhalista = insere(minhalista, 420);

    imprime(minhalista);


    minhalista = libera(minhalista);

    imprime(minhalista);

	return 0;
}

