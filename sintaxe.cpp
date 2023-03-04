#include <iostream>
#include <stdio.h> // para utilizar o printf e scanf
#include <stdlib.h> // para usar o system("cls");, mas percebi que o system("cls"); conseguiu rodar sem ele.

#define pi 3.14
#define Max 6
#define sysName cout<<"ESTUDANDO C++!!!"<<endl; // O define nao serve apenas parar guardar variaveis como o define acima, ela serve também para guardar uma linha de comando.

using namespace std;

int a, b, n; // Declarando variáveis. tipo variavel = conteudo. O tipo pode ser: int, char, string, float, double, bool ou ponteiro(que será mostrado mais a baixo).
int vet[Max], *ptr; // Criando um vetor chamado vet, de tamanho Max, você também pode passar os números do vetor por exemplo: vetor[3] = {0,1,2}. E um ponteiro começando com *, o qual você pode apontar para um vetor.

void verVetor(int *ponteiro) { // Uma função. Pode ser criada passando ou não uma variável. Nessa foi passada um ponteiro.
    int j = 0;
    for (int i = 0; i < Max; i++) {
        printf("%i: %i\n", ++j, *ponteiro); // Para mostrar variaveis no printf, você precisa colocar a % correspondente dentro do das aspas duplas, e a variavel fora. os correspondentes são int = %i ou %d, float = %f, char = %c, string = %s.
        ponteiro++; // Passando o ponteiro para a próxima posição do vetor que ele está apontando.
    }
}

int main() {
    string y = "n";
    inicio: // Label para o goto utilizar.
    sysName
    cout<<"Ola, mundo!\naprendendo c++"<<endl; // O cout é igual ao printf, mas, para usar o printf você precisa importar uma biblioteca (stdio.h). ele faz referência a saida de C. E o endl serve para quebrar linha, assim como o \n.
    cout<<"Pi: "<<pi<<endl;
    cout<<"Digite um numero: ";
    cin>>a; // O cin equivale ao scanf, e nem mesmo precisa do &. O cin faz referência a entrada de C.

    b=a; // Atribuindo o valor da a para b.

    if (a && b >= 1) { // Os comandos if e else são as condicionais, que também podem ser substituidas por switch case.
        cout<<"a e b >= 1\n";
    }else if (a || b >= 1) {
        cout<<"a ou b >= 1\n";
    }else {
        cout<<"!a && !b >= 1\n";
    }
    system("pause"); //Pausa o código.
    system("cls"); // Limpa a tela.
    cout<<"O que voce digitou: "<<a<<endl<<"Imprimindo os numeros de 1 a "<<a<<":"<<endl;
    for (int i = 0; i < a; i++) {
        cout<<i+1<<endl;
    }
    system("pause"); // Pausa o código.
    system("cls"); // Limpa a tela
    cout<<"Digite um numero entre 1 e 100: ";
    cin>>n;
    switch (n) { // Aplicando o uso do switch case na variável n.
    case 0:
        cout<<"Numero nulo\n";
        system("pause");
        break;
    case 1-5:
        cout<<"Numero muito baixo";
        system("pause");
        break;
    case 99:
        cout<<"Numero bem alto";
        system("pause");
        break;
    default:
        cout<<"\nBelo numero\n";
        system("pause");
        break;
    }

    system("cls");
    ptr=vet;
    for (int i = 0; i < Max; i++) {
        *ptr = i;
        ptr++;
    }
    cout<<"Imprimindo vetor criado automaticamente\n";
    ptr=vet; // Apontando o ponteiro ptr para o vetor vet.
    verVetor(ptr); //Chama a função verVetor passando como ponteiro o ptr que está apontando para o vetor vet.
    int vet1[Max]; // Cria um outro vetor.
    printf("Digite %i numero(s):\n",Max);
    for (int i = 0; i < Max; i++) {
        scanf("%d", &vet1[i]); // A atribuição também pode ser feito com o ponteiro, como na linha 67. O scanf usa a mesma lógica do printf, exceto pelo & antes da variável a ser atribuída. O & referencia ao endereço, e diz que quem vai receber aquele valor é o endereço da variável.
        fflush;
    }
    system("cls");
    ptr=vet1;
    cout<<"Imprimindo vetor criado:\n";
    verVetor(ptr);
    system("\npause");
    cout<<"\nDeseja continuar? [S/N]";
    cin>>y;
    while (y== "S" || y == "s") { // O while se mantém rodando enquanto a condição seja verdadeira.
        goto inicio; // Volta para o label selecionado.
    }

    return 0;
}
