#ifndef _ARVORE_H
#define _ARVORE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_l{
    struct arvore_l *right;
    struct arvore_l *left;
    struct arvore_l *prox;
    int data;
    int freq;
}arvore_l;

arvore_l* arvore_l_criar();

arvore_l* freq_ordenar(int freq[256]);

void lista_inserir(arvore_l *a, int freq, int data);

arvore_l* lista_remover(arvore_l *a);    

int lista_tamanho(arvore_l *a);

#endif