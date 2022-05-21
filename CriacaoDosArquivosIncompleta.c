#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>


int MenuInicial();
int iniciar();
int continuar();
void sair();
int MenuRodadas();
int NovaRodada();
int Salvar_Sair();

int semestre=1;
//fun��o principal
int main (){
    /////
    setlocale (LC_ALL,"Portuguese");

    int x = MenuInicial();

    if (x==1){
    	iniciar();
    	int opcaoDoJogador = MenuRodadas();
    	
        while(opcaoDoJogador!=3){
            if(opcaoDoJogador ==1 && semestre <=8){
                NovaRodada();
                //Fica chamando o NovaRodada toda vez
                opcaoDoJogador = MenuRodadas();
                semestre++;
            }
        }
    
        if(x==2)

            Salvar_Sair();
        
        else
            sair();
            
    	
	}
	else{
		if(x==2)
			continuar();
            
		else
			sair();
	}
    return 0;
}



 //Menu Inicial
int MenuInicial(){
    int EscolhaJogador;
        fprintf(stdout,"1 - Iniciar 2 - Continuar 3 - sair\n");
        fprintf(stdout,"Digite sua escolha: ");
        scanf("%d", &EscolhaJogador); 
        if(EscolhaJogador == 1 || EscolhaJogador == 2 || EscolhaJogador == 3)
            return EscolhaJogador;
        if(EscolhaJogador < 1 || EscolhaJogador > 3){
            do{
                fprintf(stdout,"Valor incorreto, digite novamente!\n");
                fprintf(stdout,"Digite sua escolha: ");
                scanf("%d", &EscolhaJogador);
            }while(EscolhaJogador < 1 || EscolhaJogador > 3);
        }   
    return EscolhaJogador;
}

    //funcao para verificar se o valor inserido é um caractere ou não
int ehCaracter(char letra){
    if (((int) letra) >= 65 && ((int) letra) <= 90)
        return 1;
    else if (((int) letra) >= 97 && ((int) letra) <= 122)
        return 1;
    return 0;
}
    //funcao que verifica se o valor inserido é valido ou não
int ehNomeValido(char*nomeUsuario){

    for(int i =0;i<strlen(nomeUsuario);i++){
        if (!ehCaracter(nomeUsuario[i])){
        printf("O nome inserido não é valido, informe outro nome: ");
            return 0;
        }
    }
    return 1;
}

int CriarArquivoUsuario(int ConfirmacaoNome,char NomeUsuario[256]){
    FILE *TestandoNomeUsuario;
    FILE *arq_usuario;

    if(ConfirmacaoNome==1){
            strcat(NomeUsuario,".txt");
            TestandoNomeUsuario=fopen(NomeUsuario,"r");
        if(TestandoNomeUsuario != NULL){
            do{
             printf("Digite outro nome: ");
             scanf("%s", NomeUsuario);
             strcat(NomeUsuario,".txt");
            
             TestandoNomeUsuario=fopen(NomeUsuario,"r");
             if(TestandoNomeUsuario== NULL){
                printf("TestandoNomeUsuario não abriu um arquivo");
                break;
             }
            }while(TestandoNomeUsuario != NULL);
        }
        //Criacao do arquivo utilizando o nome do usuario
        arq_usuario=fopen(NomeUsuario,"w+");
        }
    
    else if(ConfirmacaoNome==2){
        printf("Iniciando Novamente!\n");
        iniciar();
}
    return 0;
}
//Fun��o Iniciar
int iniciar(){

	char NomeUsuario[256];
	int ConfirmacaoDoNomeUsuario;
	

	printf("Seja Bem - Vindo(a)!!! Digite seu nome de usu�rio: ");
    scanf("%s", NomeUsuario);
    
    while(!ehNomeValido(NomeUsuario))
        scanf("%s", NomeUsuario);
        
    printf("Seu nome de usuario �: %s ", NomeUsuario);
    printf("\n Podemos confirmar?! \n 1 - sim  2 - nao\n");
    printf("Digite sua escolha: ");
    scanf("%d", &ConfirmacaoDoNomeUsuario);

   	while(ConfirmacaoDoNomeUsuario != 1 && ConfirmacaoDoNomeUsuario != 2){
	 	printf("Valor incorreto, digite novamente\n");
	 	scanf("%d", &ConfirmacaoDoNomeUsuario);
	}
    CriarArquivoUsuario(ConfirmacaoDoNomeUsuario,NomeUsuario);
    return 0;
}

int continuar(){
    char NomeJogadorContinuar[256];
    FILE *Continuar;
    printf("Digite o Nome do Jogador: ");
    scanf("%s",NomeJogadorContinuar);
    strcat(NomeJogadorContinuar,".txt");
    Continuar = fopen(NomeJogadorContinuar,"r");
    if(Continuar == NULL){
        printf("Jogador não encontrado!\n");
        continuar();
    }
    NovaRodada();
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

int QuantidadeRodada(int QuantasRodadasForam){

    return 0;
}

//EM ANDAMENTO --- N�O EST� PRONTO
int NovaRodada(){
    int tabuleiro[8][4], cont=0;
    int i,j;
    
    for(i=0;i<8;i++){
        for(j=0;j<4;j++){
        	cont++;
            tabuleiro[i][j]=cont;
        }
     }

    //pegar semestre, pontua��o e rodada
	int dado;//pontuacao;
	int situacao;

	srand(time(NULL));
	
	dado = rand()%4;
	//FAZENDO O DADO N�O CAIR EM NUMEROS QUE N�O V�O EXISTIR
	while(dado==4){
        dado = rand()%4;
	}
	
	//Pesquisando no Arquivo 
	
	FILE * ArquivoSituacoes;


	ArquivoSituacoes=fopen("situacoes.txt","r");
	
	if(ArquivoSituacoes!=NULL){
		char texto_situacao[300];
		char string;
		
		//	POSI��O DO PERSONAGEM NO TABULEIRO
		situacao=tabuleiro[semestre][dado]; 
		
		setlocale (LC_ALL,"Portuguese");

		
		int ComparadorIndicador=0; //numero em que sera realizada a compara��o com situa��o
		//percorre todo o arquivo
		while((string = fgetc(ArquivoSituacoes)) != EOF){
			fscanf(ArquivoSituacoes, "%d", &ComparadorIndicador); //procurando o id da situa��o no arquivo
			
			int i = -1;//contador do vetor
			
			if(ComparadorIndicador==situacao){///quando id da situa��o for entrado, fa�a:
				//situacao++;
				
				//escrevendo situa��o e suas alternativas, caso haja uma "|'
				do{
					i++;
					fscanf(ArquivoSituacoes, "%c", &texto_situacao[i]);
					printf("%c", texto_situacao[i]);
					
				}while(texto_situacao[i] != '|' );
				printf("\n"); //Quebra de linha após a entrada da situação
				
				//lendo pelo tamanho do texto situa��o
				/*for(i=0;i<256;i++){
					fscanf(ArquivoSituacoes, "%c", &texto_situacao[i]);
					fprintf(stdout, "%c", texto_situacao[i]);
					
				}*/
			}
        }

        int QuantidadeDeRodada=0;
        QuantidadeRodada(QuantidadeDeRodada);
        QuantidadeDeRodada++;

    }
    return 0;  
}

void sair(){
    exit(0);
}

//N�O TA PRONTO....FALTA ARQUIVO
int Salvar_Sair(){
    return 0;
}
