#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"

int main(int argc, char const *argv[])
{
    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");
    char b;
    int freq[256];
    //zera todo o vetor freq[256]
    memset(freq, 0, sizeof(freq));

    while(fread(&b, 1, 1, arquivo)){
        printf("\nByte lido: %c\n", b);
        freq[b]++;

        //Quebrando o Byte em bits
        printf("Bits:");
        int i;
        for(i=0; i<8; i++){
            char bit = (b >> i)&1;
            printf("%d", bit);
        }
        printf("\n");
    }

    arvore_l *tabela = freq_ordenar(freq);
    
    arvore_l *no_1;
    arvore_l *no_2;
    arvore_l *no_res = (arvore_l *)malloc(sizeof(arvore_l));
    while(lista_tamanho > 1){
        no_res->freq = no_1->freq + no_2->freq;
        no_res->left = tabela;
        no_res->right = tabela->prox;
        no_res->data = NULL;
        no_res->prox = lista_inserir(tabela, no_res->freq, NULL);
        no_1 == tabela;
        no_2 == tabela->prox;
        lista_remover(tabela);

    }
    

    return 0;
}
