#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    char info;
    struct lista *ant;
} typedef Lista;

Lista *criarNo(Lista *list, char c);
int quantidade(Lista *list);
void printa(Lista* list);
int verifica(Lista* list);

int main()
{

    Lista *lista = NULL;
    lista = criarNo(lista,'a');
    lista = criarNo(lista,'b');
    lista = criarNo(lista,'c');

    lista = criarNo(lista,'c');
    lista = criarNo(lista,'b');
    lista = criarNo(lista,'a');

    printa(lista);
    printf("%d", quantidade(lista));

    printf("\n\n%d se o valor for diferente de zero, sao diferentes", verifica(lista));

    return 0;
}

Lista *criarNo(Lista *list, char c)
{

    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = c;
    novo->ant = list;
}

int quantidade(Lista *list)
{

    if (list == NULL)
    {
        return 0;
    }

    Lista *aux = list;

    int count = 0;
    while (aux != NULL)
    {
        
        aux = aux->ant;
        count++;
    }
    return count;
}

void printa(Lista* list){
    Lista *aux= list;
    while (aux!=NULL)
    {
        printf(" %c ",aux->info);
        aux=aux->ant;
    }
    
}

int verifica(Lista* list){
    
    int quant = quantidade(list);
    if(quant%2==1){
        return 1;
    }
    quant = quant/2;
    char arr1[quant];
    char arr2[quant];
Lista *aux = list;
    for (int i = 0; i < quant; i++)
    {
        arr1[i]=aux->info;
        aux= aux->ant;

    }
    for (int i = quant; i > 0; i--)
    {
        printf("\n->%i",i);
        arr2[i-1]=aux->info;

        aux= aux->ant;

    }




    return (strcmp(arr1,arr2));
}