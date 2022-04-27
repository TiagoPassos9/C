#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TaMax 10

typedef int apontador;

typedef struct {
	int mat;
}tipoDado;

typedef struct {
	tipoDado alunos[TaMax];
	int tamanho;
	apontador first, last;
}tipoLista;

void inicializaLista(tipoLista *L){
	L->first=0;
	L->last=L->first;
	L->tamanho=0;
}

int listaVazia(tipoLista L){
	if (L.first==L.last){
		return 1;
	}else{
		return 0;
	}
}

int listaCheia(tipoLista *L){
	if (L->last>TaMax-1){
		return 1;
	}else{
		return 0;
	}
}

int inserirListaU(tipoLista *L, tipoDado D){
	if (listaCheia(L)==1){
		return 0;
	}else{
		L->alunos[L->last]=D;
		L->last++;
		L->tamanho++;
		return 1;
	}
}
int recusivo(int ini, int fim ){
	int mid = (ini+fim)/2;
    	return mid;
}

int ordena(tipoLista *L){  
   int i, j,aux;
	for (j=L->first;j<L->last-1;j++){
	   for (i=L->first;i<L->last-1;i++){
	   	  if (L->alunos[i].mat>L->alunos[i+1].mat){
			  aux=L->alunos[i].mat;
			  L->alunos[i].mat=L->alunos[i+1].mat;
			  L->alunos[i+1].mat=aux;
			 }
	    }	
	}
}
	
int BuscaLista (tipoLista *L, int AL, int i, int f){
		int mid, achou=0;
	    mid= (i+f)/2;
		while ((achou==0 ) && (i<=f) ) {
		   if (L->alunos[mid].mat==AL) {
		   	   achou=1;
		   	   return mid;
		    }else{
				if (L->alunos[mid].mat<AL){
				   i=mid+1;
				   mid=recusivo(i,f);
				}else{
				    if (L->alunos[mid].mat>AL)	{
				      f=mid-1;
					  mid=recusivo(i,f);
					} 
			    }
			}    
	  }
	  if (achou==0){ 
	    return -1;
	  }		
	}

void imprimir(tipoLista L){
	int aux; 
	for (aux=L.first;aux<L.last;aux++){
		printf("\nMat : %d\n", L.alunos[aux].mat);
	}
}
int main(){
    tipoLista l;
	tipoDado aluno;
	int x,op = 1, m, i, f, encontrou;	
	
	inicializaLista(&l);
	setlocale(LC_ALL, "Portuguese");
	while (op!=0){
		system("cls");
		printf("\n******** Sistema de Matrícula *************\n");
		printf("\n1-Inserir\n2-Imprimir\n3-Imprimir Ordenado \n");
		printf("4-Buscar\n0-Sair                           \n");
		printf("\nInforme a opção desejada a                 \n");
		printf("                                             \n");
		printf("*********************************************\n");
		scanf("%d",&op);
		switch (op){
		
		case 1:
			system("cls");
			printf("Informe a matrícula: ");
			scanf("%d",&aluno.mat);
			x=inserirListaU(&l,aluno);
			if (x>0){
				printf("Dado inserido com sucesso!!!\n");
			}else 
			    printf("Erro!!! Lista cheia\n");
			system("pause");    
			break;
		case 2:
			system("cls");
			imprimir(l);
			system("pause");
			break;
		case 3:
			system("cls");
	        printf("***** Imprimir Ordenado*******");
	        ordena(&l);
	        imprimir(l);
			system("pause");
			break;
		case 4:
			system("cls");
			ordena(&l);
	        printf("\nInforme O valor a ser buscado\n");
	        scanf("%d", &m);
	        i=l.first;
	        f=l.last-1;
			encontrou=BuscaLista(&l,m,i,f);
			if (encontrou!=-1){
				printf("\nO a posição do valor é : %d\n", encontrou);
			}else{
			    printf("\nValor não encontrado!\n");	
			}
			system("pause");
			break;		
		case 0:
			system("cls");
			printf("Até logo!!!\n");
			break;
		default:
			system("cls");
			printf("Opção Invalida!!!\n");
			break;
		}
	}
return 0;
}
