#include <stdio.h>
#include <stdlib.h>

#define TAM 300000

void quicksort(int *v, int left, int right) {
    int i, j;
	int pivo;
	i = left; j = right;
	pivo = v[(left+right)/2];
	do {
		while ((v[i] < pivo) && (i < right))
			i++;
		while (v[j] > pivo && j > left)
			j--;
		if (i <= j) {
			int x = v[i];
			v[i]  = v[j];
			v[j] = x;
			i++; j--;
		}
	}while(i<=j);

	if (left < j) {
		quicksort(v, left, j);
	}
	if (right > i){
		quicksort(v, i, right);
    }
}

int main() {

    int numeros[TAM];

	for(int i=0; i<TAM; i++) {
         numeros[i] = (rand()%1000); /** gerando valores aleatórios entre zero e 999 */
	}

    quicksort(numeros,0,TAM-1);

    for(int i=0; i < TAM; i++) {
       printf("%d   ",numeros[i]);
    }

    return(0);
}


