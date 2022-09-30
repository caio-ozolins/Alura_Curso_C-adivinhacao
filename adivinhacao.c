#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    wprintf(L"          P  /_\\  P                                \n");
    wprintf(L"         /_\\_|_|_/_\\                               \n");
    wprintf(L"     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    wprintf(L"     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!  \n");
    wprintf(L"    |\" \"  |  |_|  |\"  \" |                          \n");
    wprintf(L"    |_____| ' _ ' |_____|                          \n");
    wprintf(L"          \\__|_|__/                                \n");
    printf("\n\n");

    int seed = time(0);
    srand(seed);
    int numeroSecreto = (rand()%100+1), chute, tentativa = 1, numTentaivas, acertou = 0, nivel;
    double pontos=1000;

    wprintf(L"Qual o nível de dificuldade?\n");
    wprintf(L"1.Fácil 2.Médio 3.Difícil\n\n");
    wprintf(L"Escolha:");
    scanf("%d", &nivel);
    switch (nivel) {
        case 1:
            numTentaivas=20;
            break;
        case 2:
            numTentaivas=15;
            break;
        default:
            numTentaivas=6;
            break;
    }

    for (int i = 1; i <= numTentaivas; i++) {
        wprintf(L"Tentativa %d de %d\n", tentativa, numTentaivas);
        wprintf(L"Chute um número positivo entre 0 e 100: \n");
        scanf("%d", &chute);
        if (chute < 0){
            wprintf(L"Por favor não digite números negativos.\n");
            continue;
        }

        acertou = chute == numeroSecreto;
        int maior = chute > numeroSecreto;
        if (acertou) {
            break;
        }
        else if (maior) {
            wprintf(L"Seu chute foi maior que o número secreto.\n\n");
        }
        else {
            wprintf(L"Seu chute foi menor que o número secreto.\n\n");
        }
        tentativa++;
        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        pontos -= pontosPerdidos;
    }
    wprintf(L"Fim de jogo!\n");
    if (acertou){
        printf("\n\n");
        wprintf(L"          ..::''''''::..          \n");
        wprintf(L"        .;''          ``;.        \n");
        wprintf(L"       ::     ::  ::     ::       \n");
        wprintf(L"      ::      ::  ::      ::      Você acertou na %dª tentativa\n", tentativa);
        wprintf(L"      ::  .:' ::  :: `:.  ::      Total de pontos: %.1f\n", pontos);
        wprintf(L"      ::   :          :   ::      \n");
        wprintf(L"       ::  `:.      .:'  ::       \n");
        wprintf(L"        `;.. ``::::'' ..;'        \n");
        wprintf(L"          ``::,,,,,,::''          \n");
        printf("\n\n");
    } else{
        printf("\n\n");
        wprintf(L"Você errou, tente novamente\n");
        wprintf(L"    \\|/ ____ \\|/  \n");
        wprintf(L"     @~/ ,. \\~@    \n");
        wprintf(L"    /_( \\__/ )_\\  \n");
        wprintf(L"       \\__U_/      \n");
        printf("\n\n");
    }

    return 0;
}
