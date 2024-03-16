#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //variaveis gerais
    int chute, respostatipodejogo;
    int tentativas = 1;

    //geração de numero aleatorio
    int segundos = time(0);
    srand(segundos);
    int numeroaleatoriogrande= rand();
    int numerosecreto = numeroaleatoriogrande %100;



    //apresentaçao do jogo
    printf("\n");
    printf("**********************************************************************************************\n");
    printf("**********************Bem vindo ao jogo de adivinhacao do numero secreto**********************\n");
    printf("**********************************************************************************************\n");
    printf("\n");
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx Modos de jogo disponiveis xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx:\n");
    printf("\n");
    printf("*Easy Mode: voce tera tentativas ilimitadas para acertar o numero secreto, mas havera um score\n");
    printf("*Hard Mode: voce so tera 5 tentativas para acertar o numero secreto\n");
    printf("\n");
    printf("Qual modo de jogo voce quer jogar? Easy Mode->(1) ou Hard Mode->(2)\n");
    printf("\n");
    printf("ATENCAO: responda apenas com 1 ou 2\n");
    scanf("%d", &respostatipodejogo);

    if (respostatipodejogo == 1){


        //variaveis especificas para o easy mode
        int pontos = 1000;
        int ganhou = 0;

        //Easy mode
        while (ganhou == 0){

            printf("\n");
            printf("tentativa %d\n",tentativas);
            printf(">chute um numero:\n");
            scanf(" %d", &chute);

            if(chute < 0) {
                printf("Voce nao pode chutar numeros negativos\n");
                continue;
            }

            if (chute == numerosecreto){
                printf("\n");   
                printf("Parabens! voce acertou o numero secreto: %d, com %d tentativas :D\n", numerosecreto, tentativas);
                
                ganhou = 1;
            }
            else if ( chute > numerosecreto){
                printf("\n");
                printf("> %d e maior que o numero secreto\n", chute);

            }
            else {
                printf("\n");
                printf("> %d e menor que o numero secreto\n", chute);
            }


            tentativas++;

            int pontosperdidos = abs(chute - numerosecreto)/(double)2;
            pontos = pontos - pontosperdidos;
        }

        //mensagem especifica do easy mode
        printf("Score: %d\n", pontos);


    }else {

        //Hard mode
        for (tentativas = 1; tentativas <= 5; tentativas++){
            
            printf("\n");
            printf("tentativa %d de 5\n",tentativas);
            printf("chute um numero\n");
            scanf(" %d", &chute);
            

            if(chute < 0) {
                printf("\n");
                printf("Voce nao pode chutar numeros negativos\n");
                tentativas--;

                continue;
            }

            if (chute == numerosecreto){   
                printf("\n");
                printf("Parabens! voce acertou o numero secreto: %d, com %d tentativas :D\n", numerosecreto, tentativas);
                
                break;
            }
            else if ( chute > numerosecreto){
                printf("\n");
                printf("> %d e maior que o numero secreto\n", chute);

            }
            else {
                printf("\n");
                printf("> %d e menor que o numero secreto\n", chute);
            }
        }
        
        //mensagem especifica do hard mode
        if (chute == numerosecreto){   
            printf("\n");
            printf("voce acertou com %d tentativas\n", tentativas);
            
        }else {
            printf("\n");
            printf("nao foi dessa vez, tente novamente\n");

        }
        
    }

    //mensagem comum aos dois modos de jogo
    printf("\n");
    printf("Fim de jogo, obrigado por jogar :)\n");
    return 0;
}