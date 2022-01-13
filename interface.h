#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

void MSG_MENU();
void MSG_SUBMENU(int numero_modulo);
void SubMenuModulo1(TRedeSocial *rede, TUsuarios user);
void SubMenuModulo2(TRedeSocial *rede, TUsuarios user);

#endif
