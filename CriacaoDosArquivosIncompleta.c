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
        	cont++;
            tabuleiro[i][j]=cont;
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

   	while(ConfirmacaoDoNomeUsuario != 1 && ConfirmacaoDoNomeUsuario != 2){
	 	printf("Valor incorreto, digite novamente\n");
	 	scanf("%d", &ConfirmacaoDoNomeUsuario);
	}

    FILE *TestandoNomeUsuario;

    if(ConfirmacaoDoNomeUsuario==1){
            /*
                Criacao dos arquivos e vereficação de repetição realizada
                parte de arquivos dos usuarios está pronta
                falta: Revisionar com os membros do grupo e upar pra main
            */
            strcat(NomeUsuario,".txt");
            strcpy(nome_confirmado,NomeUsuario);
            TestandoNomeUsuario=fopen(nome_confirmado,"r");
        if(TestandoNomeUsuario != NULL){
            do{
             printf("Digite outro nome: ");
             scanf("%s", NomeUsuario);
             strcat(NomeUsuario,".txt");
             strcpy(nome_confirmado,NomeUsuario);
             TestandoNomeUsuario=fopen(nome_confirmado,"r");
             if(TestandoNomeUsuario== NULL)
                break;
            }while(TestandoNomeUsuario != NULL);
        }
        //Criacao do arquivo utilizando o nome do usuario
            arq_usuario=fopen(nome_confirmado,"w+");


            arq_usuario=fopen(nome_confirmado,"w+");

            if(arq_usuario == NULL){
                printf("Deu ruim ao abrir o arquivo usuario\n");
                exit(0);
            }

    }
	else{

	}

    return 0;
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
	int dado, semestre = 1 ,pontuacao;
	int situacao;

	srand(time(NULL));
	
	dado = rand()%4;
	//FAZENDO O DADO NÃO CAIR EM NUMEROS QUE NÃO VÃO EXISTIR
	while(dado==4){
        dado = rand()%4;
	}
	
	//Pesquisando no Arquivo 
	
	FILE * ArquivoSituacoes;


	ArquivoSituacoes=fopen("situacoes.txt","r");
	
	if(ArquivoSituacoes!=NULL){
		char texto_situacao[256];
		char string;
		
		//	POSIÇÃO DO PERSONAGEM NO TABULEIRO
		situacao=tabuleiro[semestre][2]; 

		
		int ComparadorIndicador=0; //numero em que sera realizada a comparação com situação
		//percorre todo o arquivo
		while((string = fgetc(ArquivoSituacoes)) != EOF){
		
			//setlocale (LC_ALL,"Portuguese");

			fscanf(ArquivoSituacoes, "%d", &ComparadorIndicador);
			int i =0;
			if(ComparadorIndicador==situacao){
				//situacao++;
				
				//escrevendo situação e suas alternativas, caso hour ---PROBLEMAA---
				while(texto_situacao[i]!=","){
					fscanf(ArquivoSituacoes, "%c", &texto_situacao[i]);
					fprintf(stdout, "%c", texto_situacao[i]);
					i++;
				}
			
                 
				break;
			}

		}
		
	}
   
}

//NÃO TA PRONTO....FALTA ARQUIVO
int Salvar_Sair(){
    return(0);
}
