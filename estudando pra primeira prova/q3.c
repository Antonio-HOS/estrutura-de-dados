#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Definindo um valor máximo para o texto

struct pilha
{
    char info[MAX];
    int topo;
} typedef Pilha;

Pilha *inializar(Pilha *pilha)
{
    pilha->topo = -1;
    return pilha;
}

void empilhar(Pilha *pilha, char c)
{
    pilha->topo++;
    pilha->info[(pilha->topo)] = c;
}

char desimpilhar(Pilha *pilha)
{
    return pilha->info[(pilha->topo)--];
}

void printar(Pilha *pilha)
{
    for (int i = 0; i < pilha->topo + 1; i++)
    {
        printf("%c", pilha->info[i]);
    }
}

void desimpilharTudo(Pilha *pilha)
{
    for (int i = pilha->topo + 1; i > 0; i--)
    {
        printf("%c", desimpilhar(pilha));
    }
}

void inverter(Pilha *pilha)
{
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux = inializar(aux);
    printf("%d", pilha->topo);
    for (int i = 0; i < pilha->topo + 1; i++)
    {
        if ((pilha->info[i]) != ' ' && pilha->info[i] != '.')
        {

            empilhar(aux, pilha->info[i]);
        }else{
            desimpilharTudo(aux);
            printf("%c", pilha->info[i]);
        }
    }
}

int main()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(pilha));
    pilha = inializar(pilha);

    empilhar(pilha, 'a');
    empilhar(pilha, 'n');
    empilhar(pilha, 't');
    empilhar(pilha, 'o');
    empilhar(pilha, 'n');
    empilhar(pilha, 'i');
    empilhar(pilha, 'o');
    empilhar(pilha, ' ');
    empilhar(pilha, 'h');
    empilhar(pilha, 'e');
    empilhar(pilha, 'r');
    empilhar(pilha, 'i');
    empilhar(pilha, 'q');
    empilhar(pilha, 'u');
    empilhar(pilha, 'e');
    empilhar(pilha, '.');

    printar(pilha);
    inverter(pilha);
    return 0;
}