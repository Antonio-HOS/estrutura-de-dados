// Implemente uma função que receba uma lista como parâmetro, crie uma cópia da lista original e
// retorne um ponteiro para a nova lista. A lista copiada deve manter a mesma ordem dos nós da
// lista original.

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

int quantNos(Lista *listInf);

Lista *copyLista(Lista *listInf);

void criarno(int i, Lista **Cabeca);

void printar(Lista *lista);

Lista *concatena(Lista *L1, Lista *L2);

Lista *arrayToList(int arr[], int tam);

Lista *apagarList(int n, Lista *list);

Lista *inverte(Lista *list);

int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    Lista *mylist = (Lista *)malloc(sizeof(Lista));
    mylist->info = 1;
    mylist->prox = NULL;

    criarno(2, &mylist);
    criarno(3, &mylist);
    criarno(4, &mylist);

    printf("%d \n", quantNos(mylist));

    Lista *listacopia = copyLista(mylist);
    printf("\nlista 1\n");
    printar(mylist);
    printf("\nlista 2\n");

    printar(listacopia);
    printf("\n%d \n", quantNos(listacopia));

    concatena(mylist, listacopia);
    printf("\nLista concatenadda\n");
    printar(mylist);

    printf("\nArray pra lista\n");
    Lista *Arrlist = arrayToList(arr, 10);
    printar(Arrlist);

    printf("\nApagando 4 elementos\n");
    Lista *ListApagado = apagarList(4, Arrlist);
    printar(ListApagado);

    
    printf("\nInvertendo a ordem\n");
    ListApagado = inverte(ListApagado);
    printar(ListApagado);

    return 0;
}

Lista *copyLista(Lista *listInf)
{
    Lista *Cabeca = (Lista *)malloc(sizeof(Lista));
    Cabeca->info = listInf->info;
    Cabeca->prox = NULL;

    Lista *auxPercorrer = (Lista *)malloc(sizeof(Lista));

    auxPercorrer = listInf->prox;
    while (auxPercorrer != NULL)
    {
        criarno(auxPercorrer->info, &Cabeca);
        auxPercorrer = auxPercorrer->prox;
    }

    return Cabeca;
}

int quantNos(Lista *listInf)
{

    if (listInf == NULL)
    {
        return 0;
    }

    Lista *aux = listInf;
    int i;
    for (i = 1; aux->prox != NULL; i++)
    {
        aux = aux->prox;
    }

    return i;
}

void criarno(int i, Lista **Cabeca)
{
    if (*Cabeca == NULL)
    {
        *Cabeca = (Lista *)malloc(sizeof(Lista));
        (*Cabeca)->info = i;
        (*Cabeca)->prox = NULL;
    }

    Lista *percorrer = (Lista *)malloc(sizeof(Lista));
    percorrer = *Cabeca;
    Lista *aux2 = (Lista *)malloc(sizeof(Lista));
    aux2->info = i;
    aux2->prox = NULL;
    while (percorrer->prox != NULL)
    {
        percorrer = percorrer->prox;
    }

    percorrer->prox = aux2;
}

void printar(Lista *lista)
{
    Lista *aux = lista;
    while (aux != NULL)
    {
        printf(" %d ", aux->info);
        aux = aux->prox;
    }
}

Lista *concatena(Lista *L1, Lista *L2)
{

    Lista *aux = (Lista *)malloc(sizeof(Lista));
    aux = L1;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = L2;

    return L1;
}

Lista *arrayToList(int arr[], int tam)
{
    if (tam == 0)
    {
        return NULL;
    }

    Lista *Cabeca = (Lista *)malloc(sizeof(Lista));
    Cabeca->info = arr[0];
    Cabeca->prox = NULL;
    for (int i = 1; i < tam; i++)
    {
        criarno(arr[i], &Cabeca);
    }

    return Cabeca;
}

Lista *apagarList(int n, Lista *list)
{

    Lista *aux = (Lista *)malloc(sizeof(Lista));
    aux = list;
    Lista *aux2 = (Lista *)malloc(sizeof(Lista));

    for (int i = 0; i < n; i++)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    return aux;
}

Lista *inverte(Lista *list)
{

    Lista *anterior = NULL;
    Lista *atual = list;
    Lista *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}