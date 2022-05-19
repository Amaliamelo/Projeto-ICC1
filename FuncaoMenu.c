#include <stdio.h>
int menu();


//função principal
int main (){
    int x = menu();
    printf("Você escolheu %d\n", x);
    if (x==1){
    	inciar();
	}
	else{
		if(x==2){
			continuar();
		}
		else{
			sair();
		}
	}

    return 0;
}
 
 //Menu 1 
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

//Função Iniciar
int iniciar(){
	
	char nome;
	char nome_confirmado;
	int confirmacao;
	FILE * arq_usuario;
	
	printf("Seja Bem - Vindo(a)!!! Digite seu nome de usuário:");
    scanf(" %s", &nome);
    
    printf("\n Seu nome de usuario é: %s", nome);
    printf("\n Podemos confirmar?! \n 1 - sim  2 - nao");
   	while(confirmacao != 1 || confirmacao != 2){
	 	printf("Valor incorreto, digite novamente\n");
	 	scanf("%d", &confirmacao);
	}
    
    
    if(confirmacao==1){
    	if ( arq_usuario=fopen("usuario","r") )
			{
			while ( !feof(ArqIn) )
			{
			fscanf(ArqIn,"%c",&caracter);
			printf("%c",caracter);
			}
			fclose(ArqIn);
			}
			else printf ("Erro na leitura do arquivo de entrada!")
	}
	else{
		
	}
}
