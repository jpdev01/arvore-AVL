#include <stdio.h>
#include <stdlib.h>
#include "No.c"
#include "arvoreCore.c"

No *buildNo() {
    No *no = malloc(sizeof(No) + 1);
    no->chave = 4;

    No *noesquerd = malloc(sizeof(No) + 1);
    noesquerd->chave = 2;

    No *noDireita = malloc(sizeof(No) + 1);
    noDireita->chave = 30;

    no->esquerda = noesquerd;
    no->direita = noDireita;

    No *maisUmNoEsquerda = malloc(sizeof(No) + 1);
    maisUmNoEsquerda->chave = 5;
    noesquerd->esquerda = maisUmNoEsquerda;

    return no;
}

void main() {
    No *no = buildNo();
    printf("%i", altura(no));
}
