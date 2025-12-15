#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int IDvenda;
    char produto_nome[50];
    int quant;
    float valor;
}Vendas;

typedef struct{
    Vendas itens[MAX];
    int topo;
}Pilha;

void inicializar_pilha(Pilha *p){
    p->topo = -1;
}

int cheia(Pilha *p){
    return p->topo == MAX - 1
}

int vazia(Pilha *p){
    return p->topo == -1;
}

void push(Pilha *p, Vendas v){
    if(!cheia(p)){
        p->itens[++p->topo] = v;
    }else{
        printf("Historico Cheio!");
    }
}

Vendas pop(Pilha *p){
    Vendas v = {0, "", 0, 0.0};
    if (!vazia(p)){
        p->itens[p->topo--];
    }else{
        printf("Historico Vazio!");
        return v;
    }
}

void mostrar_historico(Pilha *p){
    if(!vazia(p)){
        printf("---Historico de Vendas---\nRECENTE to ANTIGO\n");
        for (int i=p->topo; i>=0; i--){
            printf("ID: %d | Produto: %s | Quantidade: %d | Valor: %.2f\n",
            p->itens[i].IDvenda, p->itens[i].produto_nome, p->itens[i].quant, p->itens[i].valor);
        }
    }else{
        printf("Nenhuma venda registrada!");
    }
}
//FAZER UMA BUSCA DE UMA DETERMINADA VENDA POR BUSCA BINARIA
void bubbleSort(Vendas v[], int n){
    int temp;
    for (int i=0; i<n - 1; i++){
        for (int j=0; j<n - i - 1; j++){
            if (v[j].IDvenda > v[j+1].IDvenda){
                temp = v[j].IDvenda;
                v[j].IDvenda = v[j+1].IDvenda;
                v[j+1].IDvenda = temp;
            }
        }
    }
}

int busca_binaria_venda(Vendas v[], int venda_alvo, int tamanho){
    int esq = 0, dir = tam, meio;

    while (esq <= dir){
        meio = esq + (dir - esq)/2;
        if (venda_alvo == v[meio]){
            return 1;
        }else if (venda_alvo > v[meio]){
            esq = meio + 1;
        }else{
            dir = meio - 1;
        }
        return -1;
    }
}

