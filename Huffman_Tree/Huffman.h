#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "meuconio.h"

struct huffmantree
{
    int Frequencia;
    char Info;
    struct huffmantree *Direita;
    struct huffmantree *Esquerda;

};
typedef struct huffmantree HTree;

struct frase
{
    int Frequencia;
    HTree *Nodo;
};
typedef struct frase String;

//// FUNÇÕES

HTree *criaNo(char info);
int busca_letra(String Str[], char info, int TL);
void getString(String Str[], int *TL, char aux[]);
void ordena(String Str[], int TL);
void insere(HTree**Tree, String Str[], int TL);
void gera_codigo(HTree *Tree, char Cod[], int TL);
void exibe_frase(char Str[], int TL);
void exibe_arvore(HTree *Tree, int x, int y, int espaco);
void exibe_letra_frequencia(String Str[], int TL);
void exibe_letra_nivel(HTree *Tree, int nv);

//// IMPLEMENTAÇÃO DAS FUNÇÕES

HTree *criaNo(char info)
{
    HTree *Novo = (HTree*)malloc(sizeof(HTree));
    Novo->Info = info;
    Novo->Direita = NULL;
    Novo->Esquerda = NULL;
    Novo->Frequencia = 0;

    return Novo;
}

void getString(String Str[], int *TL, char aux[])
{
    int i, j;

    gets(aux);
    i = 0;

    while(aux[i] != '\0')
    {
        j = busca_letra(Str, aux[i], *TL);
        if(j < 0)
        {
            Str[(*TL)].Nodo = criaNo(aux[i]);
            Str[(*TL)].Frequencia = 1;
            Str[(*TL)].Nodo->Frequencia = 1;
            *TL = (*TL)+1;
        }
        else
        {
            Str[j].Frequencia++;
            Str[j].Nodo->Frequencia++;
        }
        i++;
    }
}

int busca_letra(String Str[], char info, int TL)
{
    int i = 0;

    for(;i < TL && Str[i].Nodo->Info != info; i++);

    if(i < TL)
        return i;
    return -1;
}

void ordena(String Str[], int TL)
{
    int i, j;
    String Aux;
    for(i = TL; i > 0; i--)
    {
        for(j = 0; j < TL - 1; j++)
        {
            if(Str[j].Frequencia < Str[j + 1].Frequencia)
            {
                Aux = Str[j];
                Str[j] = Str[j + 1];
                Str[j + 1] = Aux;
            }
            else if(Str[j].Frequencia == Str[j + 1].Frequencia)
            {
                if(Str[j].Nodo->Info < Str[j + 1].Nodo->Info)
                {
                    Aux = Str[j];
                    Str[j] = Str[j + 1];
                    Str[j + 1] = Aux;
                }
            }
        }
    }

}

void insere(HTree**Tree, String Str[], int TL)
{
    HTree *Aux;
    int faux;

    while(TL > 1)
    {
        Aux = criaNo(Str[TL - 1].Nodo->Info + Str[TL - 2].Nodo->Info);    //// CRIA O NÓ QUE CONTEM AS MENORES FREQUENCIAS
        //// OS DOIS MENORES SÃO FILHOS DESSE NÓ
        Aux->Esquerda = Str[TL - 1].Nodo;
        Aux->Direita = Str[TL - 2].Nodo;

        faux = Str[TL - 1].Frequencia + Str[TL - 2].Frequencia;   //// CALCULA A NOVA FREQUENCIA E INSERE DE VOLTA

        Str[TL - 2].Frequencia = faux;
        Str[TL - 2].Nodo = Aux;

        ordena(Str, --TL);
    }
    *Tree = Str[0].Nodo;
}

void gera_codigo(HTree *Tree, char Cod[], int TL)
{
    if(Tree != NULL)
    {
        if(Tree->Direita != NULL && Tree->Esquerda == NULL)
        {
            Cod[TL] = '\0';
            printf("Letra: %c \tFrequencia: %d \tCodigo:%s\n", Tree->Info, Tree->Frequencia, Cod);
        }
        else
        {
            Cod[TL] = '0';
            gera_codigo(Tree->Esquerda, Cod, TL + 1);
            Cod[TL] = '1';
            gera_codigo(Tree->Direita, Cod, TL + 1);
        }
    }
}

void exibe_frase(char Str[], int TL)
{
    int i;

    for(i = 0; i < TL; i++)
        printf("%c", Str[i]);
    getch();
}

void exibe_arvore(HTree *Tree, int x, int y, int espaco)
{
    if(Tree != NULL)
    {
        exibe_arvore(Tree->Esquerda, x - espaco, y + 2, espaco/2);
        if(Tree->Esquerda == NULL && Tree->Direita == NULL)
        {
            gotoxy(x, y); printf("%c", Tree->Info);
        }
        else
        {
            gotoxy(x, y); printf("*");
        }
        if(Tree->Esquerda != NULL);
        {
            gotoxy(x - espaco, y + 1); printf("/");
        }
        if(Tree->Direita != NULL);
        {
            gotoxy(x + espaco, y + 1); printf("\\");
        }
        exibe_arvore(Tree->Direita, x + espaco, y + 2, espaco/2);
    }
}

void exibe_letra_frequencia(String Str[], int TL)
{
    int i;

    for(i = 0; i < TL; i++)
        printf("%c - %d\n", Str[i].Nodo->Info, Str[i].Frequencia);
    getch();
}

void exibe_letra_nivel(HTree *Tree, int nv)
{
    if(Tree != NULL)
    {
        if(Tree->Direita == NULL && Tree->Esquerda == NULL)
            printf("Info:\t%c\tNivel:\t%d\n", Tree->Info, nv);
        else
        {
            exibe_letra_nivel(Tree->Esquerda, nv + 1);
            exibe_letra_nivel(Tree->Direita, nv + 1);
        }
    }
}

#endif // HUFFMAN_H_INCLUDED
