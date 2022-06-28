
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//FUNÇÕES
int MenuInicial();
void instrucoes();
int iniciar();
int continuar();
void sair();
int MenuRodadas();
int NovaRodada();
int Salvar_Sair();
int CriarArquivoUsuario();
int escolhaSituacao();
int jogoInteiro();
int finalDoJogo();
int ehCaracter(char letra);
int ehNomeValido();
// GLOBAIS
char NomeUsuario[256];
int semestre = 0, pontuacao = 0, quantidadeRodadas = 1;


//FUNÇÃO PRINCIPAL /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    /////
    setlocale(LC_ALL, "Portuguese");

    int x = MenuInicial();

    if (x == 1) {
        iniciar();
        int opcaoDoJogador = MenuRodadas();
        fflush(stdin);
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
} ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//EXECUTA TODAS AS RODAS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int jogoInteiro(){
    printf("\nsemestre: %d\n",semestre);
    printf("pontuação: %d\n",pontuacao);
    printf("quantidadeRodada: %d\n",quantidadeRodadas);
    NovaRodada();
    int escolha=0;

    for(int i=0;i<7;i++){
        //printf("I do for = %d \n",i);
        escolha = MenuRodadas();
        if(escolha == 1){
                printf("\nsemestre: %d\n",semestre);
                printf("pontuação: %d\n",pontuacao);
                printf("quantidadeRodada: %d\n",quantidadeRodadas);
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
        if(semestre == 7)
            finalDoJogo();
    }
    return 0;
}////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// INICIALIZANO O JOGO /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int iniciar() {
    int ConfirmacaoDoNomeUsuario;

    printf("Seja Bem - Vindo(a)!!! Digite seu nome de usuario: ");
    fflush(stdin);
    scanf("%s", NomeUsuario);

    while (!ehNomeValido(NomeUsuario)){
        fflush(stdin);
        scanf("%s", NomeUsuario);
    }

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
    ArquivoUsuario = fopen(NomeUsuario, "r+");
    fprintf(ArquivoUsuario, "Semestre: %d\nPontuacao: %d\n\nQuantidadeRodadas: %d\n", semestre,pontuacao, quantidadeRodadas);
    fclose(ArquivoUsuario);
    return 0;
}////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//CRIANDO ARQUIVO DO USUARIO /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        arq_usuario = fopen(NomeUsuario, "w+");

    }

    else if (ConfirmacaoNome != 1) {
        printf("Iniciando Novamente!\n");
        iniciar();
    }
    return 0;
}//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MENU INICIAL //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MenuInicial() {
    instrucoes();
    int EscolhaJogador;
    fprintf(stdout, "1 - Iniciar 2 - Continuar 3 - sair\n");
    fprintf(stdout, "Digite sua escolha: ");
    scanf("%d", &EscolhaJogador);

    while (!ehNomeValido(NomeUsuario))
        scanf("%s", NomeUsuario);

    if (EscolhaJogador >= 1 && EscolhaJogador <=3)
        return EscolhaJogador;

    do {
        fprintf(stdout, "Valor incorreto, digite novamente!\n");
        fprintf(stdout, "Digite sua escolha: ");
        fflush(stdin);
        scanf("%d", &EscolhaJogador);
        fflush(stdin);
    } while (EscolhaJogador < 1 && EscolhaJogador > 3);

    return EscolhaJogador;
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void instrucoes(){
    printf("Bem - Vindo ao Jogo da vida Universitaria!!!\n");
    printf("Objetivo: Se divertir ao se deparar com situacoes inusitadas que podem ocorrer  contigo durante a sua trajetoria pela graduacao!! E claro, alcancar o esperado  diploma;");
    printf("\nComo Jogar: Utilize o teclado de seu computador e digite a opcao desejada para  dar prosseguimento ao jogo. Voce pode sair a qualquer momento, desejando salvar  ou nao o seu percurso!!");
    printf("O jogo possui 8 rodadas (semestres), em cada uma delas  você terá uma situação e 3 possibilidades de resposta, sendo uma a mais ideal,  maior probabilidade de ganhar pontos,  e as outras menos ");
    printf("ideais, menor probabilidade de ganhar pontos. Após, a sorte será lançada e você descobrirá se fez ou não uma boa escolha!!");
    printf("\nAo final, a partir da sua pontuacao lhe diremos como foi a sua trajetoria ate aqui e quais foram as suas conquistas!!");
    printf("\nATENCAO: digite apenas 1 nome/apelido unico de usuario, sem numeros, apenas cara-cter!!");
    printf("\nDivirta-se!!\n \n ");



}

// VERIFICANCO A EXISTENCIA DE CARACTER/////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// OPÇÃO CONTINUAR ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    fclose(continuarArquivo);

    continuarArquivo = fopen(NomeUsuario, "r+");

    fseek(continuarArquivo,10,SEEK_SET);
    fscanf(continuarArquivo,"%d",&semestre);

    fseek(continuarArquivo,45,SEEK_SET);
    fscanf(continuarArquivo, "%d", &quantidadeRodadas);

    fseek(continuarArquivo,23,SEEK_SET);
    fscanf(continuarArquivo, "%d", &pontuacao);

    fseek(continuarArquivo,0,SEEK_END);
    fclose(continuarArquivo);

    int opcaoDoJogador = MenuRodadas();
    if (opcaoDoJogador == 1)
        jogoInteiro();
    if (opcaoDoJogador == 2)
        Salvar_Sair();
    if (opcaoDoJogador == 3)
        sair();
    return 0;
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MENU INICIAL DE CADA RODADA ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MenuRodadas() {

    int EscolhaJogador;

    do {
        fprintf(stdout, "\n 1 - Nova Rodada, 2 - Salvar e sair 3 - Sair\n");
        fprintf(stdout, "LEMBRE-SE: a opcao 3 nao salvara o seu percurso at� aqui \n");
        fprintf(stdout, "\n Digite sua escolha: ");
        scanf("%d", &EscolhaJogador);
        printf("Sua escolha foi: %d\n",EscolhaJogador);
        if (EscolhaJogador == 1 || EscolhaJogador == 2 || EscolhaJogador == 3)
            return EscolhaJogador;
        if (EscolhaJogador < 1 || EscolhaJogador > 3)
            fprintf(stdout, "Valor incorreto, digite novamente\n");
        break;
    } while (EscolhaJogador != 3);
    return 0;
} ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ESCOLHA DA ALTERNATIVA ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int escolhaSituacao(){

    char escolhaJogadorSituacao;
    scanf(" ");
    scanf("%c",&escolhaJogadorSituacao);
    printf("Sua escolha foi: %c\n",escolhaJogadorSituacao);
    int dadosituacao;

    srand(time(NULL));

    dadosituacao = rand() % 10;

    //printf("Numero sorteado pelo dado: %d\n", dadosituacao);
    printf("Dados sendo sorteados...");

    escolhaJogadorSituacao = toupper(escolhaJogadorSituacao);
    //printf("escolha: %c\n", escolhaJogadorSituacao);

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
        if(dadosituacao <= 2){
            pontuacao+=20;
            return 1;
        }
        else{
            return 0;
        }

    }
    return 0;
}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// FUNÇÃO DA RODADA ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    //printf("Semest: %d,pont: %d, qntd:%d\n",semestre,pontuacao,quantidadeRodadas);
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
                   printf("Você ganhou 20 pontos!\n");//avançou de semestre? SIM
                }
                else{
                    printf("Deu ruim, voce....\n");
                }

                // para pontuacao  eh 22
                semestre+=1;
                quantidadeRodadas+=1;

                lerSemestre = fopen(NomeUsuario,"r+");

                fseek(lerSemestre,10,SEEK_SET);
                fprintf(lerSemestre, "%d", semestre);

                fseek(lerSemestre,45,SEEK_SET);
                fprintf(lerSemestre, "%d", quantidadeRodadas);

                fseek(lerSemestre,23,SEEK_SET);
                fprintf(lerSemestre, "%d", pontuacao);

                fseek(lerSemestre,0,SEEK_END);
                fclose(lerSemestre);

                break;


        }
    }
    }
    return 0;
}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int  finalDoJogo(){
    printf("Parabens por chegar ao fim do Jogo da Vida Universitaria!!!!!!!!!!\n");
    if(pontuacao>=130){
        printf("Parabens por ter sido um aluno dedicado, voce foi de longe o melhor aluno da sala!!! Suas horas de estudos nao foram atoa, voce se formou com maestria!!!!\n");
        return 0;
    }
    else if(pontuacao >= 100){
        printf("Parabens por ter sido um aluno dedicado, voce nao foi o melhor, mas ERA um dos melhores, sua dedicacao foi retornada e voce conseguiu se formar em BSI, parabeens!!!!!!\n");
    }
    else if(pontuacao >=70){
        printf("Voce definitivamente nao foi o melhor aluno da sala, pra ser sincero estava entre os medianos ");
        printf("com muita dificuldade e algumas DP's conseguiu se formar em 6 anos... nao e pouco mas ainda assim e algo, parabeeeeens!!\n");
        return 0;
     }
    else if(pontuacao >=30){
        printf("Curtindo e estudando muiiiito raramente, voce estava entre os piores, mas nao era o pior, bebendo muito para afogar as magoas");
        printf(", voce teve cirrose por tanto beber e nao conseguiu terminar a faculdade, mas relaxe voce esta vivo!\n");
        return 0;
     }
    else if(pontuacao >=0){
        printf("Caramba, a USP vai ter pesadelos com suas atitudes durante o curso...Voce vai ficar lembrado pra sempre, mas nao de um jeito bom ");
        printf(", nem tudo sao flores..E como voce era baladeiro, gostava de sair.. quando voce estava bebado em uma festa, acabou entrando em uma briga e ficou em coma por 10 ANOS! ");
        printf("Infelizmente voce foi expulso da faculdade depois de um tempo, mas seguiu sua vida feliz (?)....\n");
        return 0;
    }
    return 0;
}
// NAO TA PRONTO....FALTA ARQUIVO
int Salvar_Sair() {

    return 0;
}

void sair() {
    exit(0);
}
