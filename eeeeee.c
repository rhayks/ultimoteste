#include <stdio.h> // biblioteca entrada e saida
#include <stdlib.h> // alocaçao de memoria
#include <string.h> // manipulaçao de string 

typedef struct _personagem // para simplificar a declaraçao das variaveis
{
    char nomeDoPersonagem[50]; 
    int idade;
    char genero[50];
}Personagem;

typedef struct _jogo
{
   char nomeDoJogo[50];
   int anoDeLancamento;
   char categoria[50];
   Personagem personagens[50];  // pq a variavel personagem esta dentro do jogo
   int numPersonagem;
}Jogo;

Jogo cadastrarNovoJogo(){ // para o usuario cadastrar novo jogo 
    Jogo novoJogo;
    int numPersonagens = 0; // igual a 0 pq nao existe nenhum personagem cadastrado ainda
    printf("Digite o nome do jogo");
    scanf(" %[^\n]s", novoJogo.nomeDoJogo); 
    printf("Digite o ano de lancamento");
    scanf("%d", novoJogo.anoDeLancamento);
    printf("Digite o nome da categoria");
    scanf(" %[^\n]s", novoJogo.categoria);
    printf("\n\n");
    return novoJogo;
}
Personagem cadastrarNovoPersonagem(){ // cadastrar um novo personagem
    Personagem personagens;
    printf("Digite o nome do personagem");
    scanf(" %[^\n]s", personagens.nomeDoPersonagem);
    printf("Digite a idade do personagem");
    scanf("%d", personagens.idade);
    printf("Digite o genero do personagem");
    scanf(" %[^\n]s", personagens.genero);
    scanf("\n\n");
    return personagens;
}
void editarJogo(Jogo jogos[], int numDoJogo){
    char nomeDoJogo[50];
    int i, opcao;

    printf("Digite o nome do jogo");
    scanf(" %[^\n]s", nomeDoJogo);
    for(i=0; i<numDoJogo; i++){ // i sendo a tribuido a 0 por n ter nenhuma "informaçao" nele, se i for menor que o num do jogo vai retornar o valor inicial de 1 q e 0 q ai entra o if
        if (strcasecmp(nomeDoJogo, jogos[i].nomeDoJogo)==0){ // se o num do jogo estiver no msm num sera retornado vdd pelo ==0
            printf("Digite\n");
            printf(" 1 para editar o nome do jogo\n");
            printf(" 2 para editar ano de lancamento do jogo\n");
            printf(" 3 para editar a categoria do jogo\n");
            scanf("%d", &opcao);
            switch (opcao) // executar os comandos dos printf´s do if, opcao em parenteces pq ela q esta sendo comparada
            {
            case 1:
            printf("Digite o nome do jogo\n");
            scanf(" %[^\n]s", jogos[i].nomeDoJogo);
                break;
            case 2:
            printf("Digite o ano de lancamento\n");
            scanf("%d", jogos[i].anoDeLancamento);
                break;
            case 3:
            printf("Digite a categoria do jogo\n");
            scanf(" %[^\n]s", jogos[i].categoria);
                break;
            default:
            printf("jogo nao cadastrado\n");
                break;
            }
        } printf("operacao realizada com sucesso\n\n");
    }
}
void editarPersonagem(Personagem personagens[], int numPersonagem){
    char nomeDoPersonagem[50];
    int i, opcao;

    printf("Digite o nome do personagem");
    scanf(" %[^\n]s",  nomeDoPersonagem);
    for(i=0; i < nomeDoPersonagem; i++){
        if(strcasecmp(nomeDoPersonagem, personagens[i].nomeDoPersonagem)==0){
            printf(" 1 para editar o nome do personagem\n");
            printf(" 2 para editar idade\n");
            printf(" 3 para editar genero do personagem\n");
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
            printf("Digite o nome do jogo\n");
            scanf(" %[^\n]s", personagens[i].nomeDoPersonagem);
                break;
            case 2:
            printf("Digite a idade do personagem\n");
            scanf("%d", personagens[i].idade);
                break;
            case 3:
            printf("Digite o genero do personagem\n");
            scanf(" %[^\n]s", personagens[i].genero);
                break;
            default:
            printf("personagem nao cadastrado\n");
                break;
            }
        }printf("operacao realizada com sucesso\n\n");
    }  
}
void listarJogos(Jogo jogos[], int numDoJogo){
    int i;
    for(i=0; i<numDoJogo; i++){
        printf("%d - %s\n", i+1, jogos[i].nomeDoJogo);
    } printf("\n\n");
}
void listarPersonagem(Personagem personagens[], int numPersonagem){
    int i;
    for(i=0; i<numPersonagem; i++){
        printf("%d - %s\n", i+1, personagens[i].nomeDoPersonagem); // se a variavel for int sera executada pelo %d e se for string sera pelo %s
    } printf("\n\n");
}

void excluirJogo(Jogo jogos[], int numDoJogo){
    char nomeDoJogo[50];
    int i, encontrar = 0;
    printf("Digite o nome do jogo para excluir: ");
    scanf(" %[^\n]s", nomeDoJogo);
    for(i=0; i<numDoJogo; i++){
        if(strcasecmp(nomeDoJogo, jogos[i].nomeDoJogo)==0){
            encontrar = 1;
        }
    } if(encontrar){
        if(i<nomeDoJogo-1)
        jogos[i] = jogos[i+1];
    }
    if(encontrar){
        printf("Operacao realizada com sucesso\n\n");
    } else{
        printf("jogo nao encontrado\n\n");
    }
}
void excluirPersonagem(Personagem personagens[], int numPersonagem){
    char nomeDoPersonagem[50];
    int i, encontrar = 0;
    printf("Digite o nome do personagem para excluir: ");
    scanf(" %[^\n]s", nomeDoPersonagem);
    for (i=0; 1< numPersonagem; i++){
        if(strcasecmp(nomeDoPersonagem, personagens[i].nomeDoPersonagem)==0){
            encontrar = 1;
        }
    } if(encontrar){
        if(i<numPersonagem-1)
        personagens[i] = personagens[i+1];
    }
    if(encontrar){
        printf("operacao realizada com sucesso\n\n");
    } else{
        printf("personagem nao encontrado\n\n");
    }
    {
    }  
}

int main () {
    Jogo jogos[100];
    int numDoJogo = 0;
    int posJogo;
    int opcao;
    while (1)
    {
    printf(" 1 para cadastrar um novo jogo\n");
    printf(" 2 para excluir um jogo\n");
    printf(" 3 para editar um jogo\n");
    printf(" 4 para cadastrar um novo personagem\n");
    printf(" 5 para excluir um personagem\n");
    printf(" 6 para editar um personagem\n");
    printf(" 7 para listar jogos\n");
    printf(" 8 para listar personagem\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1: 
    jogos[numDoJogo] = cadastrarNovoJogo(); numDoJogo++;
        break;
    case 2:
    excluirJogo(jogos, &numDoJogo);
        break;
    case 3:
    editarJogo(jogos, numDoJogo);
        break;
    case 4:
    listarJogos(jogos, numDoJogo);
    printf("Digite o numero do jogo: ");
    scanf("%d", &posJogo);
    if(posJogo>0 &&posJogo<=numDoJogo);
    {
        jogos[posJogo-1].personagens[jogos[posJogo-1].numPersonagem] = cadastrarNovoPersonagem();
        jogos[posJogo-1].numPersonagem++;
    } if else {
        printf("operacao invalida\n\n");
    }
        break;
    case 5:
    excluirPersonagem(jogos, numDoJogo);
        break;
    case 6:
    editarPersonagem(jogos, numDoJogo);
        break;
    case 7:
    listarJogos(jogos, numDoJogo);
        break;
    case 8:
    listarPersonagem(jogos, numDoJogo);
        break;
    default:
    printf("opcao invalida\n\n");
        break;
    }
    }
    
}