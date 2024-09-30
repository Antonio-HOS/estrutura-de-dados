#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int info;
    struct pilha *ant;
} typedef Pilha;

struct fila
{
    int info;
    struct fila *prox;
} typedef Fila;

Pilha *criaNoPilha(Pilha *p, int inf)
{

    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->info = inf;
    aux->ant = p;
    return aux;
}

Fila *criaNoFila(Fila *f, int inf)
{

    Fila *aux = (Fila *)malloc(sizeof(Fila));
    aux->info = inf;
    aux->prox = NULL;
    if (f == NULL)
    {
        return aux;
    }

    Fila *percorre = f;
    while (percorre->prox != NULL)
    {
        percorre = percorre->prox;
    }
    percorre->prox = aux;

    return f;
}

void PrintarFila(Fila *f)
{
    Fila *aux = f;

    while (aux != NULL)
    {
        printf(" %i ", aux->info);
        aux = aux->prox;
    }
}

void PrintarPilha(Pilha *p)
{
    Pilha *aux = p;
    while (aux != NULL)
    {
        printf(" %i ", aux->info);
        aux = aux->ant;
    }
}

Fila *tirarFila(Fila *f)
{
    Fila *aux = f->prox;
    free(f);
    return aux;
}

Pilha *TirarPilha(Pilha *p)
{
    Pilha *aux = p->ant;
    free(p);
    return aux;
}

Fila *inverteFila(Fila *f)
{
    Fila *anterior = NULL;
    Fila *atual = f;
    Fila *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}

Pilha *invertePilha(Pilha *p)
{

    Pilha *atual = p;
    Pilha *anterior = NULL;
    Pilha *proxima = NULL;

    while (atual != NULL)
    {
        anterior = atual->ant;
        atual->ant = proxima;
        proxima = atual;
        atual = anterior;
    }
    return proxima;
}

int main()
{
    Fila *fila = NULL;

    fila = criaNoFila(fila, 1);
    criaNoFila(fila, 2);
    criaNoFila(fila, 3);
    criaNoFila(fila, 4);
    PrintarFila(fila);
    printf("\n\n\n");
    Pilha *pilha = NULL;
    pilha = criaNoPilha(pilha, 1);
    pilha = criaNoPilha(pilha, 2);
    pilha = criaNoPilha(pilha, 3);
    pilha = criaNoPilha(pilha, 4);
    PrintarPilha(pilha);
    printf("\n\n\n");

    fila = tirarFila(fila);
    pilha = TirarPilha(pilha);
    PrintarFila(fila);
    printf("\n\n\n");
    PrintarPilha(pilha);
    printf("\n\n\nInverter fila");
    fila = inverteFila(fila);
    PrintarFila(fila);
    printf("\n\n\nInverter pilha");
    pilha = invertePilha(pilha);
    PrintarPilha(pilha);


    return 0;
}