#include "RBTree.h"

int main()
{
    int nv, y, elem;
    RBTree *Tree;
    init(&Tree);
    char rot, op = 0;

    system("color 70");

    while(op != 27)
    {
        clrscr();
        exibe(Tree, 35, 2, 17);
        gotoxy(2, 22); printf("Elemento a ser inserido:\t");
        fflush(stdin);
        scanf("%d", &elem);
        insere(&Tree, Tree, elem);
        clrscr();
        exibe(Tree, 35, 2, 17);
        gotoxy(2, 22); printf("ESC para sair ou outro tecla para continuar...");
        op = getch();
        /*gotoxy(10, 2); printf("Menu");
        gotoxy(5, 5); printf("[I] - Inserir");
        gotoxy(5, 7); printf("[E] - Exibir");
        gotoxy(5, 9); printf("[ESC] - Sair");
        op = toupper(getch());

        switch(op)
        {
            case 'I':
                clrscr();
                y = 5;
                gotoxy(10, 2); printf("Inserir na Arvore");
                gotoxy(5, y); printf("Elemento a ser inserido <-1 para sair>:\t");
                scanf("%d", &elem);
                while(elem != -1)
                {
                    insere(&Tree, Tree, elem);
                    y += 2;
                    gotoxy(5, y); printf("Elemento a ser inserido <-1 para sair>:\t");
                    scanf("%d", &elem);
                }
                break;
            case 'E':
                clrscr();
                exibe(Tree, 35, 2, 17);
                getch();
                break;
        }*/
    }

    return 0;
}
