#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void Pause(){
    /* Funcao utilizada para congelar a execucao de codigo */
    printf("\n\n\t>>>>>> MSG: Pressione uma tecla para continuar! <<<<<<\n\n");
    fflush(stdin);
    getchar();
}

void MSG_MENU(){
    printf("\n\n\t>>>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. Modulo 1 - Gerenciamento de usuarios.");
    printf("\n\t2. Modulo 2 - Gerenciamento de amizades.");
    printf("\n\t3. Sair.");
}

void MSG_SUBMENU(int numero_modulo){
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<<<", numero_modulo);
    if(numero_modulo == 1){ // dependendo do modulo escolhido o if exibe as opcoes
        printf("\n\n\t1. Cadastrar.");
        printf("\n\n\t2. Pesquisar.");
        printf("\n\n\t3. Alterar.");
        printf("\n\n\t4. Excluir.");
        printf("\n\n\t5. Imprimir.");
        printf("\n\n\t6. Sair.");
    }
    else{
        printf("\n\n\t1. Cadastrar amizades.");
        printf("\n\n\t2. Pesquisar amizades.");
        printf("\n\n\t3. Excluir amizades.");
        printf("\n\n\t4. Imprimir a lista de amigos.");
        printf("\n\n\t5. Imprimir usuario com mais amigos.");
        printf("\n\n\t6. Amigos em comum entre dois usuarios.");
        printf("\n\n\t7. Matriz de amigos em comum.");
        printf("\n\n\t8. Usuarios que nao tem amigos em comum.");
        printf("\n\n\t9. Relacao indireta de nivel 1.");
        printf("\n\n\t10. Relacao indireta de nivel 2.");
        printf("\n\n\t11. Sair.");
    }
}

void SubMenuModulo1(TRedeSocial *rede, TUsuarios user){
    int opcao = 0;
    do{
        MSG_SUBMENU(1);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
        case 1: // Realizando o cadastro de novos usuarios
            system("cls");
            printf("\n\n\t>>>>>> MSG: Cadastro <<<<<<");
            Ler(&user);
            if(!(RedeCheia(*rede))){ // Verifica se a rede nao esta cheia
                Cadastrar(rede, user);
                printf("\n\n\t>>>>>> MSG: Cadastro realizado com sucesso <<<<<<");
            }
            else
                printf("\n\n\t>>>>>> MSG: A rede esta cheia <<<<<<");
            Pause();
            break;
        case 2: // Pesquisa um usuario baseado no nome
            system("cls");
            printf("\n\n\t>>>>>> MSG: Pesquisar <<<<<<");
            printf("\n\nDigite o nome a ser pesquisado: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            int i = Pesquisar(*rede, user);
            if(i >= 0 && rede->vetor[i].ID >= 0){// verifica se o usuario existe, caso exista imprime os dados dele
                Imprimir(rede->vetor[i]);
                printf("\n\n\t>>>>>> MSG: O usuario pesquisado foi encontrado! <<<<<<\n\n");
            }
            else{
                printf("\n\n\t>>>>>> MSG: O usuario pesquisado nao esta cadastrado! <<<<<<\n\n");
            }
            Pause();
            break;
        case 3: // Altera o cadastro do usuario pesquisado pelo nome
            system("cls");
            printf("\n\n\t>>>>>> MSG: Alterar <<<<<<<<<<");
            printf("\n\nDigite o nome do usuario a ser alterado: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i >= 0){// verifica se o usuario existe, caso exista le os novos dados e altera
                printf("\n\n\t>>>>>> MSG: Digite os dados para alterar: <<<<<<\n\n");
                Ler(&user);
                Alterar(rede, user, i);
                printf("\n\n\t>>>>>> MSG: O usuario foi alterado com sucesso! <<<<<<\n\n");
            }
            else{
                printf("\n\n\t>>>>>> MSG: O usuario pesquisado nao esta cadastrado! <<<<<<\n\n");
            }
            Pause();
            break;
        case 4: // Pesquisa um usuario por nome, encontra seu id e o exclui da rede
            system("cls");
            printf("\n\n\t>>>>>> MSG: Excluir <<<<<<");
            printf("\n\nDigite o nome do usuario a ser excluido: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i >= 0 && rede->vetor[i].ID >= 0){// Caso o usuario exista e nao tenha sido excluido, a funcao excluir e chamada
                Excluir(rede, i);
                printf("\n\n\t>>>>>> MSG: O usuario foi excluido com sucesso! <<<<<<\n\n");
            }
            else{
                printf("\n\n\t>>>>>> MSG: O usuario pesquisado nao esta cadastrado! <<<<<<\n\n");
            }
            Pause();
            break;
        case 5: // Imprime as informacoes de todos os usuarios cadastrados na rede
            system("cls");
            printf("\n\n\t>>>>> MSG: Imprimir <<<<<<<<<<");
            if(!(RedeVazia(*rede))){//Verifica se a rede nao esta vazia
                printf("\n\n\t>>>>>> MSG: Lista de usuarios cadastrados: <<<<<<\n\n");
                Imprimir2(*rede);
            }
            else{
                printf("\n\n\t>>>>>> MSG: Nao existem usuarios cadastrados! <<<<<<\n\n");
            }
            Pause();
            break;
        case 6: // Sai do loop
            system("cls");
            printf("\n\n\t>>>>>> MSG: Saindo do Modulo...!!! <<<<<<");
            Pause();
            break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            Pause();
        }
    }while(opcao != 6);
}

void SubMenuModulo2(TRedeSocial *rede, TUsuarios user){
    int opcao = 0;
    TUsuarios user2;
    do{
        MSG_SUBMENU(2);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
        case 1: // Cadastro de dois usuarios apos verificar se eles existem
            system("cls");
            printf("\n\n\t>>>>> MSG: Cadastro de amizades <<<<<<");
            printf("\n\nPesquise o nome do primeiro usuario: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\nPesquise o nome do segundo usuario: ");
            fflush(stdin);
            fgets(user2.nome, 100, stdin);
            int i = Pesquisar(*rede, user);
            int j = Pesquisar(*rede, user2);
            if(i != j && i >=0 && j >= 0){ // Um usuario nao pode ser amigo dele mesmo e so pode adicionar usuarios existentes
                CadastrarAmizades(rede, rede->vetor[i], rede->vetor[j]);
                printf("\n\n\t>>>>>> MSG: Amizade feita com sucesso. <<<<<<");
            }
            else if(j == i){
                printf("\n\n\t>>>>>> MSG: O usuario nao pode se adicionar. <<<<<<");
            }
            else
                printf("\n\n\t>>>>>> MSG: Um dos usuarios nao foi encontrado. <<<<<<");
            Pause();
            break;
        case 2: // Verifica se dois usuarios sao amigos
            system("cls");
            printf("\n\n\t>>>>> MSG: Pesquisa de amizades <<<<<<");
            printf("\n\nPesquise o nome primeiro usuario: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\nPesquise o nome segundo usuario: ");
            fflush(stdin);
            fgets(user2.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            j = Pesquisar(*rede, user2);
            if(i >= 0 && j >= 0 && i != j){ // um usuario nao pode ser amigo dele mesmo nem de um usuario que foi excluido
                int resultado = PesquisarAmizades(*rede, rede->vetor[i],rede->vetor[j]);
                if(resultado){
                    printf("\n\n\t>>>>>> Existe uma amizade entre esses usuarios <<<<<<");
                }
                else{
                    printf("\n\n\t>>>>>> Nao ha amizade entre esses usuarios <<<<<<");
                }
            }
            else
                printf("\n\n\t>>>>>> MSG: Um dos usuarios nao foi encontrado. <<<<<<");
            Pause();
            break;
        case 3: // Remove a amizade entre dois usuarios
            system("cls");
            printf("\n\n\t>>>>> MSG: Excluir amizades <<<<<<");
            printf("\n\nPesquise o nome primeiro usuario: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\nPesquise o nome segundo usuario: ");
            fflush(stdin);
            fgets(user2.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            j = Pesquisar(*rede, user2);
            if(i >= 0 && j >= 0 && i != j){
                printf("\n\n\t>>>>>> MSG: A amizade foi excluida com sucesso");
                ExcluirAmizades(rede, rede->vetor[i], rede->vetor[j]);
            }
            else
                printf("\n\n\t>>>>>> MSG: Um dos usuarios nao foi encontrado. <<<<<<");
            Pause();
            break;
        case 4:// Imprime todos os amigos de um determinado usuario
            system("cls");
            printf("\n\n\t>>>>> MSG: Imprimir lista de amigos <<<<<<");
            printf("\n\nPesquise o nome primeiro usuario: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            if(i >= 0 && rede->vetor[i].numeros_amigos > 0){
                ImprimirListadeAmigos(*rede, rede->vetor[i]);
            }
            else if(rede->vetor[i].numeros_amigos == 0)
                printf("\n\n\t>>>>>> MSG: O usuario nao possui amigos. <<<<<<");
            else
                printf("\n\n\t>>>>>> MSG: O usuario nao foi encontrado. <<<<<<");
            Pause();
            break;
        case 5://Imprime os dados do usuario que tem mais amigos
            system("cls");
            printf("\n\n\t>>>>> MSG: Usuario com mais amigos <<<<<<");
            int id = MaisAmigos(*rede);
            Imprimir(rede->vetor[id]);
            Pause();
            break;
        case 6:// Imprime a quantidade de amigos entre os 2 usuarios pesquisados
            system("cls");
            printf("\n\n\t>>>>> MSG: Amigos em comum entre 2 usuarios <<<<<<");
            printf("\n\nDigite o nome do primeiro usuario: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\nDigite o nome do segundo usuario: ");
            fflush(stdin);
            fgets(user2.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            j = Pesquisar(*rede, user2);
            if(i == j){
                printf("\n\n\t>>>>> MSG: Nao pode ser a mesma pessoa <<<<<<");
            }
            else if(i >= 0 && j >=0 && !(PesquisarAmizades(*rede, rede->vetor[i], rede->vetor[j]))){ // os usuarios nao podem ser amigos
                printf("\n\n\t>>>>> MSG: Esses usuarios possuem %d amigos em comum <<<<<<", AmigosEmComum(*rede, i, j));
            }
            else
                printf("\n\n\t>>>>> MSG: Usuario nao encontrado <<<<<<");
            Pause();
            break;
        case 7://Imprime a matriz de amigos em comum
            system("cls");
            if(rede->indice > 1){//imprime essa matriz quando a rede social tem mais de 1 pessoa
                printf("\n\n\t>>>>> MSG: Imprimindo matriz de amigos em comum <<<<<<");
                MatrizAmigosEmComum(rede);
            }
            else{
                printf("\n\n\t>>>>> MSG: A rede nao tem usuarios suficientes <<<<<<");
            }
            Pause();
            break;
        case 8://Imprime nome dos dois primeiros usuarios encontrados que nao possuem amigos em comum
            system("cls");
            printf("\n\n\t>>>>> MSG: Imprimindo usuarios que nao possuem amigos em comum <<<<<<");
            if(rede->indice < 2){
                printf("\n\n\t>>>>> MSG: A rede nao possui usuarios suficientes <<<<<<");
            }
            else{
                SemAmigosEmComum(rede);
                printf("\n\nOs usuarios %s e %s nao possuem amigos em comum.", rede->user_escolhidos[0].nome, rede->user_escolhidos[1].nome);
            }
            Pause();
            break;
        case 9://Imprime os dados do usuario intermediario
            system("cls");
            printf("\n\n\t>>>>> MSG: Amizades indiretas nivel 1 <<<<<<");
            printf("\n\nO nome do usuario 1: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\nO nome do usuario 2: ");
            fflush(stdin);
            fgets(user2.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            j = Pesquisar(*rede, user2);
            if(i >= 0 && j >= 0 && i != j && !(PesquisarAmizades(*rede, rede->vetor[i], rede->vetor[j]))){
                id = AmizadesInderetasNivel1(*rede, rede->vetor[i], rede->vetor[j]);
                printf("\n\n\t>>>>> MSG: O usuario intermediario e: <<<<<<");
                Imprimir(rede->vetor[id]);
            }
            else{
                printf("\n\n\t>>>>> MSG: O usuario intermediario nao pode ser encontrado <<<<<<");

            }
            Pause();
            break;
        case 10: // Amizades indiretas de nivel 2
            system("cls");
            printf("\n\n\t>>>>> MSG: Amizades indiretas nivel 2 <<<<<<");
            printf("\n\nO nome do usuario 1: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\nO nome do usuario 2: ");
            fflush(stdin);
            fgets(user2.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            j = Pesquisar(*rede, user2);
            if(i >= 0 && j >= 0 &&!(PesquisarAmizades(*rede, rede->vetor[i], rede->vetor[j]))){
                AmizadesInderetasNivel2(rede, rede->vetor[i], rede->vetor[j]);
                printf("\n\n\t>>>>> MSG: Usuarios intermediarios: <<<<<<");
                Imprimir(rede->user_escolhidos[0]);
                Imprimir(rede->user_escolhidos[1]);
            }
            else{
                printf("\n\n\t>>>>> MSG: Os usuarios intermediarios nao puderam ser encontrados <<<<<<");
            }
            Pause();
            break;
        case 11:// Encerra loop
            system("cls");
            printf("\n\n\t>>>>> MSG: Saindo do Modulo...!!! <<<<<<");
            Pause();
            break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            Pause();
        }
    }while(opcao != 11);
}

