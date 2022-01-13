#ifndef REDESOCIAL_H INCLUDED
#define REDESOCIAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct usuarios
{
    char nome[100];
    char email[100];
    char login[50];
    char senha[50];
    TData data_de_nascimento;
    int ID;
    int numeros_amigos;
}TUsuarios;

typedef struct redeSocial
{
    TUsuarios vetor[100];
    int matriz[100][100];
    int matriz_amigos_em_comum[100][100];
    int indice;
    TUsuarios user_escolhidos[2];
}TRedeSocial;

void Ler(TUsuarios *user);
void Imprimir(TUsuarios user);
void Iniciar(TRedeSocial *rede);
void Cadastrar(TRedeSocial *rede, TUsuarios user);
void Imprimir2(TRedeSocial rede);
int Pesquisar(TRedeSocial rede, TUsuarios user);
void Alterar(TRedeSocial *rede, TUsuarios user, int i);
void Excluir(TRedeSocial *rede, int i);

// Sao funcoes que ajudam na reutilizacao do codigo
int RedeVazia(TRedeSocial rede);
int RedeCheia(TRedeSocial rede);
#endif
