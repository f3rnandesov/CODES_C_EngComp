#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100
#define TAM_PILHA 100

typedef struct{
    int senha;
    time_t chegada;
}Cliente;

typedef struct{
    Cliente clientes[TAM];
    int inicio;
    int fim;
    int numSenha;
}Fila;

typedef struct{
    Cliente historico[TAM_PILHA];
    int topo;
}Pilha;

void inicializar_pilha(Pilha *p){
    p->topo = -1;
}

int pilha_vazia(Pilha *p){
    return p->topo == -1;
}

int pilha_cheia(Pilha *p){
    return p->topo == TAM_PILHA - 1;
}

void push(Pilha *p, Cliente c){
    if (!pilha_cheia(c)){
        p->historico[++p->topo] = c;
    }else{
        printf("Historico Cheio!");
    }
}

Cliente pop(Pilha *p){
    return p->historico[p->topo--];
}

Cliente retornar_topo_pilha(Pilha *p){
    return p->historico[p->topo];
}

void inicializar_fila(Fila *l){
    l->inicio = 0;
    l->fim = -1;
    l->numSenha = 100;
}

nt isFull(Fila *f) {
    return f->fim == TAM - 1;
}

int isEmpty(Fila *f) {
    return f->fim == -1;
}

// Adiciona novo cliente com timestamp
void gerarSenha(Fila *f) {
     Cliente novo;
    novo.senha = f->numSenha++;
    novo.chegada = time(NULL); // hora atual
    f->clientes[++f->fim] = novo;
    printf("\nSenha: %d - Chegada: %s", novo.senha, ctime(&novo.chegada));
}

// Atende cliente
Cliente atenderCliente(Fila *f) {
    Cliente atendido = f->clientes[f->inicio];
    for (int i=f->inicio; i < f->fim; i++ ) {
        f->clientes[i] = f->clientes[i+1];
    }
    f->fim--;
    return atendido;
}


void mostrarFila(Fila *f) {
    for (int i = f->inicio; i <= f->fim; i++) {
        printf("  Senha %d - Chegada: %s", f->clientes[i].senha, ctime(&f->clientes[i].chegada));
    }
}

void menu() {
    printf("\n===== SIMULADOR DE ATENDIMENTO =====");
    printf("\n1. Gerar nova senha");
    printf("\n2. Atender proximo cliente");
    printf("\n3. Mostrar fila");
    printf("\n4. Mostrar Historico");
    printf("\n5. Mostrar ultimo atendimento");
    printf("\n6. Sair");
    printf("\nEscolha uma opcao: ");
}


int main() {
    Fila fila;
    Pilha historico;
    inicializar(&fila);
    inicializar_pilha(&historico);
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
       // getchar(); // limpa o buffer do teclado
        Cliente clienteAtendido;
        switch (opcao) {
            case 1:
               if (!isFull(&fila)) {
                   gerarSenha(&fila);
               } else {
                   printf("\nFila cheia!");
               }
               break;
            case 2:
                if (!isEmpty(&fila)) {
                    clienteAtendido = atenderCliente(&fila);
                    time_t agora = time(NULL);
                    double espera = difftime(agora, clienteAtendido.chegada);
                    printf("\nSenha atendida: %d", clienteAtendido.senha);
                    printf("\nTempo de espera: %.2f segundos", espera);


                    //guarda no historico
                    push(&historico, clienteAtendido);
                } else {
                    printf("\nFila Vazia!");
                }
                 break;
            case 3:
                if (!isEmpty(&fila)){
                    mostrarFila(&fila);

                }else{
                    printf("\nFila Vazia!");
                }
                break;
            case 4:
                if (!pilha_vazia(&historico)){
                    printf("\n---Historico de Atendimentos---");
                    for (int i=0; i<historico.topo; i--){
                        printf("Senha: %d - Chegada: %s",
                        historico.historico[i].senha)
                        ctime(&historico.historico[i].chegada);
                    }
                }else{

                }
















