#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena_string(char * str1, char *str2){
     size_t str1len = strlen(str1);
     size_t str2len = strlen(str2);
     
     size_t tamanho_memoria = str1len + str2len + 1;
     char * res = malloc(tamanho_memoria*sizeof(char));
     if(res){
          strcpy(res, str1);
          strcpy(res+str1len, str2);
     }
     return res;
}

char *inserir_nome(int *total, char *nomes){
     char *nome;
     nome = malloc(100*sizeof(char));
     scanf("%s", nome);

     nome = concatena_string(nome, "|");
     nomes = concatena_string(nomes, nome);

     printf("%s\n", nomes);
     *total += 1;
     return nomes;
}

void listar(int *total, char *nomes){
     int cnt = 0;
     int i = 0;

     printf("\n %s \n", "Lista de Nomes: ");

     while(cnt < *total){
          if( *(nomes+i) == '|'){
               printf("\n");
               cnt++;
          }
          else{
               printf("%c", *(nomes+i));
          }
          i++;
     }
}

char *apagar_nome(int *total, char *nomes){
     char *nome;
     nome = malloc(100*sizeof(char));
     scanf("%s", nome);
     nome = concatena_string(nome, "|");

     int remove = 0;
     size_t len = strlen(nome);

     if(len > 0){
           char *p = nomes;
           while( (p = strstr(p, nome)) != NULL ){
                memmove(p, p+len, strlen(p+len) + 1);
                remove = 1;
           }
     }

     if(remove == 1) *total -= 1;
     return nomes;
}

int main(){
     int total, op;
     char *nomes;

     total = 0;
     printf("\nDigite a opção que deseja:\n\t1 - Incluir Nome\n\t2 - Remover Nome\n\t3 - Listar Nomes\n\t4 - Sair\n");

     while(scanf("%d",&op) != 4){
          if(op == 1) nomes = inserir_nome(&total, nomes);
          else if(op == 2) nomes = apagar_nome(&total, nomes);
          else if(op == 3) listar(&total, nomes);
          else break;
          printf("\nDigite a opção que deseja:\n\t1 - Incluir Nome\n\t2 - Remover Nome\n\t3 - Listar Nomes\n\t4 - Sair\n");
     }

     free(nomes);
     return 0;
}
