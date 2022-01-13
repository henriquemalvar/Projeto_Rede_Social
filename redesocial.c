#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "redesocial.h"

void Ler(TUsuarios *user){
    /* A funcao recebe tds os dados do usuario*/

    printf("\nDigite o nome do usuario: ");
    fflush(stdin);
    fgets(user->nome, 100, stdin);

    printf("\nDigite o email do usuario: ");
    fflush(stdin);
    fgets(user->email, 200, stdin);

    printf("\nDigite o login do usuario: ");
    fflush(stdin);
    fgets(user->login, 50, stdin);

    printf("\nDigite a senha: ");
    fflush(stdin);
    fgets(user->senha, 50, stdin);

    printf("\nData de Nascimento:\n");
    printf("\nDigite o dia: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.dia);

    printf("\nDigite o mes: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.mes);

    printf("\nDigite o ano: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.ano);

    user->numeros_amigos = 0;
}

void Imprimir(TUsuarios user){
    /* A funcao exibe na tela os dados do usuario passado */

    printf("\nNome do usuario: ");
    printf("\n%s", user.nome);

    printf("\nEmail do usuario: ");
    printf("\n%s", user.email);

    printf("\nLogin do usuario: ");
    printf("\n%s", user.login);

    printf("\nSenha do usuario: ");
    printf("\n%s", user.senha);

    printf("\nData de Nascimento: \n");
    printf("\n\tDia: ");
    printf("%d", user.data_de_nascimento.dia);

    printf("\n\tMes: ");
    printf("%d", user.data_de_nascimento.mes);

    printf("\n\tAno: ");
    printf("%d", user.data_de_nascimento.ano);
}

void Iniciar(TRedeSocial *rede){
    /* A funcao inicia a rede, inicializando a variavel indice em 0 e colocando o valor 0 em toda a matriz, que representa a matriz de amizade, e na matriz_amigos_em_comum.  */
    rede->indice = 0;
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++){
            rede->matriz[i][j] = 0;
            rede->matriz_amigos_em_comum[i][j] = 0;
        }
}

void Cadastrar(TRedeSocial *rede, TUsuarios user){
    /* A funcao cadastra um usuario lido no vetor de usuarios na rede, usando o indice da rede como local do vetor aonde o usuario sera alocado, passa o valor do indice ao id do usuario
    e aumenta o valor do indice em 1 */
    rede->vetor[rede->indice] = user;
    rede->vetor[rede->indice].ID = rede->indice;
    rede->indice++;
}

void Imprimir2(TRedeSocial rede){
    /* Imprime a lista de usuarios total da rede usando a funcao imprimir e passando cada usuario do vetor, exibindo as informacoes de todos*/
    for(int i = 0; i < rede.indice; i++)
        if(rede.vetor[i].ID >= 0)
            Imprimir(rede.vetor[i]);
}

int Pesquisar(TRedeSocial rede, TUsuarios user){
    /* Pesquisa um usuario comparando o nome do usuario recebido com o nome dos usuarios da rede, retornando o id caso o usuario seja encontrado, caso nao seja retorna -1*/
    for(int i = 0; i < rede.indice; i++){
        if(strcmp(rede.vetor[i].nome, user.nome) == 0 && rede.vetor[i].ID >= 0)
            return rede.vetor[i].ID;
    }
    return -1;
}

void Alterar(TRedeSocial *rede, TUsuarios user, int i){
    /* Recebe um usuario modificado e um indice, o usuario modificado substituira o usuario referente ao indice */
    rede->vetor[i] = user;
}

void Excluir(TRedeSocial *rede, int i){
    /* Recebe o indice do usuario a ser escolhido, modifica o id desse usuario para -1 e zera a sua linha e coluna, desfazendo as amizades com os outros usuarios */
    rede->vetor[i].ID = -1;
    int linha, coluna;
    for(coluna = 0; coluna < rede->indice; coluna++)
        if(rede->matriz[i][coluna] == 1){
            rede->matriz[i][coluna] = 0;
            rede->matriz[coluna][i] = 0;
        }
}

int RedeVazia(TRedeSocial rede){
    /* Funcao booleana que retorna 1 caso a rede esteja vazia e 0 caso tenha algum usuario cadastrado*/
    if(rede.indice == 0)
        return 1;
    return 0;
}

int RedeCheia(TRedeSocial rede){
    /* Funcao booleana que retorna 1 caso a rede esteja completamente cheia, 0 caso ainda possa ser cadastrado algum usuario*/
    if(rede.indice == 100)
        return 1;
    return 0;
}
