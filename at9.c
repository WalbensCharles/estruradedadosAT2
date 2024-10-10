#include <stdio.h>
#include <stdlib.h>

struct Escolar {
    int matricula;
    float media;
    struct Escolar* next;
    struct Escolar* prev;
};
typedef struct Escolar escolare;
//  adicionar 
void adicionar(escolare** nota, int matricula, float media) {
    escolare* novo = (escolare*)malloc(sizeof(escolare));
    novo->matricula = matricula;
    novo->media = media;
    novo->next = NULL;
    novo->prev = NULL;
    
    if (*nota == NULL) {
        *nota = novo;
    } else {
        escolare* aux = *nota;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
        novo->prev = aux;
    }
}

//  imprimir media e media geral
void imprimirMedia(escolare* nota) {
    escolare* aux = nota;
    int totalAlunos = 0;
    float somaMedia = 0;
    
    while (aux != NULL) {
        printf("Aluno: %d Media: %.1f\n", aux->matricula, aux->media);
        somaMedia += aux->media;
        totalAlunos++;
        aux = aux->next;
    }
    
    if (totalAlunos > 0) {
        printf("Media geral da turma: %.1f\n", somaMedia / totalAlunos);
    }
}

int main() {
    escolare* lista = NULL;
    int matricula;
    float notas[5], media;
    printf("\n\tLista DUPLA\n");
    
    while (1) {
        printf("Matricula ");
        scanf("%d", &matricula);
        if (matricula == 0) break;
        
        media = 0;
        for (int i = 0; i < 5; i++) {
            printf("Nota %d: ", i + 1);
            scanf("%f", &notas[i]);
            media += notas[i];
        }
        media /= 5;
        adicionar(&lista, matricula, media);
    }
    
    imprimirMedia(lista);
    
    return 0;
}
