#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *arquivo;
    if( !(arquivo = fopen("ola_mundo.txt","w")) )
    {
        printf("Erro! Impossivel abrir o arquivo!\n");
        exit(1);
    }
    else
    {
        fprintf(arquivo, "Ola mundo!");
        fclose(arquivo);
    }

}
