#include "RBTree.h"

int main()
{
    int nv;
    RBTree *Tree;
    init(&Tree);
    char rot;

    system("color 70");

    insere(&Tree, Tree, 5, &rot);
    insere(&Tree, Tree, 7, &rot);
    insere(&Tree, Tree, 3, &rot);
    insere(&Tree, Tree, 1, &rot);
    insere(&Tree, Tree, 10, &rot);
    insere(&Tree, Tree, 2, &rot);
    insere(&Tree, Tree, 14, &rot);
    insere(&Tree, Tree, 8, &rot);
    insere(&Tree, Tree, 6, &rot);

    exibe(Tree, 35, 2, 17);
    getchar(); printf("\n\n\n");
    insere(&Tree, Tree, 13, &rot);
    insere(&Tree, Tree, 11, &rot);
    insere(&Tree, Tree, 12, &rot);
    exibe(Tree, 35, 10, 17);
    //nivel(Tree, &nv);
    //printf("\n\nNivel:\t%d", nv);
    printf("\n\n\n");
    return 0;
}
