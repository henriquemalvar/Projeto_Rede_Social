#ifndef AMIZADES_H_INCLUDED
#define AMIZADES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

void CadastrarAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB);
int PesquisarAmizades(TRedeSocial rede,TUsuarios userA, TUsuarios userB);
void ExcluirAmizades(TRedeSocial *rede,TUsuarios userA, TUsuarios userB);
void ImprimirListadeAmigos(TRedeSocial rede, TUsuarios user);

#endif
