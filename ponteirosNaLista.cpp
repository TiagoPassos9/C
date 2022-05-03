#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Criando o vetor:
int vet [5]  = {6,4,2,11,20};
//Adicionando mais variaveis e os ponteiros:
int i = 5, b, a = 1, *ptr, *ptr1, menor, maior;
//Booleano para o while:
bool sair = false;

//Função para receber os valores para o vet:
void get() {
	ptr=vet;
	printf("Informe %i números: \n", i);
		for (int x=0; x<i; x++){
			scanf("%d", ptr);
			fflush(stdin);
			ptr++;
		}
}

//Função para ordenar o vetor em ordem crescente:
void ordena() {
	//ordenando os ponteiros no vetor vet:
	ptr=vet;
	ptr1=ptr;
	//Correndo o vetor(vet) para achar o número menor e colocar ele no inicio do vetor:
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
//Função para ordenar o vetor em ordem decrescente:
void ordenaD() {
	//Ordenando os ponteiros no vetor vet:
	ptr=vet;
	ptr1=ptr;
	//Correndo o vetor(vet) para achar o número maior e colocar ele no inicio do vetor:
	for (int x=0; x<i; x++) {
		for (int y=0; y<i; y++) {
			if (*ptr1>*ptr){
				maior=*ptr1;
				*ptr1=*ptr;
				*ptr=maior;
			}
			ptr++;
		}
		ptr1++;
		ptr=vet;
	}
}
void inverte() {
	int aux [i];
	ptr=aux;
	for (int z=(i-1); z>=0; z--) {
		int w = 0;
		*ptr = x[z];
		ptr++;
	}
	ptr=x;
	for (int z = 0; z<i; z++) {
		*ptr = aux[z];
		ptr++;
	}
}

//Função para mostrar os números do vetor:
void mostrar() {
	for (int x=0; x<5; x++) {
		printf("%d, ",vet[x]);
	}
	printf("\n");
}

//Funções para perguntas:
void ask() {
	printf("Deseja realizar a operação novamente?\n 1-sim 2-não\n");
	scanf("%i",&a);
	if (a != 1) {
		sair = true;
	}
}

void ask1() {
	printf("Deseja ordenar o vetor na ordem:\n1-crescente ou 2-decrescente\n");
	scanf("%i",&b);
	if (b == 1) {
		ordena();
	}else if (b == 2){
		ordenaD();
	}else{
		printf("Número inválido!");
		ask1();
	}
}

//Inicio do programa:
int main() {
	//O setlocale é utilizado junto com o #include <locale.h> para adicionar as acentuações para uma lingua
	setlocale(LC_ALL, "Portuguese");
	while (not sair){
		get();
		ask1();
		mostrar();
		ask();
	}
}
