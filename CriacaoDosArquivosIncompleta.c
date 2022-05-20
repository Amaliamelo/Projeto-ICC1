#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

/* escrever as situaçãoes e os ids de cada uma delas em arquivo .csv
cada linha vai ter uma situação
determinar um limitador para saber onde para a situação e onde começa ou não as opções
*/


int MenuInicial();
int iniciar();
int continuar();
void sair();
int MenuRodadas();
int NovaRodada();
int Salvar_Sair();

//função principal
int main (){

    //criando tabuleiro
    int tabuleiro[8][4], cont=0;
    int i,j;
    
    for(i=0;i<8;i++){
        for(j=0;j<4;j++){
            tabuleiro[i][j]=cont++;
        }
     }
    /////
    setlocale (LC_ALL,"Portuguese");

    int x = MenuInicial();

    if (x==1){
    	iniciar();
    	int op = MenuRodadas();
    	if(op==1){
            NovaRodada(tabuleiro);
    	}else{
    	    if(x==2){
                Salvar_Sair();
            }
            else{
                sair();
            }
    	}
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
        fprintf(stdout,"1 - Iniciar 2 - Continuar 3 - sair\n");
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

    //verificando se o nome está de acordo com o que o usuario quer
    while(ConfirmacaoDoNomeUsuario != 1){
            printf("Informe um novo nome: \n");
            scanf("%s", NomeUsuario);
            printf("\n Podemos confirmar?! \n 1 - sim  2 - nao\n");
            scanf("%d", &ConfirmacaoDoNomeUsuario);

    }
    /////////

    //Verificando se a confirmação é valida
   	while(ConfirmacaoDoNomeUsuario != 1 && ConfirmacaoDoNomeUsuario != 2){
	 	printf("Valor incorreto, digite novamente\n");
	 	scanf("%d", &ConfirmacaoDoNomeUsuario);
	}
	//////


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
    return ;
}

int continuar(){
    return 0;
}

void sair(){
    exit(0);
}

//Menu que aparecerá ao final de cada rodade
int MenuRodadas(){

	int EscolhaJogador;

    do{
        fprintf(stdout,"\n 1 - Nova Rodada, 2 - Salvar e sair 3 - Sair\n");
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
int NovaRodada(int tabuleiro[8][4]){

    //pegar semestre, pontuação e rodada
	int dado, semestre =1 ,pontuacao;
	int situacao;

	srand(time(NULL));
	
	dado = rand()%5;
	//FAZENDO O DADO NÃO CAIR EM NUMEROS QUE NÃO VÃO EXISTIR
	while(dado==0||dado==5){
        dado = rand()%5;
	}
	
	//Pesquisando no Arquivo 
	
	FILE * ArquivoSituacoes;


	ArquivoSituacoes=fopen("situacoes.txt","r");
	
	if(ArquivoSituacoes!=NULL){
		char texto_situacao[256];
		char string;
		
		//	POSIÇÃO DO PERSONAGEM NO TABULEIRO
		situacao=tabuleiro[semestre][dado]; 
		
		//strcpy(situacao,strcat("",""));
		
		//percorre todo o arquivo
		while((string = fgetc(ArquivoSituacoes)) != EOF){
			if(string == strcpy(situacao,strcat("",""))){
				fscanf(ArquivoSituacoes, "%s", &texto_situacao);
			}
		}
		
		fprintf(stdout,"%s", texto_situacao);
		
	}
   
}

//NÃO TA PRONTO....FALTA ARQUIVO
int Salvar_Sair(){
    return(0);
}
