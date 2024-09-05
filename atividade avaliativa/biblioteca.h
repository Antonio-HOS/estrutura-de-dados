#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[256];
    char telefone[256];
    char email[256];
    struct Contato *proximo;
} Contato;

typedef struct Intervalos
{
    int inicio;
    int fim;
    struct Intervalos *proximo;

} Intervalos;

// funcoes de contato
void AdicionarContato(Contato **cabeca, Contato *cabeca2,char nome_[256], char contato_[256], char email_[256]);
void verificarContato(Contato **cabeca, char buscador[256]);
void apagarcontato(Contato **cabeca, char buscador[256]);
void printListaContato(Contato *head);
int verificarquantidade(Contato *head);
int verificarSeContatoExite(Contato **cabeca, char buscador[256]);


// funcoes de intervalo
void adicionarIntervalo(Intervalos **cabeca, int inicio, int fim);
void verificarPonto(Intervalos **x, int ponto);
void printLista(Intervalos *head);

#endif // CONTATO_H
