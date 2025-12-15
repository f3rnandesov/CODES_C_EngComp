#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inverter(char *str){
    char *inicio, *fim;
    inicio = str;
    fim  = str + strlen(str) - 1;
    int temp;
    while (inicio < fim){
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}


int main(){
    char str12[]= "Hello";
    inverter(&str12);
    printf("Invertido: %s", str12);
}
