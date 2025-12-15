#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA COM PONTEIRO PARA ELA MESMA
typedef struct{
    int info;
    struct no *prox;
}Lista;

//LISTA DE INTEIROS

typedef struct no{
    int info;
    struct no *prox;
}Lista;
Lista *l;

//OPERAÇÕES BÁSICAS

//---//

//FUNÇÃO CRIARLISTA
//- Cria uma lista vazia, representada pelo ponteiro NULL
Lista *criar_lista(){
    return NULL;
}


//FUNÇÃO INSERIR
// - Aloca memória para armazenar o elemento
// - Encadeia o elemento na lista existente
// Insere no ínicio e retorna lista atualizada
Lista *inserir(Lista *l; int valor){
    Lista *novo_no = (Lista *)malloc(sizeof(Lista));
    novo_no->info = valor;
    novo_no->prox = l;
    return novo_no;
}


//FUNÇÃO IMPRIMIR
// - Imprime os valores dos elementos armazenados
// - Encadeia o elemento na lista existente
// Imprime valores dos elementos

void imprimir(Lista *l){
    Lista *p;
    for(p=l; p!=NULL; p=p->prox){
        printf("[%d | %x]", p->info, p->prox);
    }

}



//FUNÇÃO VAZIA
// - Retorna 1 se vazia ou 0 se não vazia
int lista_vazia(Lista *l){
    return l==NULL;
}

//FUNÇÃO BUSCA
// - recebe a informação referente ao elemento a pesquisar
/* - retorna o ponteiro  do nó da lista que representa o
elemento, ou NULL, caso o elemento não seja encontradona lista */
 Lista *buscar(Lista *l, int valor){
    Lista *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->info == valor){
            return p;
        }
    }
    return NULL;
}


 //FUNÇÃO RETIRAR
 // - Retira elemento da lista
 Lista *retirar(Lista *l; int valor){
    Lista *anterior = NULL; // ponteiro para o elemento anterior
    Lista *p = l; // ponteiro para percorrer a lista

    /*Procura o elemento na lista, guardando  o anterior*/
    while (p!=NULL && p->info!=valor){
        anterior = p;
        p = p->prox;
    }

    /*Verifica se achou o elemento*/
    if (p==NULL){
        return l; //Não achou o elemento, retorna a lista original
    }

    /*Retirar o elemento*/
    if(anterior == NULL){
        l = p->prox; // retira o elemento do inicio
    }else{
        anterior->prox = p->prox;
    }
    free(p);
    return l;
 }

//FUNÇÂO LIBERAR
// - Distrói a lista, liberando todos os elementos alocados
void liberar(Lista *l){
    Lista *p = l;
    while (p!=NULL){
        Lista *t = p->prox;
        free(p);
        p=t;
    }
}
/*Guarda referência p/ proximo elemento libera a memória apontda por
p faz p apontar para o próximo*/

int main (void){
    Lista *l; //Declara uma lista não inicializada
    l = criarLista(); // Cria e inicializa a lista como vazia
    l = insere(l, 23); // Insere na lista o elemento 23
    l = insere(l, 45); // Insere na lista o elemento 45
    imprime(l);
    l = retirar(l, 78);
    imprime(l);
    l = retirar(45);
    imprime(l);
    liberar(l);
    //...deve-se atualizar a variável que representa a lista a cada inserção de um novo elemento
    return 0;
}
