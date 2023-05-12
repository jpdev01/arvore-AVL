#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    struct No *pai;
    struct No *esquerda;
    struct No *direita;
    int valor;
} No;


int altura(No *no) {
    int esquerda = 0, direita = 0;
    if (no->esquerda != NULL) {
        printf("Verificando esquerda\n");
        esquerda = altura(no->esquerda) + 1;
    }
    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda > direita ? esquerda : direita;
}

int main() {
    No *no = malloc(sizeof(No) * 1);
    no->valor = 20;

    No* noesquerd = malloc(sizeof(No) +1);
    noesquerd->valor=10;

    No* noesquerda = malloc(sizeof(No) +1);
    noesquerda->valor=30;

    no->esquerda = noesquerd;
    noesquerd->esquerda=noesquerda;

    printf("%i", altura(no));
    return 0;
}

int fb(No* no) {
    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }
    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda - direita;
}

No* rse(No* no) {
    No* pai = no->pai;
    No* direita = no->direita;

    no->direita = direita->esquerda;
    no->pai = direita;
    direita->esquerda = no;
    direita->pai = pai;

    return direita;
}

No* rsd(No* no) {
    No* pai = no->pai;
    No* esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    return esquerda;
}

No* rde(No* no) {
    no->direita = rsd(no->direita);
    return rse(no);
}

No* rdd(No* no) {
    no->esquerda = rse(no->esquerda);
    return rsd(no);
}