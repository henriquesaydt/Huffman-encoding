#include <string.h>
#include "arvore.h"

int main(int argc, char const *argv[])
{
    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");
    char b;
    int freq[257];
    //zera todo o vetor freq[256]
    memset(freq, 0, sizeof(freq));

    while(fread(&b, 1, 1, arquivo)){
        printf("\nByte lido: %c, codigo: %d\n", b, b);
        freq[b-1]++;

        //Quebrando o Byte em bits
        printf("Bits:");
        int i;
        for(i=0; i<8; i++){
            char bit = (b >> i)&1;
            printf("%d", bit);
        }
        printf("\n");
    }

    /*
    int i;
    for(i=0; i<256; i++)
    {
        printf("\nCódigo: %d, caracter: %c frequência: %d", i+1, i+1, freq[i]);
    }
    printf("\n");
    */

    arvore_l *tabela = freq_ordenar(freq);
    
    int i;
    arvore_l *tmp = tabela;
    for(i=0; i<257; i++){
        printf("\nNó numero %d: data: %c, freq: %d", i, tmp->data, tmp->freq);
        tmp = tmp->prox;
        if(tmp->prox == NULL){
            printf("\nFIM\n");
            break;
        }
    }
    printf("\n");

    /*
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
    */

    return 0;
}
