#include <stdio.h>
#include <stdlib.h>

struct Pagamento {
    float salario;
    int filhos;
    struct Pagamento* next;
    struct Pagamento* prev;
};
typedef struct  Pagamento pagamento;
// Função para adicionar dados à lista
void adicionar(pagamento** sal, float salarios, int filho) {
    pagamento* novo = (pagamento*)malloc(sizeof(pagamento));
    novo->salario = salarios;
    novo->filhos = filho;
    novo->next = NULL;
    novo->prev = NULL;
    
    if (*sal == NULL) {
        *sal = novo;
    } else {
        pagamento* aux = *sal;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
        novo->prev = aux;
    }
}

// Função para calcular e imprimir a média salarial e de filhos
void calcularMedia(pagamento* sal) {
    pagamento* aux = sal;
    float somaSalarios = 0;
    int somaFilhos = 0, count = 0;
    
    while (aux != NULL) {
        somaSalarios += aux->salario;
        somaFilhos += aux->filhos;
        count++;
        aux = aux->next;
    }
    
    if (count > 0) {
        printf("Media salarial: %.1f\n", somaSalarios / count);
        printf("Media de filhos: %.1f\n", (float)somaFilhos / count);
    } else {
        printf("Nenhum dado foi inserido.\n");
    }
}

int main() {
    pagamento* lista = NULL;
    float salario;
    int filhos;
    printf("\n\tLista DUPLA\n");
    while (1) {
        printf("salario : ");
        scanf("%f", &salario);
        if (salario < 0) break;
        printf(" filhos: ");
        scanf("%d", &filhos);
        adicionar(&lista, salario, filhos);
    }
    
    calcularMedia(lista);
    
    return 0;
}
