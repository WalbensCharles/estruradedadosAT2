#include <stdio.h>
#include <stdlib.h>

struct Percentual {
    int valor;
    struct Percentual* next;
    struct Percentual* prev;
};
typedef struct  Percentual percen;
//  adicionar 
void adicionar(percen** per, int num) {
    percen* novo = (percen*)malloc(sizeof(percen));
    novo->valor = num;
    novo->next = NULL;
    novo->prev = NULL;
    
    if (*per == NULL) {
        *per = novo;
    } else {
        percen* aux = *per;
        while (aux->next != NULL) {
            aux= aux->next;
        }
        aux->next = novo;
        novo->prev = aux;
    }
}

// calcular a porcentagem  entre 10 e 20
void calcular(percen* per) {
    percen* aux = per;
    int total = 0, count = 0;
    
    while (aux != NULL) {
        total++;
        if (aux->valor >= 10 && aux->valor <= 20) {
            count++;
        }
        aux = aux->next;
    }
    
    if (total > 0) {
        printf("%% entre 10 e 20: %.2f%%\n", (float)count / total * 100);
    } else {
        printf("Nenhum numero foi inserido.\n");
    }
}

int main() {
    percen* lista = NULL;
    int numero;
    printf("\n\tLista DUPLA\n");
    while (1) {
        printf(" numero : ");
        scanf("%d", &numero);
        if (numero <= 0) break;
        adicionar(&lista, numero);
    }
    
    calcular(lista);
    
    return 0;
}
