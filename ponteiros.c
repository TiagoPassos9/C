#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vet [5]  = {6,4,2,11,20};
int i = 5, a = 1, *ptr, *ptr1, menor;
bool sair = false;

void get() {
	printf("Informe %i números: \n", i);
		for (int x=0; x<i; x++){
			scanf("%d", ptr);
			fflush(stdin);
			ptr++;
		}

}

void ordenar() {
	ptr=vet;
	ptr1=ptr;
	
	for (int x=0; x<i; x++) {
		for (int y=0; y<i; y++) {
			if (*ptr1<*ptr){
				menor=*ptr1;
				*ptr1=*ptr;
				*ptr=menor;
			}
			ptr++;
		}
		ptr1++;
		ptr=vet;
	}
}

void mostrar() {
	for (int x=0; x<5; x++) {
		printf("%d, ",vet[x]);
	}
	printf("\n");
}

void ask() {
	printf("Deseja realizar a operação novamente?\n 1-sim 2-não\n");
	scanf("%i",&a);
	if (a != 1) {
		sair = true;
	}
}
int main() {
	setlocale(LC_ALL, "Portuguese");

	while (not sair){
		ptr=vet;
		get();
		ordenar();
		mostrar();
		ask();
	}
}
