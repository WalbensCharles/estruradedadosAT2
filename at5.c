#include <stdio.h>
#include <stdlib.h>

struct Fatorial {
    int valor;
    struct No* next;
    struct No* prev;
};
typedef struct Fatorial fatorial;
// adicionar
void adicionar(fatorial** fat, int num) {
    fatorial* novo = (fatorial*)malloc(sizeof(fatorial));
    novo->valor = num;
    novo->next = NULL;
    novo->prev = NULL;
    
    if (*fat == NULL) {
        *fat = novo;
    } else {
        fatorial* aux = *fat;
        while (aux->next != NULL) {
            aux= aux->next;
        }
        aux->next = novo;
        novo->prev = aux;
    }
}

//  imprimir os passos do fatorial
void imprimir(fatorial* fat) {
    fatorial* aux = fat;
    int passo = 1;
    
    while (aux != NULL) {
        printf("Passo %d: %d\n", passo, aux->valor);
        aux = aux->next;
        passo++;
    }
}

int main() {
    fatorial* lista = NULL;
    int numero, fato = 1;
    printf("\n\tLista DUPLA\n");
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &numero);
    
    for (int i = 1; i <= numero; i++) {
        fato *= i;
        adicionar(&lista, fato);
    }
    
    printf("O fatorial de %d e: %d\n", numero, fato);
    imprimir(lista);
    
    return 0;
}
