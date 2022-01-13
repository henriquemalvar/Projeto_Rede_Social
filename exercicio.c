#include <stdio.h>
#include <stdlib.h>

#include "exercicio.h"


int MaisAmigos(TRedeSocial rede){
    /* Recebe a rede social e compara o numero de amigos entre os usuarios e retorna o id do usuario que possui mais amigos */
    TUsuarios userA;
    int maior = -1;
    int id;
    for(int i = 0; i <= rede.indice; i++){
        userA = rede.vetor[i];
        if(userA.numeros_amigos > maior){
            maior = userA.numeros_amigos;
            id = userA.ID;
        }
    }
    return id;
}

int AmigosEmComum(TRedeSocial rede, int id_user_A, int id_user_B){
    /* Recebe uma rede e id de dois usuarios, usuario A e usuario B, analisando a linha, do usuario A e do usuario B, na matriz de amizade e caso as duas linhas tenham amizade com a mesma coluna
    essa coluna é um amigo em comum entre os dois, apos isso e incrementado no contador e retornado ao fim da funcao */
    int contador = 0;
    for(int i = 0; i <= rede.indice; i++)
        if(PesquisarAmizades(rede, rede.vetor[id_user_A], rede.vetor[i]) && PesquisarAmizades(rede, rede.vetor[id_user_B], rede.vetor[i]))
            contador++;
    return contador;
}

void MatrizAmigosEmComum(TRedeSocial *rede){
    /* Recebe uma rede social, por referencia, e modifica a matriz_amigos_em_comum colocando a quantidade de amigos em comum no elemento da matriz, usando a funcao AmigosEmComum()*/
    for(int i = 0; i < rede->indice; i++){
        printf("\n");
            for(int j = 0; j < rede->indice; j++){
                if(i != j){
                   rede->matriz_amigos_em_comum[i][j] = AmigosEmComum(*rede, i, j);
                   rede->matriz_amigos_em_comum[j][i] = AmigosEmComum(*rede, i, j);
                }
                else
                    rede->matriz_amigos_em_comum[i][j] = 0;
                printf("%d ", rede->matriz_amigos_em_comum[i][j]);
            }
    }
}

void SemAmigosEmComum(TRedeSocial *rede){
    /* Recebe a rede por referencia e encontra 2 usuarios que nao possuem amigos em comum, exibe os dois usuarios nessa condicao que foram encontrados primeiro e os retorna por referencia*/
    for(int i = 0; i < rede->indice; i++){
        for(int j = 0; j < rede->indice; j++){
            if(rede->matriz_amigos_em_comum[i][j] == 0 && i != j){
                rede->user_escolhidos[0] = rede->vetor[i];
                rede->user_escolhidos[1] = rede->vetor[j];
                return 0;
            }
        }
    }
}

int AmizadesInderetasNivel1(TRedeSocial rede, TUsuarios userA, TUsuarios userB){
    /* Recebe a rede e dois usuarios A e B que nao sao amigos, encontra um usuario que seja amigo em comum com A e com B e retorna o id desse usuario*/
    for(int i = 0; i <= rede.indice; i++)
        if(PesquisarAmizades(rede, rede.vetor[userA.ID], rede.vetor[i]) && PesquisarAmizades(rede, rede.vetor[userB.ID], rede.vetor[i]))
            return rede.vetor[i].ID;
}

void AmizadesInderetasNivel2(TRedeSocial *rede, TUsuarios userA, TUsuarios userB){
    /* Recebe a rede e dois usuarios A e B que nao sao amigos, encontra dois usuarios que sejam amigos, porem um deles e amigos de A e outro de B e retorna esses dois por referencia*/
    int count = 0;
    int idC, idD;
    for(int i = 0; i <= rede->indice; i++){
        if(PesquisarAmizades(*rede, userA, rede->vetor[i]) && !(PesquisarAmizades(*rede, userB, rede->vetor[i])))
            rede->user_escolhidos[0] = rede->vetor[i];
        for(int j = 0; j <= rede->indice; j++){
            if(PesquisarAmizades(*rede, userB, rede->vetor[j]) && !(PesquisarAmizades(*rede, userA, rede->vetor[j])) && PesquisarAmizades(*rede, rede->user_escolhidos[0], rede->vetor[j])){
                rede->user_escolhidos[1] = rede->vetor[j];
                return 0;
            }
        }
    }
}
