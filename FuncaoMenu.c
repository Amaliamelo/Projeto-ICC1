#include <stdio.h>
int menu();

int main (){
    int x = menu();
    printf("Você escolheu %d\n", x);


    return 0;
}
 
int menu(){
    int EscolhaJogador;
    do{
        fprintf(stdout,"1 - Iniciar, 2 - Continuar, 3 - sair\n");
        fprintf(stdout,"Digite sua escolha: ");
        scanf("%d", &EscolhaJogador);
        if(EscolhaJogador == 1 || EscolhaJogador == 2 || EscolhaJogador == 3)
            return EscolhaJogador;
        if(EscolhaJogador < 1 || EscolhaJogador > 3)
        fprintf(stdout,"Valor incorreto, digite novamente\n");
        break;
            
    }while(EscolhaJogador != 3);
    return 0;
}