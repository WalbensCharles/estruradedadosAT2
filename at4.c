#include <stdio.h>
#include <stdlib.h>


struct Calculadora {
    char operacao;
    int op1, op2, resultado;
    struct Calculadora* next;
};
typedef struct Calculadora calculador;
//  adicionar 
void adicionar(calculador** cal, char op, int a, int b, int res) {
    calculador* novo = (calculador*)malloc(sizeof(calculador));
    novo->operacao = op;
    novo->op1 = a;
    novo->op2 = b;
    novo->resultado = res;
    novo->next = NULL;
    
    if (*cal == NULL) {
        *cal = novo;
    } else {
        calculador* aux = *cal;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
    }
}

// para imprimir 
void imprimirHistorico(calculador* cal) {
    calculador* aux = cal;
    
    printf("Historico de operacoes:\n");
    while (aux != NULL) {
        printf("%d %c %d = %d\n", aux->op1, aux->operacao, aux->op2, aux->resultado);
        aux = aux->next;
    }
}

int main() {
    calculador* historico = NULL;
    char operacao;
    int a, b, resultado;
    printf("\n\tLista simple\n");
    while (1) {
        printf("Digite a operacao (+, -, *, /) ou @ para sair: ");
        scanf(" %c", &operacao);
        
        if (operacao == '@') break;
        
        printf("Digite o primeiro numero: ");
        scanf("%d", &a);
        printf("Digite o segundo numero: ");
        scanf("%d", &b);
        
        switch (operacao) {
            case '+':
                resultado = a + b;
                break;
            case '-':
                resultado = a - b;
                break;
            case '*':
                resultado = a * b;
                break;
            case '/':
                if (b != 0) {
                    resultado = a / b;
                } else {
                    printf("Divisao por zero nao e permitida!\n");
                    continue;
                }
                break;
            default:
                printf("Operacao invalida!\n");
                continue;
        }
        
        printf("Resultado: %d\n", resultado);
        adicionar(&historico, operacao, a, b, resultado);
    }
    
    imprimirHistorico(historico);
    
    return 0;
}
