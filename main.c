#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");
    char b;

    while(fread(&b, 1, 1, arquivo)){
        printf("Byte lido: %c\n", b);
        printf("Bits:\n");
        int i;
        for(i=0; i<8; i++){
            int bit = (b >> i)&1;
            printf("%d\n", bit);
        }
    }
    
    return 0;
}
