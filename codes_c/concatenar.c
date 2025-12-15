#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concatenar(const char *str1, const char *str2){
    int tam_total = strlen(str1) + strlen(str2) + 1;

    //alocar memoria para a nova string
    char *resultado = (char *)malloc(tam_total * sizeof(char));
    if (resultado == NULL){
        return NULL;
    }
    //copia as str para resultado
    strcpy(resultado, str1);
    strcat(resultado, str2);

    return resultado;
}

int main(){

    char *s1 = "Bom";
    char *s2 = "Dia";

    char *resultado = concatenar(s1, s2);

    if (resultado != NULL){
        printf("Resultado: %s\n", resultado);
        free(resultado); //liberar a memoria alocada
    }
    return 0;
}

