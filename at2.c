#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó para a lista simples
struct Multiplicacao {
    int valor;
    struct Multiplicacao* next;
};
typedef struct Multiplicacao mul;
// Função para adicionar soma parcial à lista
void adicionar(mul** adicao, int num) {
    mul* novo = (mul*)malloc(sizeof(mul));
    novo->valor = num;
    novo->next = NULL;
    
    if (*adicao == NULL) {
        *adicao = novo;
    } else {
        mul* aux = *adicao;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
    }
}

// Função para imprimir as somas parciais
void imprimir(mul* adicao) {
    mul* aux = adicao;
    int count = 1;
    
    while (aux != NULL) {
        printf("%d -> soma: %d\n", count, aux->valor);
        aux = aux->next;
        count++;
    }
}

int main() {
    mul* lista = NULL;
    int a, b, soma = 0;
    printf("\n\tlista simple\n");
    
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    
    for (int i = 0; i < b; i++) {
        soma += a;
        adicionar(&lista, soma);
    }
    
    imprimir(lista);
    printf("O resultado de %d * %d = %d\n", a, b, soma);
    
    return 0;
}
