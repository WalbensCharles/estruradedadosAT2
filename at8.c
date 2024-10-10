#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Campeonato {
    char time[2];
    int pontos;
    struct Campeonato* next;
    struct Campeonato* prev;
};
typedef struct Campeonato liga;

// adicionar 
void adicionar(liga** partido, char time[], int pontos) {
    liga* aux = *partido;
    
    // Verifica se o time ja existe na lista
    while (aux != NULL) {
        if (strcmp(aux->time, time) == 0) {
            aux->pontos += pontos; // Atualiza os pontos do time
            return;
        }
        aux = aux->next;
    }

    // Se o time não estiver na lista, cria um novo nó
    liga* novo = (liga*)malloc(sizeof(liga));
    strcpy(novo->time, time);
    novo->pontos = pontos;
    novo->next = NULL;
    novo->prev = NULL;
    
    if (*partido == NULL) {
        *partido = novo;
    } else {
        aux = *partido;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
        novo->prev = aux;
    }
}

// imprimir os pontos dos times e definir o campeão
void imprimirCampeao(liga* partido) {
    liga* aux = partido;
    int campeaoPontos = 0;
    char campeao[2] = "";
    int empate = 0;

    printf("Pontuacao dos times:\n");
    while (aux != NULL) {
        printf("Time %s: %d pontos\n", aux->time, aux->pontos);
        if (aux->pontos > campeaoPontos) {
            strcpy(campeao, aux->time);
            campeaoPontos = aux->pontos;
            empate = 0;
        } else if (aux->pontos == campeaoPontos) {
            empate = 1;
        }
        aux = aux->next;
    }

    if (empate) {
        printf("Nao houve campeao, houve empate.\n");
    } else {
        printf("Campeao: %s\n", campeao);
    }
}

int main() {
    liga* lista = NULL;
    char time1[2], time2[2];
    int gols1, gols2;

    printf("\n\tLista DUPLA\n");
    while (1) {
        printf("time ");
        scanf("%s", time1);
        if (strcmp(time1, "A") != 0 && strcmp(time1, "B") != 0 && strcmp(time1, "C") != 0 && strcmp(time1, "D") != 0) break;

        printf("gols : ");
        scanf("%d", &gols1);

        printf("time: ");
        scanf("%s", time2);
        printf(" gols : ");
        scanf("%d", &gols2);

        // Verifica o resultado do jogo e atualiza os pontos
        if (gols1 > gols2) {
            adicionar(&lista, time1, 3);  // Vitória para o time 1
            adicionar(&lista, time2, 0);  // Derrota para o time 2
        } else if (gols1 < gols2) {
            adicionar(&lista, time2, 3);  // Vitória para o time 2
            adicionar(&lista, time1, 0);  // Derrota para o time 1
        } else {
            adicionar(&lista, time1, 1);  // Empate para ambos
            adicionar(&lista, time2, 1);
        }
    }

    imprimirCampeao(lista);

    return 0;
}
