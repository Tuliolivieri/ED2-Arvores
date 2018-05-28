#include "Huffman.h"

int main()
{
    HTree *Tree = NULL;
    String Str[256];
    int TL = 0, TLC = 0;
    char aux[257], Codigos[256];

    getString(Str, &TL, &aux);
    ordena(Str, TL);
    insere(&Tree, Str, TL);

    //clrscr();
    exibe_arvore(Tree, 35, 5, 15);
    getch();

    exibe_letra_frequencia(Str, TL);
    exibe_letra_nivel(Str, 0);

    return 0;
}
