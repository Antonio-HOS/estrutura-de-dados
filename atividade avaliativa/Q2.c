//espero que goste do codigo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Contato
{
    char nome[256];
    char telefone[256];
    char email[256];
    struct Contato *proximo;

} Contato;

void AdiconarContato(Contato **cabeca, char nome_[256],char contato_[256],char email_[256]);
void verificarContato(Contato **x, char buscador[256]);

void printLista(Contato *head)
{
    Contato *aux = head;
    while (aux != NULL)
    {
        printf("{nome: %s,telefone: %s,email: %s   ---- }", aux->nome, aux->telefone, aux->email);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

int main()
{
    int menu = 9;
    char contato_buffer[256], nome_buffer[256], email_buffer[256], busca_buffer[256];
    Contato *cabeca = NULL;

    printf("ola! veja as opcoes e selecione a adequada \n");

    while (menu != 0)
    {
        printf("[1]Adicionar contato, [2]Visualizar contatos, [3]Buscar contato, [4]Remover contato [0]sair\n");
        scanf("%i", &menu);

        if (menu == 1)
        {
            printf("insira os elementos do seu contato\n");
            printf("numero do contato (com ddd, sem acento e sem espaços):");
            scanf("%s",contato_buffer);
            printf("nome do contato: ");
            scanf("%s",nome_buffer);
            printf("email do contato: ");
            scanf("%s",email_buffer);

            if (strlrn(contato_buffer) != 11 )
            {
                printf("Intervalo invalido: o inicio deve ser < que o fim \n");
            }
            else
            {

                adicionarIntervalo(&cabeca, contato_buffer, nome_buffer,email_buffer);
            }
        }
        else if (menu == 3)
        {
            printf("insira corretamente o nome do contato\n");
            scanf("%s", busca_buffer);
            verificarContato(&cabeca, busca_buffer);
        }
        else if (menu == 0)
        {
            printf("saindo...");
            for (int i = 0; i < 2; i++)
            {
                Contato *aux = cabeca;
                Contato *auxAoQuadrado = cabeca->proximo;

                while (aux->proximo != NULL)
                {
                    free(aux);
                    aux = auxAoQuadrado;
                    auxAoQuadrado = auxAoQuadrado->proximo;
                }

                return 0;
            }
        }

        else if (menu == 2) 
        {
            printf("mostrando todos os contatos..; \n");
            printLista(cabeca);
        }else if (menu == 4)
        {
            printf("digite exatamente o nome do contato que deseja apgar..; \n");
            scanf("%s", busca_buffer);
            apagarcontato(&cabeca, cabeca,busca_buffer);
        }
        else
        {
            printf("\n\n insira um numero valido por favor\n");
        }
    }

    return 0;
}

void AdiconarContato(Contato **cabeca, char nome_[256],char contato_[256],char email_[256])
{

    Contato *novo = (Contato *)malloc(sizeof(Contato));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória!\n");
    }
    strcpy(novo->nome,nome_);
    strcpy(novo->email,email_);
    strcpy(novo->telefone,contato_);
    
    novo->proximo = NULL;

    if (*cabeca == NULL)
    {
        *cabeca = novo;
    }
    else
    {
        Contato *aux = *cabeca;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void verificarContato(Contato **cabeca, char buscador[256])
{
    Contato *aux = *cabeca;
    int contador = 0;

    do
    {

        if (buscador == aux->nome)
        {
            printf("contato encontrado!\n\nnome: %s\ncontato: %s\nemail: %s]\n\n", aux->nome, aux->telefone, aux->email);
            contador++;
        }

        aux = aux->proximo;
    } while (aux != NULL);

    if (contador == 0)
    {
        printf("Contato inexistente \n\n");
    }
}



void apagarcontato(Contato **cabeca, Contato *cabeca2, char buscador[256])
{
    Contato *aux = *cabeca;
    Contato *auxaoquadrado = cabeca2->proximo;

    int contador = 0;

    do
    {

        if (buscador == aux->nome)
        {
            printf("contato encontrado!\n\nnome: %s\ncontato: %s\nemail: %s]\n\n", aux->nome, aux->telefone, aux->email);
            contador++;
        }

        aux = aux->proximo;
    } while (aux != NULL);

    if (contador == 0)
    {
        printf("Contato inexistente \n\n");
    }
}
