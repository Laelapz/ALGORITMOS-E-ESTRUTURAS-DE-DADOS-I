#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[10];
    int idade;
    int altura;
    struct pessoa* prox;
};

typedef struct pessoa Pessoa;


Pessoa* inicializa(){
    return NULL;
}

Pessoa* inserir_dados(Pessoa *p){
    int num;
    char n[10];


    printf("\nInserindo dados, BIP BOP BIP BOP\n\n");
    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));
    
    printf("insira o nome\n");
    scanf("%s", &n);
    for (size_t i = 0; i < 10; i++){
        novo->nome[i] = n[i];
    }
    

    printf("insira a idade\n");
    scanf("%d", &num);
    novo->idade = num;

    printf("insira a altura\n");
    scanf("%d", &num);
    novo->altura = num;

    novo->prox = p;

    return novo;

}

void imprimir_dados(Pessoa* p){
    Pessoa* a;
    for (a = p; a != NULL; a = a->prox){
        printf("Nome: %s\n", a->nome);
        printf("Idade: %d\n", a->idade);
        printf("Altura: %d\n\n", a->altura);
    }
    
}

void vazia(Pessoa* p){
    if(p==NULL){
        printf("Lista vazia\n");
    }else{
        imprimir_dados(p);
    }
}

void menu(){
    int op;
    Pessoa *p;
    
    p = inicializa();

    printf("\nEscolha uma opcao:\n\t1 - Inserir dados\n\t2 - Sair\n");

   while(scanf("%d", &op) != 2){
        if(op == 1){
            p = inserir_dados(p);
        }else{
            printf("Saindo\n");
            vazia(p);
            free(p);
            break;
        }
        printf("Escolha uma opcao:\n\t1 - Inserir dados\n\t2 - Sair\n");
    }
}

int main(){
    menu();
}