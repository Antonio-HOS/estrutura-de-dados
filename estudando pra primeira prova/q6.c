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

Fila *Nofila(Fila *f, int i);

Pilha *NoPilha(Pilha *p, int i);

int DesFila(Fila **f);

void printarPilha(Pilha *p);

void printaFila(Fila *f);

int quatosImpares(Fila *f){
    int count =0;
    Fila *aux = f;
    while(aux!=NULL){
        if(aux->info%2==1){
            count++;
        }
        aux=aux->prox;

    }
    return count;
}
int main()
{

    Fila *fpar, *fimpar, *ftodos;
    fpar = NULL;
    fimpar = NULL;
ftodos =NULL;

    int buff = 1;
    printf("va enviando os numeros\n");
    while (buff != 0)
    {

        scanf("%d", &buff);
        if (buff != 0)
        {
            ftodos = Nofila(ftodos,buff);
            if (buff % 2 == 0)
            {
                fpar = Nofila(fpar, buff);
            }
            else
            {
                fimpar = Nofila(fimpar, buff);
            }
        }
    }
    printf("\n\n");
    printaFila(fpar);
    printf("\n\n");

    printaFila(fimpar);

    Pilha *pilha = NULL;
    while (fpar != NULL || fimpar != NULL)
    {

        if (fimpar != NULL)
        {
            pilha = NoPilha(pilha, DesFila(&fimpar));
        }

        if (fpar != NULL)
        {
            pilha = NoPilha(pilha, DesFila(&fpar));
        }
    }
    printarPilha(pilha);
    printf("\n\n\ntem %d impares no total",quatosImpares(ftodos));

    return 0;
}

Fila *Nofila(Fila *f, int i)
{
    Fila *aux = (Fila *)malloc(sizeof(Fila));
    aux->info = i;
    aux->prox = NULL;

    if (f == NULL)
    {
        return aux;
    }

    Fila *percorrer = f;
    while (percorrer->prox != NULL)
    {
        percorrer = percorrer->prox;
    }
    percorrer->prox = aux;

    return f;
}

Pilha *NoPilha(Pilha *p, int i)
{

        if (i > 0)
    {
        Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
        aux->info = i;
        aux->ant = p;
        return aux;
    }
    else
    {
        Pilha *aux = p->ant;
        free(p);
        return aux;
    }
    return NULL;
}

int DesFila(Fila **f)
{
    Fila *aux = *f;
    int i = (*f)->info;
    *f = aux->prox;
    free(aux);
printf("\n                         %d",i);
    return i;
}

void printarPilha(Pilha *p)
{
    Pilha *aux = p;
    while (aux != NULL)
    {
        printf("\npilha->%d", aux->info);
        aux = aux->ant;
    }
}

void printaFila(Fila *f)
{
    Fila *aux = f;
    while (aux != NULL)
    {
        printf("%d", aux->info);
        aux = aux->prox;
    }
}