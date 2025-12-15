#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int info;
    struct no *prox;
} Lista;

Lista *crialista()
{
    return NULL;
}

Lista *insere(Lista *l, int v) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox=l;
    return novo;
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
/* função iterativa */
void listagem(Lista *l) {
    Lista *p;
    for (p=l; p!=NULL; p=p->prox)     {
        printf("%d  ", p->info);
    }
}
/* função Recursiva */
void listagemR(Lista *l) {
    if (l != NULL) {
      printf("%d  ", l->info);
      listagemR(l->prox);
    }
}
/* função iterativa */
Lista *busca(Lista *l, int v) {
    Lista *p;
    for (p=l; p!=NULL; p=p->prox)  {
        if (p->info == v)    {
            return p;
        }
    }
    return NULL;
}

/* função Recursiva */
Lista *buscaR(Lista *l, int v) {
    if (l==NULL){
        return NULL;
    }
    if (l->info==v) {
        return l;
    }
    return buscaR(l->prox, v);
}
/* função iterativa */
int conta(Lista *l){
    Lista *p;
    int x=0;
    for (p=l; p!=NULL; p=p->prox) {
        x++;
    }
    return x;
}
/* função Recursiva */
int contaR(Lista *l){
    if (l==NULL) {
        return 0;
    }
    return 1+contaR(l->prox);
}
/* função iterativa */
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
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return l;
}
/* função iterativa */
Lista* libera(Lista* lista) {
    Lista *p = lista;
    while (p != NULL) {
        p = lista->prox;
        free(lista);
        lista = p;
    }
    return NULL;
}
/* função iterativa */
Lista *obterNoComMaiorValor(Lista *l) {
    if (l == NULL) {
        return NULL;
    }
    Lista *pMaior=l;
    for(Lista *p=l->prox; p!=NULL; p=p->prox) {
        if (p->info > pMaior->info ) {
           pMaior = p;
        }
    }
    return pMaior;
}

/* função Recursiva */
Lista *obterNoComMaiorValorR(Lista *l) { /* 55, 50, 10 */
    if (l==NULL || l->prox == NULL) {
        return l;
    }

    Lista *maior = obterNoComMaiorValorR(l->prox);

    if (l->info > maior->info) {
        return l;
    } else {
        return maior;
    }
}
int estaOrdCresc(Lista *l){
    Lista *p=l;
    while(p!=NULL && p->prox!=NULL) {
       if (p->info > p->prox->info) {
             return 0;
       }
       p = p->prox;
    }
    return 1;
}


int isIgual(Lista *list1, Lista *list2){
    Lista *p1=list1, *p2=list2;

  /*  if ( p1==NULL || p2==NULL ) {
        return 0;
    }

   int tam1 = conta(p1);
    int tam2 = conta(p2);
    if (tam1!=tam2) {
        return 0;
    }*/

    while ( p1!=NULL && p2!=NULL ) {
        if (p1->info != p2->info) {
           return 0; //não são iguais
        }
        p1=p1->prox;
        p2=p2->prox;
    }


    // Se uma das listas ainda tiver elementos, elas não são iguais
    if (p1 != NULL || p2 != NULL) {
        return 0;
    }

    return 1; //são iguais
}

Lista *copia(Lista *l){

    if ( l == NULL ) {
        return NULL;
    }

    Lista *bkLista=crialista();
    Lista *p = l;
    while( p!=NULL ) {
        bkLista = insere(bkLista, p->info);
        p=p->prox;
    }
    return bkLista;
}


Lista *reverter3(Lista *l) {  /*[6]->[8]->[10]->NULL*/
    Lista *anterior = NULL;
    Lista *proximo = NULL;
    Lista *p = l;
    while (p != NULL) {
        proximo = p->prox; // guarda o próximo nó
        p->prox = anterior; // move 'anterior' para o atual
        anterior = p;       // avança para o próximo nó

       p = proximo;
    }
    return anterior; // novo início da lista
}

/*
Remove só duplicados adjacentes — ou seja, só remove se dois nós consecutivos têm info igual.
Exemplo:
3 -> 3 -> 7 -> 7 -> 5 → remove corretamente, vira 3 -> 7 -> 5.
*/

void removerDuplicados2(Lista* l) {
    Lista *p = l;
    while (p->prox != NULL) {
         if (p->prox->info != p->info) {
              p = p->prox;
         } else { /*achou duplicado adjacente*/
              Lista *temp = p->prox;
              p->prox = temp->prox;
              free(temp);
         }
    }
}
/* remover os duplicados mesmo não sendo adjacentes*/
void removerDuplicados3(Lista* head) {
    Lista* current = head;
    while (current != NULL) {
        Lista* runner = current;
        while (runner->prox != NULL) {
            if (runner->prox->info == current->info) {
                Lista* temp = runner->prox;
                runner->prox = runner->prox->prox;
                free(temp);
            } else {
                runner = runner->prox;
            }
        }
        current = current->prox;
    }
}

Lista* intercalarListas(Lista* l1, Lista* l2) {
    // Cria um nó sentinela (não faz parte da lista final)
    Lista noInicio;
    noInicio.prox = NULL;
    Lista *noFim = &noInicio;
    //printf("\n\n ### %p: ", l1);
    // Enquanto ambas as listas tiverem elementos
    while (l1 != NULL && l2 != NULL) {
        // Adiciona um nó de l1
        noFim->prox = l1;
        l1 = l1->prox;
        noFim = noFim->prox;

        // Adiciona um nó de l2
        noFim->prox = l2;
        l2 = l2->prox;
        noFim = noFim->prox;
    }

    // Se ainda sobrar alguma lista, anexa o restante
    if (l1 != NULL) noFim->prox = l1;
    if (l2 != NULL) noFim->prox = l2;

   // printf("\n\n >>> %p: ", noInicio.prox);

    // Retorna o início da nova lista (logo após o sentinela)
    return noInicio.prox;
}

Lista* intercalarListasR(Lista* l1, Lista* l2) {
    // Caso base: se uma das listas acabou, retorna a outra
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    // Guarda o próximo de cada lista
    Lista* prox1 = l1->prox;
    Lista* prox2 = l2->prox;

    // Liga l1 -> l2
    l1->prox = l2;

    // Chama recursivamente para intercalar o resto
    l2->prox = intercalarListas(prox1, prox2);

    // Retorna o primeiro nó (l1)
    return l1;
}

int main() {

    Lista *mylista, *mylista2;

    mylista = crialista();
    mylista2 = crialista();

    mylista = insere(mylista, 5);
    mylista = insere(mylista, 50);
    mylista = insere(mylista, 50);
    mylista = insere(mylista, 100);
    mylista = insere(mylista, 100);
    mylista = insere(mylista, 8);
    mylista = insere(mylista, 5);

    printf("\n");
    listagem(mylista);
    //mylista = reverter3(mylista);
    removerDuplicados2(mylista);
    printf("\n");
    listagem(mylista);

    mylista = libera(mylista);


    mylista = insere(mylista, 8);
    mylista = insere(mylista, 10);
    mylista = insere(mylista, 7);

    mylista2 = insere(mylista2, 6);
    mylista2 = insere(mylista2, 16);
    mylista2 = insere(mylista2, 26);


    printf("\n\n------------------------\n");
    listagem(mylista);
    printf("\n");
    listagem(mylista2);

    mylista = intercalarListas(mylista, mylista2);
    printf("\n\n---------Intercelando listas---------------\n");
    listagem(mylista);
    printf("\n");

    printf("\n\n");
    listagem(mylista);

    return 1;
}


