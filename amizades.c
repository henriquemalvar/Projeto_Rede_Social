#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "amizades.h"

void CadastrarAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB){
    int i = userA.ID;
    int j = userB.ID;
    rede->matriz[i][j] = 1;
    rede->matriz[j][i] = 1;
    rede->vetor[i].numeros_amigos++;
    rede->vetor[j].numeros_amigos++;
}

int PesquisarAmizades(TRedeSocial rede, TUsuarios userA, TUsuarios userB){
    int i = userA.ID;
    int j = userB.ID;
    return rede.matriz[i][j];
}

void ExcluirAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB){
    int i = userA.ID;
    int j = userB.ID;
    rede->matriz[i][j] = 0;
    rede->matriz[j][i] = 0;

    rede->vetor[i].numeros_amigos--;
    rede->vetor[j].numeros_amigos--;
}

void ImprimirListadeAmigos(TRedeSocial rede, TUsuarios user){
    int i;
    for(i = 0; i < rede.indice; i++)
        if(PesquisarAmizades(rede, user, rede.vetor[i]))
            Imprimir(rede.vetor[i]);

}
