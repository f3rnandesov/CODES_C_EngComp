#include <stdio.h>
#include <stdlib.h>

int mostrar_total_nos(Lista *l){
    Lista *p;
    int quant = 0;
    for (p=l; p!= NULL; p=p->prox){
        quant++;
    }
    return quant;
}

int mostrar_total_nos(Lista *l){
    Lista *p;
    int q = 0;
    for (p=l; p!=NULL; p=p->prox){
        quant++;
    }
    return quant;
}

int mostrar_total_nos(Lista *l){
    Lista *p;
    int quant = 0;
    for (p=l; p!=NULL; p=p->prox){
        `quant++;
    }
    return quant;
}


Lista *adicionar_no_final_lista(Lista *l  int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;

    if (l==NULL{
        return novo;
    }else{
        Lista *p;
        for(p=l; p!=NULL; p=p->prox); // Vai ate o ultimo nó
        p->prox = novo; //Liga o novo nó
        return l;
    }
}

Lista adicionar_no_final_lista(Lista *l, int valor){
    Lista *novo=(Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;

    if (l==NULL){
        return novo;
    }else{
        Lista *p;
        for(p=l; p!=NULL; p=p->prox);
        p->prox = novo;
        return l;
    }
}

