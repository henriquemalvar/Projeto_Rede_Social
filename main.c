#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

/* A main inicializa a rede social chamando a funcao iniciar e da inicio ao loop responsavel pelo menu.*/
int main()
{
    TUsuarios user;
    TRedeSocial rede;
    Iniciar(&rede);
    int opcao = 0;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            SubMenuModulo1(&rede, user);
            break;
        case 2:
            SubMenuModulo2(&rede, user);
            break;
        case 3:
            break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Saindo do programa...!!! <<<<<<""");
            fflush(stdin);
            getchar();
        }
    }while(opcao != 3);

    return 0;
}
