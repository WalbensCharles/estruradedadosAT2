#include <stdio.h>
#include <stdlib.h>

struct Somar{
    int valor;
    struct Somar *next;

};
typedef struct Somar somar;

//adicionar na lista
void adicionar(somar** som, int num) {
    somar* novo = (somar*)malloc(sizeof(somar));
    novo->valor = num;
    novo->next = NULL;
    
    if (*som == NULL) {
        *som = novo;
    } else {
        somar* aux = *som;
        while (aux->next != NULL) {
            aux= aux->next;
        }
        aux->next = novo;
    }
}

//imprimir
void imprimir(somar *som) {
    somar* aux = som;
    int soma = 0;
    
    printf("Lista simple: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        soma += aux->valor;
        aux = aux->next;
    }
    printf("\nA soma de todos os numeros : %d\n", soma);
}

int main(){
    somar* lista = NULL;
    int numero;
    printf("\n\tLista simple\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    for (int i = 1; i <= numero; i++) {
        adicionar(&lista, i);
    }
    
    imprimir(lista);
    
    return 0;
}