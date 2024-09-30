#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int valor;
    struct pilha *ant;
} typedef Pilha;

Pilha *CriaNo(Pilha *p, int inf)
{
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->valor = inf;
    aux->ant = p;
    return aux;
}

void imprimePilha(Pilha *p)
{
    Pilha *aux = p;

    while (aux != NULL)
    {
        printf("    %d   ", aux->valor);
        aux = aux->ant;
    }
}

int main()
{

    int num, option;
    printf("\n\n\ninsira um numero inteiro");
    scanf("%d", &num);

    printf("\n escolha a conversao [1] binario [2] octal");
    scanf("%d", &option);
    Pilha *pilha = NULL;
    if (option == 1)
    {
        while (num != 0)
        {
            pilha = CriaNo(pilha, num % 2);
            num = num / 2;
        }
    }
    if (option == 2)
    {
        while (num != 0)
        {
            pilha = CriaNo(pilha, num % 8);
            num = num / 8;
        }
    }
    

    imprimePilha(pilha);
    return 0;
}