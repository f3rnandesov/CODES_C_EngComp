#include <stdio.h>
#include <stdlib.h>

void miniMAX(int *v[], int n, int *min, int *max){
    *min = *max = v[0];

    for(int i=1; i<n ; i++){
        if (v[i] > *max){
            *max = v[i];
        }else if(v[i] < *min){
            *min = v[i];
        }
    }
}

int main(){
    int n = 5;
    int *vet[] = {5, 1, 8, 12, 2};
    int a, b;
    miniMAX(vet, n, &a, &b);
    printf("minimo: %d / maximo: %d", a, b);



    return 0;
}
