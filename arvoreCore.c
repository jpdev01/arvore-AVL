int altura(No *no) {
    int alturaEsquerda = 0, alturaDireita = 0;
    if (no->esquerda != NULL) {
        alturaEsquerda = altura(no->esquerda) + 1;
    }
    if (no->direita != NULL) {
        alturaDireita = altura(no->direita) + 1;
    }

    if (alturaEsquerda == alturaDireita) return 0;
    return alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita;
}

int fb(No* no) {
    int alturaEsquerda = 0,alturaDireita = 0;

    if (no->esquerda != NULL) {
        alturaEsquerda = altura(no->esquerda) + 1;
    }
    if (no->direita != NULL) {
        alturaDireita = altura(no->direita) + 1;
    }

    return alturaEsquerda - alturaDireita;
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