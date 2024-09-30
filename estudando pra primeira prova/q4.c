#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int arr[100];
    int topo;
} typedef Pilha;

Pilha *inicializar()
{
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->topo = -1;
    return aux;
}

void criarNo(Pilha* l, int i){
   
   if (l->topo == 100-1)
   {
    printf("pilha lotada");
    return;
   }
   
    l->topo ++;
    l->arr[l->topo]=i;
}

int verifica(Pilha* l1, Pilha* l2){
    if (l1->topo != l2->topo)
    {
        return 1;
    }
    for (int i = 0; i < l1->topo +1; i++)
    {
        if(l1->arr[i]!=l2->arr[i]){
            return 1;
        }
    }
    
    return 0;
}

void printar(Pilha* pilha){
    for (int i = 0; i < pilha->topo +1; i++)
    {
        printf("%d", pilha->arr[i]);
    }
    
}

int main()
{
    Pilha *l1 = inicializar();
    Pilha *l2 = inicializar();

    criarNo(l1,1);
    criarNo(l1,2);
    criarNo(l1,3);
    criarNo(l1,4);

    criarNo(l2,1);
    criarNo(l2,2);
    criarNo(l2,3);
    criarNo(l2,3);

    printar(l1);
    printar(l2);

    printf("\n\n resultado %d",verifica(l1,l2));
    return 0;
}