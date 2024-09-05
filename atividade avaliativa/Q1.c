//espero que goste do codigo
#include <stdio.h>
#include <stdlib.h>
#include "./biblioteca.h"


void adicionarIntervalo(Intervalos **cabeca, int inicio, int fim);
void verificarPonto(Intervalos **x, int ponto);

void printLista(Intervalos *head);

int main()
{
    int menu = 9;
    int intervalo_inicio, intervalo_fim, ponto = 0;
    Intervalos *cabeca = NULL;

    printf("ola! veja as opcoes e selecione a adequada \n");

    while (menu != 0)
    {
        printf("[1]Adicionar intrvalo, [2]verificar ponto [0]sair\n");
        scanf("%i", &menu);

        if (menu == 1)
        {
            printf("insira dois numeros inteiros para ser seu intervalo\n");
            printf("numero de intevalo de inicio: ");
            scanf("%i", &intervalo_inicio);
            printf("numero de intervalo de fim: ");
            scanf("%i", &intervalo_fim);
            if (intervalo_inicio <= intervalo_fim)
            {
                printf("Intervalo invalido: o inicio deve ser < que o fim \n");
            }
            else
            {

                adicionarIntervalo(&cabeca, intervalo_inicio, intervalo_fim);
            }
        }
        else if (menu == 2)
        {
            printf("insira um numero inteiro para verificar se ele esta dentro de algum intervalo\n");
            scanf("%i", &ponto);
            verificarPonto(&cabeca, ponto);
        }
        else if (menu == 0)
        {
            printf("saindo...");
            for (int i = 0; i < 2; i++)
            {
                Intervalos *aux = cabeca;
                Intervalos *auxAoQuadrado = cabeca->proximo;

                while (aux->proximo != NULL)
                {
                    free(aux);
                    aux = auxAoQuadrado;
                    auxAoQuadrado = auxAoQuadrado->proximo;
                }

                return 0;
            }
        }

        else if (menu == 4) // funçao secreta
        {
            printLista(cabeca);
        }
        else
        {
            printf("\n\n insira um numero valido por favor\n");
        }
    }

    return 0;
}

void adicionarIntervalo(Intervalos **cabeca, int inicio, int fim)
{

    Intervalos *novo = (Intervalos *)malloc(sizeof(Intervalos));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória!\n");
    }
    novo->inicio = inicio;
    novo->fim = fim;
    novo->proximo = NULL;

    if (*cabeca == NULL)
    {
        *cabeca = novo;
    }
    else
    {
        Intervalos *aux = *cabeca;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void verificarPonto(Intervalos **cabeca, int ponto)
{
    Intervalos *aux = *cabeca;
    int contador = 0;

    do
    {

        if (ponto >= aux->inicio && ponto <= aux->fim)
        {
            printf("Dentro do intervalo [%d,%d]\n\n", aux->inicio, aux->fim);
            contador++;
        }

        aux = aux->proximo;
    } while (aux != NULL);

    if (contador == 0)
    {
        printf("Fora de todos os intervalos\n\n");
    }
}

void printLista(Intervalos *head)
{
    Intervalos *aux = head;
    while (aux != NULL)
    {
        printf("inicio %d  ", aux->inicio);
        printf("fim %d \n", aux->fim);

        aux = aux->proximo;
    }
    printf("fim\n");
}
