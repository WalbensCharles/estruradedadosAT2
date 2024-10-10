#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int valor;
    struct Lista *next;
 };
 typedef struct Lista lista;

 //adicinar elemento na lista
void adicionar(lista**l,int num){
    lista *novo=(lista*)malloc(sizeof(lista));
    novo->valor=num;
    novo->next=NULL;
//verificar se esta vazia
    if(*l==NULL){
        *l=novo;
    }else{
        lista *aux;
        aux=*l;
        while(aux->next !=NULL){
            aux=aux->next;
        }
        aux->next=novo;
    }
}

//imprimir a lista de elemento
void imprimir(lista *l){
    lista *aux=l;
    int count=0;
    int total=0;

    //contar a quantidade de numero
    while(aux!=NULL){
        total++;
        aux=aux->next;
    }
    aux=l;// resetar para o inicio da lista
    int metade =total/2; //encontra a metade
    
    printf("\n\tLista simple\n");
    while(aux!=NULL){
        printf("%d\n",aux->valor);
        if(count==metade-1){
            printf("Metade\n");
        }
        aux=aux->next;
        count++;
    }
    printf("\nquantidades de numeros %d\n",count);
}


int main(){
    lista *lista=NULL;
    int num;
    printf("digite um numero:");
    scanf("%d",&num);
    for(int i=1; i<=num; i++){
        adicionar(&lista,i);
    }
    imprimir(lista);
    return 0;
}
