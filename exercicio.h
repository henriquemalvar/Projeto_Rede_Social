#ifndef EXERCICIO_H_INCLUDED
#define EXERCICIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

int MaisAmigos(TRedeSocial rede);
int AmigosEmComum(TRedeSocial rede, int id_user_A, int id_user_B);
void MatrizAmigosEmComum(TRedeSocial *rede);
void SemAmigosEmComum(TRedeSocial *rede);
int AmizadesInderetasNivel1(TRedeSocial rede, TUsuarios userA, TUsuarios userB);
void AmizadesInderetasNivel2(TRedeSocial *rede, TUsuarios userA, TUsuarios userB);

#endif

