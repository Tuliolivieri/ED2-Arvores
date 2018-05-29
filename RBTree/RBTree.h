#ifndef RBTREE_H_INCLUDED
#define RBTREE_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "meuconio.h"

struct rbtree
{
    struct rbtree *Direita;
    struct rbtree *Esquerda;
    struct rbtree *Pai;
    int Info;
    char Cor;
};
typedef struct rbtree RBTree;

//// FUNÇÕES

void init(RBTree**Tree);
RBTree *criaNo(RBTree *Pai, char cor, int info);
int altura(RBTree *Tree);
void colore(RBTree**Tree);
void insere(RBTree**Tree, RBTree *Pai, int info);
void rotacao_esquerda(RBTree**Tree);
void rotacao_direita(RBTree**Tree);
void nivel(RBTree *Raiz, int *nv);
void exibe(RBTree *Tree, int x, int y, int dist);

//// IMPLEMENTAÇÃO DAS FUNÇÕES

void init(RBTree**Tree)
{
    *Tree = NULL;
}

RBTree *criaNo(RBTree *Pai, char cor, int info)
{
    RBTree *Novo = (RBTree*)malloc(sizeof(RBTree));
    Novo->Direita = NULL;
    Novo->Esquerda = NULL;
    Novo->Pai = Pai;
    Novo->Cor = cor;
    Novo->Info = info;

    return Novo;
}

int altura(RBTree *Tree)
{
    int a, b;
    if(Tree == NULL)
        return -1;
    a = altura(Tree->Esquerda);
    b = altura(Tree->Direita);
    if(a > b)
        return a+1;
    return b+1;
}

/*void colore(RBTree**Tree)
{
    RBTree *Pai;
    Pai = (*Tree)->Pai;

    if(Pai == NULL)    //// RAIZ É SEMPRE PRETA
        (*Tree)->Cor = 'b';
    if((*Tree)->Esquerda != NULL)
    {
        if((*Tree)->Esquerda->Esquerda != NULL)
        {
            if((*Tree)->Esquerda->Cor == 'r' && (*Tree)->Esquerda->Esquerda->Cor == 'r')
            {
                if((*Tree)->Direita != NULL && (*Tree)->Direita->Cor == 'r')
                {
                    (*Tree)->Direita->Cor = 'b';
                    (*Tree)->Esquerda->Cor = 'b';
                    if(Pai != NULL)
                       (*Tree)->Cor = 'r';
                }
            }
        }
        if((*Tree)->Esquerda->Direita != NULL)
        {
            if((*Tree)->Esquerda->Cor == 'r' && (*Tree)->Esquerda->Direita->Cor == 'r')
            {
                if((*Tree)->Direita != NULL && (*Tree)->Direita->Cor == 'r')
                {
                    (*Tree)->Direita->Cor = 'b';
                    (*Tree)->Esquerda->Cor = 'b';
                    if(Pai != NULL)
                        (*Tree)->Cor = 'r';
                }
            }
        }
    }
    if((*Tree)->Direita != NULL)
    {
        if((*Tree)->Direita->Direita != NULL)
        {
            if((*Tree)->Direita->Cor == 'r' && (*Tree)->Direita->Direita->Cor == 'r')
            {
                if((*Tree)->Esquerda != NULL && (*Tree)->Esquerda->Cor == 'r')
                {
                    (*Tree)->Direita->Cor = 'b';
                    (*Tree)->Esquerda->Cor = 'b';
                    if(Pai != NULL)
                        (*Tree)->Cor = 'r';
                }
            }
        }
        if((*Tree)->Direita->Esquerda != NULL)
        {
            if((*Tree)->Direita->Cor == 'r' && (*Tree)->Direita->Esquerda->Cor == 'r')
            {
                if((*Tree)->Esquerda != NULL && (*Tree)->Esquerda->Cor == 'r')
                {
                    (*Tree)->Direita->Cor = 'b';
                    (*Tree)->Esquerda->Cor = 'b';
                    if(Pai != NULL)
                        (*Tree)->Cor = 'r';
                }
            }
        }
    }
}

void insere(RBTree**Tree, RBTree *Pai, int info, char *rotacionou)
{
    int FB, FB_Filho;

    if(*Tree == NULL)   //// ELEMENTO A SER INSERIDO SERA RAIZ
    {
        *Tree = criaNo(*Tree, 'r', info);
        (*Tree)->Pai = Pai;
        *rotacionou = 0;
    }
    else if(info > (*Tree)->Info)
        insere(&(*Tree)->Direita, *Tree, info, &*rotacionou);
    else
        insere(&(*Tree)->Esquerda, *Tree, info, &*rotacionou);

    if(*rotacionou == 0)
    {
        FB = altura((*Tree)->Direita) - altura((*Tree)->Esquerda);
        if(FB == 2 || FB == -2)
        {
            *rotacionou = 1;
            if(FB == 2)
            {
                FB_Filho = altura((*Tree)->Direita->Direita) - altura((*Tree)->Direita->Esquerda);

                if(FB_Filho == 1)   //// (2)(1) -> TIPO 1 EXEMPLO 1
                    rotacao_esquerda(&*Tree);
                else    ////  (2)(-1) -> TIPO 2 EXEMPLO 2
                {
                    rotacao_direita(&(*Tree)->Direita);
                    rotacao_esquerda(&*Tree);
                }
            }
            else    //// FB == -2
            {
                FB_Filho = altura((*Tree)->Esquerda->Direita) - altura((*Tree)->Esquerda->Esquerda);

                if(FB_Filho == -1)  //// (-2)(-1) -> TIPO 1 EXEMPLO 2
                    rotacao_direita(&*Tree);
                else    //// (-2)(1) -> TIPO 2 EXEMPLO 1
                {
                    rotacao_esquerda(&(*Tree)->Esquerda);
                    rotacao_direita(&*Tree);
                }
            }
        }
    }
    colore(&*Tree);
}*/

void rotacao_direita(RBTree **Tree)
{
	RBTree *Q;
	Q = (*Tree)->Esquerda;
	Q->Cor = 'b';
	(*Tree)->Cor = 'r';
	(*Tree)->Esquerda = Q->Direita;
	if((*Tree)->Esquerda != NULL)
		(*Tree)->Esquerda->Pai = *Tree;
	Q->Direita = *Tree;
	Q->Pai = (*Tree)->Pai;
	(*Tree)->Pai = Q;
	*Tree = Q;
}

void rotacao_esquerda(RBTree **Tree)
{
	RBTree *Q;
	Q = (*Tree)->Direita;
	Q->Cor = 'b';
	(*Tree)->Cor = 'r';
	(*Tree)->Direita = Q->Esquerda;
	if((*Tree)->Direita != NULL)
		(*Tree)->Direita->Pai = *Tree;
	Q->Esquerda = *Tree;
	Q->Pai = (*Tree)->Pai;
	(*Tree)->Pai = Q;
	*Tree = Q;
}

void insere(RBTree**Tree, RBTree *Pai,int info)
{
	if(*Tree == NULL)
	{
		*Tree = criaNo(Pai, 'r', info);

		if(Pai == NULL)
			(*Tree)->Cor = 'b';
	}
	else
	{
		if(info > (*Tree)->Info)
			insere(&(*Tree)->Direita,*Tree, info);
		else
			insere(&(*Tree)->Esquerda,*Tree, info);
	}

	if((*Tree)->Esquerda != NULL) /// filhoesq != null
	{
		if((*Tree)->Esquerda->Esquerda != NULL) /// filhoesq -> filhoesq != null
		{
			if((*Tree)->Esquerda->Cor == 'r' && (*Tree)->Esquerda->Esquerda->Cor == 'r')
			{   /// Pai e filho red
				if((*Tree)->Direita != NULL && (*Tree)->Direita->Cor == 'r')
				{
				    /// Pai, tio e filho red
					(*Tree)->Direita->Cor = 'b';
					(*Tree)->Esquerda->Cor = 'b';
					if((*Tree)->Pai != NULL) /// se nao for a Tree da arvore
						(*Tree)->Cor = 'r';
				}
				else
					rotacao_direita(&*Tree);
			}
		}

		if((*Tree)->Esquerda->Direita != NULL) /// filhoesq -> filhodir != null
		{
			if((*Tree)->Esquerda->Cor == 'r' && (*Tree)->Esquerda->Direita->Cor == 'r')
			{   /// Pai e filho red
				if((*Tree)->Direita != NULL && (*Tree)->Direita->Cor == 'r')
				{   /// Pai, tio e filho red
					(*Tree)->Direita->Cor = 'b';
					(*Tree)->Esquerda->Cor = 'b';
					if((*Tree)->Pai != NULL) /// se nao for a Tree da arvore
						(*Tree)->Cor = 'r';
				}
				else
				{
					rotacao_esquerda(&(*Tree)->Esquerda);
					rotacao_direita(&*Tree);
				}
			}
		}
	}

	if((*Tree)->Direita != NULL) /// filhodir != null
	{
		if((*Tree)->Direita->Direita != NULL) /// filhodir -> filhodir != null
		{
			if((*Tree)->Direita->Cor == 'r' && (*Tree)->Direita->Direita->Cor == 'r')
			{   /// Pai e filho red
				if((*Tree)->Esquerda != NULL && (*Tree)->Esquerda->Cor == 'r')
				{   /// tio, Pai e filho red
					(*Tree)->Direita->Cor = 'b';
                    (*Tree)->Esquerda->Cor = 'b';
					if((*Tree)->Pai != NULL) /// se nao for a Tree da arvore
						(*Tree)->Cor = 'r';
				}
				else
					rotacao_esquerda(&*Tree);
			}
		}

		if((*Tree)->Direita->Esquerda != NULL) /// filhodir -> filhoesq != null
		{
			if((*Tree)->Direita->Cor == 'r' && (*Tree)->Direita->Esquerda->Cor == 'r')
			{   /// Pai e filho red
				if((*Tree)->Esquerda != NULL && (*Tree)->Esquerda->Cor == 'r')
				{ /// Pai, tio e filho red
					(*Tree)->Direita->Cor = 'b';
					(*Tree)->Esquerda->Cor = 'b';
					if((*Tree)->Pai != NULL) /// se não for a Tree da arvore
						(*Tree)->Cor = 'r';
				}
				else
				{
					rotacao_direita(&(*Tree)->Direita);
					rotacao_esquerda(&*Tree);
				}
			}
		}
	}
}

/*void rotacao_esquerda(RBTree**Tree)
{
    RBTree *Q, *Temp;
    Q = (*Tree)->Direita;
    Temp = Q->Esquerda;
    Q->Esquerda = *Tree;
    (*Tree)->Direita = Temp;
    *Tree = Q;
}

void rotacao_direita(RBTree**Tree)
{
    RBTree *Q, *Temp;
    Q = (*Tree)->Esquerda;
    Temp = Q->Direita;
    Q->Direita = (*Tree);
    (*Tree)->Esquerda = Temp;
    *Tree = Q;
}*/

void nivel(RBTree *Raiz, int *nv)
{
    *nv = 0;
    while(Raiz != NULL)
    {
        *nv+=1;
        Raiz = Raiz->Pai;
    }
}

void exibe(RBTree *Tree, int x, int y, int dist)
{
    if(Tree != NULL)
    {
        if(Tree->Cor == 'r')
            textcolor(12);
        else
            textcolor(0);

        gotoxy(x, y); printf("%d", Tree->Info);
        textcolor(0);
        if(Tree->Direita != NULL)
        {
            gotoxy(x + dist/2, y + 1); printf("\\");
        }
        if(Tree->Esquerda != NULL)
        {
            gotoxy(x - dist/2, y + 1); printf("/");
        }
        exibe(Tree->Esquerda, x - dist, y + 2, dist/2);
        exibe(Tree->Direita, x + dist, y + 2, dist/2);
    }
}

#endif // RBTREE_H_INCLUDED
