// espero que goste do codigo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./biblioteca.h"

void AdicionarContato(Contato **cabeca, Contato *cabeca2, char nome_[256], char contato_[256], char email_[256]);
void verificarContato(Contato **x, char buscador[256]);
void apagarcontato(Contato **cabeca, char buscador[256]);
void printListaContato(Contato *head);
int verificarquantidade(Contato *head);
int verificarSeContatoExite(Contato **cabeca, char buscador[256]);


int main()
{
    int menu = 9;
    char contato_buffer[256], nome_buffer[256], email_buffer[256], busca_buffer[256];
    Contato *cabeca = NULL;

    printf("Ola! Veja as opcoes e selecione a adequada \n");

    while (menu != 0)
    {
        printf("[1] Adicionar contato, [2] Visualizar contatos, [3] Buscar contato, [4] Remover contato, [0] Sair\n");
        scanf("%i", &menu);

        if (menu == 1)
        {
            printf("Insira os elementos do seu contato\n");
            printf("Numero do contato (com DDD, sem acento e sem espacos [11 digitos]): ");
            scanf("%s", contato_buffer);
            printf("Nome do contato: ");
            scanf("%s", nome_buffer);
            printf("Email do contato: ");
            scanf("%s", email_buffer);

            if (strlen(contato_buffer) != 11)
            {
                printf("Numero invalido: o numero deve ter 11 digitos\n");
            }
            else if (strchr(email_buffer, '@') == NULL && strchr(email_buffer, '.') == NULL)
            {
                printf("email invalido, tente novamente [exemplo@gmail.com]\n");
            }else if(verificarSeContatoExite(&cabeca, nome_buffer) == 1){
                printf("Contato já existente\n");
            }
            else
            {
                AdicionarContato(&cabeca, cabeca, nome_buffer, contato_buffer, email_buffer);
            }
        }
        else if (menu == 2)
        {
            printf("Mostrando todos os contatos...\n");
            printListaContato(cabeca);
        }
        else if (menu == 3)
        {
            printf("Insira corretamente o nome do contato\n");
            scanf("%s", busca_buffer);
            verificarContato(&cabeca, busca_buffer);
        }
        else if (menu == 4)
        {
            printf("Digite exatamente o nome do contato que deseja apagar\n");
            scanf("%s", busca_buffer);
            apagarcontato(&cabeca, busca_buffer);
        }
        else if (menu == 0)
        {
            printf("Tchau tchau...\n");
            Contato *aux = cabeca;
            while (aux != NULL)
            {
                Contato *temp = aux;
                aux = aux->proximo;
                free(temp);
            }
        }
        else
        {
            printf("\n\nInsira um numero valido por favor\n");
        }
    }

    return 0;
}

void AdicionarContato(Contato **cabeca, Contato *cabeca2, char nome_[256], char contato_[256], char email_[256])
{

    if (verificarquantidade(cabeca2) >= 100)
    {
        printf("Limite de contatos atingido\n");
        return;
    }

    Contato *novo = (Contato *)malloc(sizeof(Contato));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    strcpy(novo->nome, nome_);
    strcpy(novo->telefone, contato_);
    strcpy(novo->email, email_);
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

    printf("contato adicionado com sucesso\n");
}

void verificarContato(Contato **cabeca, char buscador[256])
{
    Contato *aux = *cabeca;
    int contador = 0;

    while (aux != NULL)
    {
        if (strcmp(buscador, aux->nome) == 0)
        {
            printf("Contato encontrado!\n\nNome: %s\nTelefone: %s\nEmail: %s\n\n", aux->nome, aux->telefone, aux->email);
            contador++;
        }
        aux = aux->proximo;
    }

    if (contador == 0)
    {
        printf("Contato inexistente\n\n");
    }
}

void apagarcontato(Contato **cabeca, char buscador[256])
{
    Contato *aux = *cabeca;
    Contato *anterior = NULL;

    while (aux != NULL && strcmp(aux->nome, buscador) != 0)
    {
        anterior = aux;
        aux = aux->proximo;
    }

    if (aux == NULL)
    {
        printf("Contato inexistente\n\n");
        return;
    }

    if (anterior == NULL)
    {
        *cabeca = aux->proximo;
    }
    else
    {
        anterior->proximo = aux->proximo;
    }

    printf("\nContato removido: \nnome: %s, telefone: %s, email: %s\n", aux->nome, aux->telefone, aux->email);
    free(aux);
}

void printListaContato(Contato *head)
{
    Contato *aux = head;
    while (aux != NULL)
    {
        printf("\n{nome: %s, telefone: %s, email: %s ---- }\n", aux->nome, aux->telefone, aux->email);
        aux = aux->proximo;
    }
    printf("fim da lista\n");
}

int verificarquantidade(Contato *head)
{
    Contato *aux = head;
    int contador = 0;
    while (aux != NULL)
    {
        aux = aux->proximo;
        contador++;
    }
    return contador;
}

int verificarSeContatoExite(Contato **cabeca, char buscador[256])
{
    Contato *aux = *cabeca;
    int contador = 0;

    while (aux != NULL)
    {
        if (strcmp(buscador, aux->nome) == 0)
        {
            return 1;
        }
        aux = aux->proximo;
    }
return 0;
}