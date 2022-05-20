#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

/* escrever as situa��oes e os ids de cada uma delas em arquivo .csv
cada linha vai ter uma situa��o
determinar um limitador para saber onde para a situa��o e onde come�a ou n�o as op��es
*/


int MenuInicial();
int iniciar();
int continuar();
void sair();
int MenuRodadas();
int NovaRodada();
int Salvar_Sair();

//fun��o principal
int main (){

    //criando tabuleiro
    int tabuleiro[8][4], cont=0;
     for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
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
        if(TestandoNomeUsuario == NULL)
            printf("O ARQUIVO SERÁ CRIADO\n");
        else{

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

//Menu que aparecer� ao final de cada rodade
int MenuRodadas(){

	int EscolhaJogador;

    do{
        fprintf(stdout,"\n 1 - Nova Rodada, 2 - Salvar e sair 3 - Sair\n");
        fprintf(stdout,"LEMBRE-SE: a opcao 3 nao salvara o seu percurso at� aqui \n");
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


//EM ANDAMENTO --- N�O EST� PRONTO
int NovaRodada(int tabuleiro[8][4]){

    //pegar semestre, pontua��o e rodada
	int dado, semestre,pontuacao,situacao;

	srand(time(NULL));



	while(dado!=0&&dado!=5){
        dado = rand()%5;
	}

    situacao=tabuleiro[semestre][dado];

    //puxar situa��o do arquivo
    return 0;
}

//N�O TA PRONTO....FALTA ARQUIVO
int Salvar_Sair(){
    return(0);
}
