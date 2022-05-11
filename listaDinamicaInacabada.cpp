#include <stdio.h>
#include <stdlib.h>

// TERMINAR A FUNÇÃO: invertePilhaUmPraPilhaDois();

int i, input, n, ex = 1;

typedef struct {
	int mat;
	
}tipoDado;


typedef struct no *apontador;


typedef struct no {
	tipoDado aluno;
	apontador prox;
}tipoNo;


typedef struct {
	apontador topo, base;
	int tam;
}tipoPilha;

tipoPilha p, p2;
tipoDado al, al2;

void iniciarPilha(tipoPilha *p) {
    p->base=(apontador) malloc(sizeof(tipoNo)); //malloc serve para alocar o tipo de dado na memÃ³ria
    p->topo=p->base;
    p->topo->prox=NULL;
    p->tam=0;
}


void iniciarSecondPilha(tipoPilha *p2) {
    p->base=(apontador) malloc(sizeof(tipoNo)); //malloc serve para alocar o tipo de dado na memÃ³ria
    p->topo=p2->base;
    p->topo->prox=NULL;
    p->tam=0;
}


int pilhaVazia(tipoPilha *p) {
    return (p->topo==p->base);
}

int secondPilhaVazia(tipoPilha *p2) {
    return (p2->topo==p2->base);
}


void empilhar(tipoPilha *p, tipoDado d) {
	apontador aux;

    aux=(apontador) malloc(sizeof(tipoNo)); //malloc serve para alocar o tipo de dado na memÃ³ria
    p->topo->aluno=d;
    aux->prox=p->topo;
    p->topo=aux;
    p->tam++;    
}


void secondEmpilhar(tipoPilha *p2, tipoDado d2) {
	apontador aux;

    aux=(apontador) malloc(sizeof(tipoNo)); //malloc serve para alocar o tipo de dado na memÃ³ria
    p2->topo->aluno=d2;
    aux->prox=p2->topo;
    p2->topo=aux;
    p2->tam++;    
}


void imprimir(tipoPilha *p) {
    apontador aux;
    aux=p->topo->prox;
    printf("\n\n");
    if (aux == NULL) {
    	printf("error: aux == null");
	}
    while(aux!=NULL) {
        printf("%d", aux->aluno.mat);
        aux=aux->prox;
    }
}


void secondImprimir(tipoPilha *p2) {
    apontador aux;
    aux=p2->topo->prox;
    printf("\n\n");
    if (aux == NULL) {
    	printf("error: aux == null");
	}
    while(aux!=NULL) {
        printf("%d", aux->aluno.mat);
        aux=aux->prox;
    }
}


void desempilhar(tipoPilha *p, tipoDado *d) {
	if (pilhaVazia(p) == 1) {
		printf("Pilha vazia!!!");
	} else {
		apontador aux;
		aux = p->topo;
		p->topo=aux->prox;
		free(aux);
		p->tam--;
	}
}


void secondDesempilhar(tipoPilha *p2, tipoDado *d) {
	if (pilhaVazia(p2) == 1) {
		printf("Pilha vazia!!!");
	} else {
		apontador aux;
		aux = p2->topo;
		p2->topo=aux->prox;
		free(aux);
		p->tam--;
	}
}

void invertePilhaUmPraPilhaDois() {
	
	apontador aux;
    aux=p->topo->prox;
	
	

	while (aux!=NULL) {
		int a[]
    	aux=aux->prox;
	}
}


void pedirNumero() {
	printf("Digite a quantidade de números para a pilha:\n");
    scanf("%i",&input);
    
    while (i<input) {
    	bool sair = false;
    	
		while (not sair) {
			int n;
		    printf("Digite o número para adicionar a pilha:\n");
		    scanf("%i",&n);
		    al.mat=n;
    		empilhar(&p, al);
		    i++;
		    if (i == n) {
				sair = true;
			}
		}
	}
}

int main() {
    iniciarPilha(&p);
    iniciarSecondPilha(&p2);
    pedirNumero();
    //printf("pedirNumero = OK");
    //al.mat=0;
    //empilhar(&p, al);
    //al.mat=1;
    //empilhar(&p, al);
    //al.mat=2;
    //empilhar(&p, al);
    //al.mat=3;
    //empilhar(&p, al);
    //al.mat=4;
    //empilhar(&p, al);
    
    imprimir(&p2);
    //printf("\nimprimir = OK");
    desempilhar(&p,&al);
    //printf("\ndesempilhar = OK");
    imprimir(&p);
    //printf("\nimprimir = OK");
}
