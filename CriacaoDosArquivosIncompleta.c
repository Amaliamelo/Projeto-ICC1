#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



int MenuInicial();
int iniciar();
int continuar();
void sair();
int MenuRodadas();
int NovaRodada();
//função principal
int main (){
    int x = MenuInicial();
    printf("Você escolheu %d\n", x);
    if (x==1){
    	iniciar();
    	MenuRodadas();
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

 //Menu Inicial
int MenuInicial(){
    /* Funcao Menu, nao recebe valor e retorna a escolha que o jogador realizar
    pode ser: iniciar, continuar,sair
    */
    int EscolhaJogador;
    do{
        fprintf(stdout,"1 - Iniciar, 2 - Continuar, 3 - sair\n");
        fprintf(stdout,"Digite sua escolha: ");
        scanf("%d", &EscolhaJogador); //armazenando a escolha
        if(EscolhaJogador == 1 || EscolhaJogador == 2 || EscolhaJogador == 3)
            // se a escolha for correta, retorna ela
            return EscolhaJogador;
        if(EscolhaJogador < 1 || EscolhaJogador > 3)
        // se for incorreta, entra no loop ate ser digitada corretamente
        fprintf(stdout,"Valor incorreto, digite novamente\n");
        break;

    }while(EscolhaJogador != 3);
    return 0;
}

//Função Iniciar
int iniciar(){

	char NomeUsuario[256];
	char nome_confirmado[256];
	int ConfirmacaoDoNomeUsuario;
	FILE * arq_usuario;

	printf("Seja Bem - Vindo(a)!!! Digite seu nome de usuário: ");
    scanf("%s", NomeUsuario);

    printf("Seu nome de usuario é: %s ", NomeUsuario);
    printf("\n Podemos confirmar?! \n 1 - sim  2 - nao\n");
    scanf("%d", &ConfirmacaoDoNomeUsuario);

   	while(ConfirmacaoDoNomeUsuario != 1 && ConfirmacaoDoNomeUsuario != 2){
	 	printf("Valor incorreto, digite novamente\n");
	 	scanf("%d", &ConfirmacaoDoNomeUsuario);
	}
	//criacao do Id do usuario para evitar repeticoes
	/*int IdUsuario = 10;
    char IdUsuarioChar = (IdUsuario + '0');
    printf("%s",IdUsuarioChar);*/
    FILE *ArquivoUsuarioBase, *ArquivoUsuarioUnico;
    int ContadorUsuarios = 1;
    char player[256];
    if(ConfirmacaoDoNomeUsuario==1){
		/*
            ArquivoUsuarioBase=fopen("BaseUsuarios.txt","w+");

            if(ArquivoUsuarioBase == NULL){
                printf("Deu ruim ao abrir o ArquivoUsuarioBase\n");
                exit(0);
            }

            fseek(ArquivoUsuarioBase,0,SEEK_SET);
            fprintf(ArquivoUsuarioBase,"UltimoUsuario = %d\n", ContadorUsuarios);
            fprintf(ArquivoUsuarioBase,"Primeiro Usuario = 1\n");
            fprintf(ArquivoUsuarioBase,"player_\n");
            fclose(ArquivoUsuarioBase);
            //TESTANDO AINDA
            strcat("player_",ContadorUsuarios);
            arq_usuario=fopen(nome_confirmado,"w+");

            ArquivoUsuarioUnico=open(player_%d,"w+");
                //FIM FASE DE TESTE
       */
        //Criacao do arquivo utilizando o nome do usuario

            strcpy(nome_confirmado,strcat(NomeUsuario,".txt"));
            arq_usuario=fopen(nome_confirmado,"w+");

            if(arq_usuario == NULL){
                printf("Deu ruim ao abrir o arquivo usuario\n");
                exit(0);
            }

        //FIM DO BLOCO DO ARQUIVO


        /*
        Testando o arquivo, leitura e escrita
        NÃO RETIRA O FSEEK, POR FAVOR
        Esse bloco foi para teste do arquivo
        */

        /*char testando[256];
        fprintf(arq_usuario,"%s","CafeÉLindo");
        fseek(arq_usuario,0,SEEK_SET);
        fscanf(arq_usuario,"%s",testando);
        printf("%s",testando);
        fclose(arq_usuario);*/
        // FIM DO BLOCO DE TESTE
    }
	else{

	}

    return ;
}

int continuar(){
    return 0;
}

void sair(){
    exit(0);
}

int MenuRodadas(){

	int EscolhaJogador;

    do{
        fprintf(stdout,"1 - Nova Rodada, 2 - Salvar e sair, 3 - Sair\n");
        fprintf(stdout,"LEMBRE-SE: a opcao 3 nao salvara o seu percurso até aqui \n");
        fprintf(stdout,"\n Digite sua escolha: ");
        scanf("%d", &EscolhaJogador); //armazenando a escolha
        if(EscolhaJogador == 1 || EscolhaJogador == 2 || EscolhaJogador == 3)
            // se a escolha for correta, retorna ela
            return EscolhaJogador;
        if(EscolhaJogador < 1 || EscolhaJogador > 3)
        // se for incorreta, entra no loop ate ser digitada corretamente
        fprintf(stdout,"Valor incorreto, digite novamente\n");
        break;

    }while(EscolhaJogador != 3);

    return 0;

}
//EM ANDAMENTO --- NÃO ESTÁ PRONTO
int NovaRodada(){

	int dado;

	srand(time(NULL));

	dado = rand()%7;
}
