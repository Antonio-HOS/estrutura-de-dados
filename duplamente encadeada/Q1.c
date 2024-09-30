#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expressao
{
    char descricao[81];
    struct expressao *prox;
    struct expressao *ant;
} expressao;

#define LIMITE 10

expressao *criarLista(expressao *cabeca, char descricao[81]);
expressao *consultarLista(expressao *cabeca, char descricao[81]);
void PrintrarDecrescente(expressao *cabeca);
void PrintrarCrescente(expressao *cabeca);
void PrintrarRank(expressao *cabeca, int quant);

int main()
{
    int escolha = 0;
    expressao *cabeca = NULL;

    while (escolha != 5)
    {
        printf("\n\nO que deseja fazer?\n[1]Consultar\n[2]Exibir Crescente\n[3]Exibir Decrescente\n[4]Exibir N\n[5]Encerrar\n[6]Criar\n\n");
        scanf("%i", &escolha);
        
        if (escolha == 6)
        {
            char descricao[81];
            printf("Digite a descricao: ");
            scanf("%s", descricao);
            cabeca = criarLista(cabeca, descricao);
        }
        else if (escolha == 5)
        {
            printf("\nPrograma encerrando\n");
            return 0;
        }
        else if (escolha == 4)
        {
            int n = 0;
            printf("\nNumero de itens a ser exibido: ");
            scanf("%i", &n);
            PrintrarRank(cabeca, n);
        }
        else if (escolha == 3)
        {
            PrintrarDecrescente(cabeca);
        }
        else if (escolha == 2)
        {
            PrintrarCrescente(cabeca);
        }
        else if (escolha == 1)
        {
            char palavra[81];
            printf("Digite a palavra a ser consultada: ");
            scanf("%s", palavra);
            expressao *resultado = consultarLista(cabeca, palavra);
            if (resultado != NULL)
            {
                printf("Encontrado: %s\n", resultado->descricao);
            }
            else
            {
                printf("Nao encontrado\n");
            }
        }
    }

    return 0;
}

expressao *criarLista(expressao *cabeca, char descricao[81])
{
    if (cabeca == NULL)
    {
        cabeca = (expressao *)malloc(sizeof(expressao));
        cabeca->prox = NULL;
        cabeca->ant = NULL;
        strcpy(cabeca->descricao, descricao);
        return cabeca;
    }

    expressao *aux = cabeca;
    int count = 1; // Contando o primeiro nó
    
    while (aux->prox != NULL)
    {
        aux = aux->prox;
        count++;
    }

    if (count >= LIMITE)
    {
        printf("Lista cheia\n");
        return cabeca;
    }

    expressao *novo = (expressao *)malloc(sizeof(expressao));
    strcpy(novo->descricao, descricao);
    novo->prox = NULL;
    novo->ant = aux;
    aux->prox = novo;

    return cabeca;
}

expressao *consultarLista(expressao *cabeca, char descricao[81])
{
    expressao *aux = cabeca;
    while (aux != NULL)
    {
        if (strcmp(aux->descricao, descricao) == 0)
        {
            return aux; // Retorna o nó encontrado
        }
        aux = aux->prox;
    }
    return NULL; // Retorna NULL se não encontrar
}

void PrintrarCrescente(expressao *cabeca)
{
    expressao *aux = cabeca;
    while (aux != NULL)
    {
        printf("%s\n", aux->descricao);
        aux = aux->prox;
    }
}

void PrintrarDecrescente(expressao *cabeca)
{
    expressao *aux = cabeca;
    if (aux == NULL)
    {
        return;
    }

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    while (aux != NULL)
    {
        printf("%s\n", aux->descricao);
        aux = aux->ant;
    }
}

void PrintrarRank(expressao *cabeca, int quant)
{
    expressao *aux = cabeca;
    int contador = 0;

    while (aux != NULL && contador < quant)
    {
        printf("%s\n", aux->descricao);
        aux = aux->prox;
        contador++;
    }
}
