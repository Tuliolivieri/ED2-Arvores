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

void rotacao_direita(RBTree **no)
{
	RBTree *q = (*no)->Esquerda;
	q->Cor = 'b';
	(*no)->Cor = 'r';
	(*no)->Esquerda = q->Direita;
	if((*no)->Esquerda != NULL)
		(*no)->Esquerda->Pai = *no;
	q->Direita = *no;
	q->Pai = (*no)->Pai;
	(*no)->Pai = q;
	*no = q;
}

void rotacao_esquerda(RBTree **no)
{
	RBTree *q = (*no)->Direita;
	q->Cor = 'b';
	(*no)->Cor = 'r';
	(*no)->Direita = q->Esquerda;
	if((*no)->Direita != NULL)
		(*no)->Direita->Pai = *no;
	q->Esquerda = *no;
	q->Pai = (*no)->Pai;
	(*no)->Pai = q;
	*no = q;
}

void insere(RBTree**raiz, RBTree *pai,int info)
{
	if(*raiz == NULL)
	{
		*raiz = criaNo(pai, 'r', info);

		if(pai == NULL)
			(*raiz)->Cor = 'b';
	}
	else
	{
		if(info > (*raiz)->Info)
			insere(&(*raiz)->Direita,*raiz, info);
		else
			insere(&(*raiz)->Esquerda,*raiz, info);
	}

	if((*raiz)->Esquerda != NULL) /// filhoesq != null
	{
		if((*raiz)->Esquerda->Esquerda != NULL) /// filhoesq -> filhoesq != null
		{
			if((*raiz)->Esquerda->Cor == 'r' && (*raiz)->Esquerda->Esquerda->Cor == 'r')
			{   /// pai e filho red
				if((*raiz)->Direita != NULL && (*raiz)->Direita->Cor == 'r')
				{
				    /// pai, tio e filho red
					(*raiz)->Direita->Cor = 'b';
					(*raiz)->Esquerda->Cor = 'b';
					if((*raiz)->Pai != NULL) /// se nao for a raiz da arvore
						(*raiz)->Cor = 'r';
				}
				else
					rotacao_direita(&*raiz);
			}
		}

		if((*raiz)->Esquerda->Direita != NULL) /// filhoesq -> filhodir != null
		{
			if((*raiz)->Esquerda->Cor == 'r' && (*raiz)->Esquerda->Direita->Cor == 'r')
			{   /// pai e filho red
				if((*raiz)->Direita != NULL && (*raiz)->Direita->Cor == 'r')
				{   /// pai, tio e filho red
					(*raiz)->Direita->Cor = 'b';
					(*raiz)->Esquerda->Cor = 'b';
					if((*raiz)->Pai != NULL) /// se nao for a raiz da arvore
						(*raiz)->Cor = 'r';
				}
				else
				{
					rotacao_esquerda(&(*raiz)->Esquerda);
					rotacao_direita(&*raiz);
				}
			}
		}
	}

	if((*raiz)->Direita != NULL) /// filhodir != null
	{
		if((*raiz)->Direita->Direita != NULL) /// filhodir -> filhodir != null
		{
			if((*raiz)->Direita->Cor == 'r' && (*raiz)->Direita->Direita->Cor == 'r')
			{   /// pai e filho red
				if((*raiz)->Esquerda != NULL && (*raiz)->Esquerda->Cor == 'r')
				{   /// tio, pai e filho red
					(*raiz)->Direita->Cor = 'b';
                    (*raiz)->Esquerda->Cor = 'b';
					if((*raiz)->Pai != NULL) /// se nao for a raiz da arvore
						(*raiz)->Cor = 'r';
				}
				else
					rotacao_esquerda(&*raiz);
			}
		}

		if((*raiz)->Direita->Esquerda != NULL) /// filhodir -> filhoesq != null
		{
			if((*raiz)->Direita->Cor == 'r' && (*raiz)->Direita->Esquerda->Cor == 'r')
			{   /// pai e filho red
				if((*raiz)->Esquerda != NULL && (*raiz)->Esquerda->Cor == 'r')
				{ /// pai, tio e filho red
					(*raiz)->Direita->Cor = 'b';
					(*raiz)->Esquerda->Cor = 'b';
					if((*raiz)->Pai != NULL) /// se não for a raiz da arvore
						(*raiz)->Cor = 'r';
				}
				else
				{
					rotacao_direita(&(*raiz)->Direita);
					rotacao_esquerda(&*raiz);
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
