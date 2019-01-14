#include "arvore.h"

arvore_l* arvore_l_criar(){
    arvore_l *a = (arvore_l *)malloc(sizeof(arvore_l));
    a->prox = NULL;
    a->right = NULL;
    a->left = NULL;
    a->freq = 0;
    return a;
}

void lista_inserir(arvore_l *a, int freq, int data){
    arvore_l *tmp = a;
    arvore_l *b = (arvore_l *)malloc(sizeof(arvore_l));
    b->data = data;
    b->freq = freq;
    b->right = NULL;
    b->left = NULL;

    //Se a lista tiver apenas 1 item
    if(tmp->prox == NULL){
        tmp->prox = b;
        b->prox = NULL;
        return;
    }
    /*posiciona o nó em ordem crescente de frequencia.
    Ficando sempre a esquerda em caso de mesma frequencia.
    */
    while(tmp->prox->freq < b->freq){
        tmp = tmp->prox;
        if(tmp->prox == NULL){
            tmp->prox = b;
            b->prox = NULL;
            return;
        }
    }
    b->prox = tmp->prox;
    tmp->prox = b;
    return;
}

arvore_l* freq_ordenar(int freq[256]){
    arvore_l *tabela = arvore_l_criar();
    int i;
    for(i=0; i<256; i++){
        lista_inserir(tabela, freq[i], i+1);
    }
    return tabela;
}

arvore_l* lista_remover(arvore_l *a){
    arvore_l *tmp = a->prox->prox;
    a->prox = NULL;
    a = NULL;
    return tmp;
}

int lista_tamanho(arvore_l *a){
    int i=0;
    while(a->prox != NULL){
        i++;
        a = a->prox;
    }
}