#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int MenuInicial();
int iniciar();
int continuar();
void sair();
int MenuRodadas();
int NovaRodada();
int Salvar_Sair();
int CriarArquivoUsuario();
int escolhaSituacao();
int jogoInteiro();

char NomeUsuario[256];
int semestre = 0, pontuacao = 0, quantidadeRodadas = 0;
// fun��o principal
int main() {
    /////
    setlocale(LC_ALL, "Portuguese");

    int x = MenuInicial();

    if (x == 1) {
        iniciar();
        int opcaoDoJogador = MenuRodadas();

        if (opcaoDoJogador == 1)
            jogoInteiro();
        if (opcaoDoJogador == 2)
            Salvar_Sair();
        else
            sair();
    }
    else {
        if(x == 2)
            continuar();

        else
            sair();
    }
    return 0;
}
int jogoInteiro(){
    printf("\nsemestre: %d\n",semestre);
    NovaRodada();
    int escolha=0;
    for(int i=0;i<=7;i++){
        escolha = MenuRodadas();
        if(escolha == 1){
                printf("\nsemestre: %d\n",semestre);
            NovaRodada();
        }
        else if(escolha == 2){
            //pq tem isso:??????????
            printf("Jogo salvo, ate a proxima!\n");
            sair();
        }
        else if(escolha == 3){
                printf("Obrigado por jogar.. Ate a proxima!! :)\n");
            sair();
        }
    }
}

int iniciar() {
    int ConfirmacaoDoNomeUsuario;

    printf("Seja Bem - Vindo(a)!!! Digite seu nome de usuario: ");
    scanf("%s", NomeUsuario);

    while (!ehNomeValido(NomeUsuario))
        scanf("%s", NomeUsuario);

    printf("Seu nome de usuario eh: %s ", NomeUsuario);
    printf("\n Podemos confirmar?! \n 1 - sim  2 - nao\n");
    printf("Digite sua escolha: ");
    scanf("%d", &ConfirmacaoDoNomeUsuario);

    while (ConfirmacaoDoNomeUsuario != 1 && ConfirmacaoDoNomeUsuario != 2) {
        printf("Valor incorreto, digite novamente\n");
        scanf("%d", &ConfirmacaoDoNomeUsuario);
    }
    CriarArquivoUsuario(ConfirmacaoDoNomeUsuario, NomeUsuario);
    FILE *ArquivoUsuario;
    ArquivoUsuario = fopen(NomeUsuario, "w+");
    fprintf(ArquivoUsuario, "Semestre: %d\nPontuacao: %d\nQuantidadeRodadas: %d\n", semestre,pontuacao, quantidadeRodadas);
    fclose(ArquivoUsuario);
    return 0;
}

int CriarArquivoUsuario(int ConfirmacaoNome, char NomeUsuario[256]) {
    FILE *TestandoNomeUsuario;
    FILE *arq_usuario;

    if (ConfirmacaoNome == 1) {
        strcat(NomeUsuario, ".txt");
        TestandoNomeUsuario = fopen(NomeUsuario, "r");
        if (TestandoNomeUsuario != NULL) {
            do {
                printf("Digite outro nome: ");
                scanf("%s", NomeUsuario);
                strcat(NomeUsuario, ".txt");

                TestandoNomeUsuario = fopen(NomeUsuario, "r");
            } while (TestandoNomeUsuario != NULL);
        }
        // Criacao do arquivo utilizando o nome do usuario
        arq_usuario = fopen(NomeUsuario, "w");

    }

    else if (ConfirmacaoNome != 1) {
        printf("Iniciando Novamente!\n");
        iniciar();
    }
    return 0;
}

// Menu Inicial
int MenuInicial() {
    int EscolhaJogador;
    fprintf(stdout, "1 - Iniciar 2 - Continuar 3 - sair\n");
    fprintf(stdout, "Digite sua escolha: ");
    scanf("%d", &EscolhaJogador);
    if (EscolhaJogador == 1 || EscolhaJogador == 2 || EscolhaJogador == 3)
        return EscolhaJogador;
    do {
        fprintf(stdout, "Valor incorreto, digite novamente!\n");
        fprintf(stdout, "Digite sua escolha: ");
        scanf("%d", &EscolhaJogador);
    } while (EscolhaJogador < 1 || EscolhaJogador > 3);

    return EscolhaJogador;
}

// funcao para verificar se o valor inserido é um caractere ou não
int ehCaracter(char letra) {
    if (((int)letra) >= 65 && ((int)letra) <= 90)
        return 1;
    else if (((int)letra) >= 97 && ((int)letra) <= 122)
        return 1;
    return 0;
}

int ehNomeValido(char *nomeUsuario) {
    for (int i = 0; i < strlen(nomeUsuario); i++) {
        if (!ehCaracter(nomeUsuario[i])) {
            printf("O nome inserido não é valido, informe outro nome: ");
            return 0;
        }
    }
    return 1;
}

int continuar() {
    FILE *continuarArquivo;
    printf("Digite o Nome do Jogador: ");
    scanf("%s", NomeUsuario);
    strcat(NomeUsuario, ".txt");
    continuarArquivo = fopen(NomeUsuario, "r");
    if (continuarArquivo == NULL) {
        printf("Jogador não encontrado!\n");
        continuar();
    }
    fscanf(continuarArquivo,"%d %d %d",&semestre,&pontuacao,&quantidadeRodadas);
    fclose(continuarArquivo);
    int opcaoDoJogador = MenuRodadas();
    if (opcaoDoJogador == 1)
        jogoInteiro();

    if (opcaoDoJogador == 2)
        Salvar_Sair();
    if (opcaoDoJogador == 3)
        sair();
}

int MenuRodadas() {

    int EscolhaJogador;

    do {
        fprintf(stdout, "\n 1 - Nova Rodada, 2 - Salvar e sair 3 - Sair\n");
        fprintf(stdout, "LEMBRE-SE: a opcao 3 nao salvara o seu percurso at� aqui \n");
        fprintf(stdout, "\n Digite sua escolha: ");
        scanf("%d", &EscolhaJogador);
        if (EscolhaJogador == 1 || EscolhaJogador == 2 || EscolhaJogador == 3)
            return EscolhaJogador;
        if (EscolhaJogador < 1 || EscolhaJogador > 3)
            fprintf(stdout, "Valor incorreto, digite novamente\n");
        break;
    } while (EscolhaJogador != 3);
    return 0;
}

int escolhaJogadorRodada(){

}

// EM ANDAMENTO --- N�O EST� PRONTO
int escolhaSituacao(){
    int dadosituacao;
    char escolhaJogadorSituacao;
    scanf("%s",&escolhaJogadorSituacao);
    srand(time(NULL));

    dadosituacao = rand() % 10;//para situacoes que precisam de um novo rand
    if(escolhaJogadorSituacao == 'A'){
        if(dadosituacao <= 7){
            pontuacao+=20;
            return 1;
        }
        else{
            return 0;
        }

    }
    else if(escolhaJogadorSituacao == 'B'){
        if(dadosituacao <= 5){
            pontuacao+=20;
            return 1;
        }
        else{
            return 0;
        }

    }
    else if(escolhaJogadorSituacao == 'C'){
        if(dadosituacao <= 3){
            pontuacao+=20;
            return 1;
        }
        else{
            return 0;
        }

    }

}

int NovaRodada() {
    int tabuleiro[8][4], cont = 0;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            cont++;
            tabuleiro[i][j] = cont;
        }
    }

    int dado;
    int situacao;

    srand(time(NULL));

    dado = rand() % 4;
    while (dado == 4) {
        dado = rand() % 4;
    }

    FILE *ArquivoSituacoes;
    FILE *lerSemestre;
    lerSemestre = fopen(NomeUsuario,"r");

    fscanf(lerSemestre,"%d %d %d",&semestre,&pontuacao,&quantidadeRodadas);
    fclose(lerSemestre);
    ArquivoSituacoes = fopen("situacoes.txt", "r");

    if (ArquivoSituacoes != NULL) {
        char texto_situacao[500];
        char string;
        FILE *abreArquivoUsuario;
        abreArquivoUsuario = fopen(NomeUsuario, "a");

        if(abreArquivoUsuario == NULL){
            printf("Deu treta\n");
            exit(0);
        }
        //	POSI��O DO PERSONAGEM NO TABULEIRO
        situacao = tabuleiro[semestre][dado];

        setlocale(LC_ALL, "Portuguese");

        int ComparadorIndicador = 0; // numero em que sera realizada a compara��o com situa��o
        // percorre todo o arquivo
        while ((string = fgetc(ArquivoSituacoes)) != EOF) {
            fscanf(ArquivoSituacoes, "%d", &ComparadorIndicador);
            int i = -1;

            if (ComparadorIndicador == situacao) {
                do {
                    i++;
                    fscanf(ArquivoSituacoes, "%c", &texto_situacao[i]);
                    if(texto_situacao[i] == '|')
                        break;
                    printf("%c", texto_situacao[i]);
                    fprintf(abreArquivoUsuario, "%c", texto_situacao[i]);

                } while (texto_situacao[i] != '|');

                printf("\n");// Quebra de linha após a entrada da situação
                fprintf(abreArquivoUsuario, "\n");
                fclose(abreArquivoUsuario);



                if(escolhaSituacao() == 1){
                   printf("Você ganhou 20 pontos!\n");//avançou de semestre?
                }
                else{
                    printf("Deu ruim, voce....\n");
                }

                semestre+=1;
                lerSemestre = fopen(NomeUsuario,"r+");
                fseek(lerSemestre,10,SEEK_SET);
                fprintf(lerSemestre, "%d", semestre);
                fseek(lerSemestre,0,SEEK_END);
                fclose(lerSemestre);
                break;


        }
    }
    }
    return 0;
}

// N�O TA PRONTO....FALTA ARQUIVO
int Salvar_Sair() {

    return 0;
}

void sair() {
    exit(0);
}
