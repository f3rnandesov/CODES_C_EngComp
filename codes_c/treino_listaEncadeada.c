#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}Lista;

Lista *criar_lista(){
    return NULL;
}

Lista *insere_info(Lista *l, int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

Lista *buscar_no (Lista *l, int valor_buscado){
    Lista *p;
    for (p=l; p!=NULL; p=p->prox){
        if (p->info == valor_buscado){
            return p;
        }
    }
}
//INSERIR UM NÓ NO FINAL DA LISTA

Lista *inserir_no_final(Lista *l, int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL; //Será o ultimo, então o prox = NULL

    if (l == NULL){
        return novo; //O novo no vira o primeiro
    }else{
        Lista *p;
        for (p=l; p->prox!=NULL; p=p->prox);
        p->prox = novo; //Quando chegar no ultimo vai ligar o novo nó
        return l; //Retorna o início da lista (que não muda)
    }
}

//INSERIR UM NÓ EM ORDEM CRESCENTE
Lista *ordem_crescente(Lista *l, int valor){
    Lista *novo_crescente = (Lista *)malloc(sizeof(Lista));
    novo_crescente->info = valor;
    novo_crescente->prox = NULL;
    if (l == NULL || valor < l->info){//Se a lista estiver vazia ou o valor é menor que o primeiro nó da lista, então o novo valor vai ser o primeiro da lista
        novo_crescente->prox = l;
        return novo_crescente;
    }
    Lista *ant; //nó anteriors
    Lista *p = l->prox;//nó proximo do anterior
    while(p->info || p->info < valor){
        ant = p;
        p = p->prox;
    }//avança ate onde o valor novo deve entrar
    novo_crescente->prox = p;
    ant->prox = novo_crescente;


}
int isEmpty(Lista *l){
    return l==NULL;
}

void imprimir(Lista *l){
    Lista *p;
    for (p=l; p!=NULL; p=p->prox){
        if(p->prox != NULL){
            printf("[%d | %x] - >", p->info, p->prox);
        }
    }
}

Lista *retirar(Lista *l, int valor){
    Lista *ant = NULL;
    Lista *p=l;
    while (p!=NULL && p->info) {
        ant = p;
        p=p->prox;
    }

    if (p==NULL) {
        return l;
    }

    if (ant==NULL) {
        l = p->prox;
    }else {
        ant->prox = p->prox;
    }
    free(p);
    return l;

}
//REMOVER TODOS OS NÓS QUE CONTENHA UM VALOR ESPECIFICO
Lista *remover_nos_especifico(Lista *l, int valor){
    Lista *p=l;
    Lista *ant = NULL;

    while(p!=NULL){
        if(p->info == valor){
            if (ant == NULL){
                //Caso 1: Nó a remover é o primeiro
                l = p->prox;
                free(p);
                p=l;
            }else{
                //Caso 2: Nó a remover está no meio ou no final
                ant->prox = p->prox;
                free(p);
                p=ant->prox;
            }
        }else{
            //Segue percorrendo
            ant = p;
            p=p->prox;
        }
    }
    return l;
}


//RETORNAR O NUMERO TOTAL DE NÓS NA LISTA

int retornar_numero_t(Lista *l){
    Lista *p;
    int quant = 0;
    for (p = l; p != NULL; p = p->prox){
        quant++;
    }
    return quant;
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
    Lista *minhalista = criar_lista();

    minhalista = insere_info(minhalista, 12);
    minhalista = insere_info(minhalista, 45);
    minhalista = insere_info(minhalista, 10);
    minhalista = insere_info(minhalista, 20);

    imprimir(minhalista);

    Lista *r  = buscar_no(minhalista, 45);

    if (r!=NULL) {
        printf("\nNO com o valor %d encontrado.", r->info);
    }

    minhalista = insere_info(minhalista, 600);
    minhalista = insere_info(minhalista, 510);
    minhalista = insere_info(minhalista, 420);

    imprimir(minhalista);

    int result = retornar_numero_t(minhalista);
    printf("\n\nQuantidade nós: %d\n", result);

	return 0;
}

