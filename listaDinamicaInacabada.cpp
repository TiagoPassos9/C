#include <stdio.h>
#include <stdlib.h>

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

tipoPilha p;
tipoDado al;

void iniciarPilha(tipoPilha *p) {
    p->base=(apontador) malloc(sizeof(tipoNo)); //malloc serve para alocar o tipo de dado na memÃ³ria
    p->topo=p->base;
    p->topo->prox=NULL;
    p->tam=0;
}


int pilhaVazia(tipoPilha *p) {
    return (p->topo==p->base);
}


void empilhar(tipoPilha *p, tipoDado d) {
	apontador aux;

    aux=(apontador) malloc(sizeof(tipoNo)); //malloc serve para alocar o tipo de dado na memÃ³ria
    p->topo->aluno=d;
    aux->prox=p->topo;
    p->topo=aux;
    p->tam++;    
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


void pedirNumero(tipoPilha *p) {
	printf("Digite a quantidade de números para adicionar a pilha:\n");
    scanf("%i",&input);
    
    for (i == 0; i<input; i++) {
    	bool sair = false;
    	int n;
		while (not sair) {
		    printf("Digite o número para adicionar a pilha:\n");
		    scanf("%i",&n);
		    al.mat=n;
		    if (i == n) {
				sair = true;
			}
		}
	}
	printf("Deseja adicionar outro número?\n 1-Sim 2-Não");
	scanf("%i",&n);
	if (ex == 0) {
		scanf("&i",&ex);
	}
}

int main() {
    iniciarPilha(&p);
    pedirNumero(&p);
    al.mat=0;
    empilhar(&p, al);
    al.mat=1;
    empilhar(&p, al);
    al.mat=2;
    empilhar(&p, al);
    al.mat=3;
    empilhar(&p, al);
    al.mat=4;
    empilhar(&p, al);
    imprimir(&p);
    desempilhar(&p,&al);
    imprimir(&p);
}
