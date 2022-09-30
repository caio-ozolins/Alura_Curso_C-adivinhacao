#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("--------------------------------------\n");
    wprintf(L"Bem vindo ao nosso jogo de adivinhação\n");
    printf("--------------------------------------\n");
    int seed = time(0);
    srand(seed);
    int numeroSecreto = (rand()%100+1), chute, tentativa = 1;
    double pontos=1000;

    while (1) {
        wprintf(L"Tentativa %d\n", tentativa);
        wprintf(L"Chute um número positivo entre 0 e 100: \n");
        scanf("%d", &chute);
        if (chute < 0){
            wprintf(L"Por favor não digite números negativos.\n");
            continue;
        }

        int acertou = chute == numeroSecreto;
        int maior = chute > numeroSecreto;
        if (acertou) {
            wprintf(L"Você acertou!\n");
            break;
        }
        else if (maior) {
            wprintf(L"Seu chute foi maior que o número secreto.\n");
        }
        else {
            wprintf(L"Seu chute foi menor que o número secreto.\n");
        }
        tentativa++;
        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        pontos -= pontosPerdidos;
    }
    wprintf(L"Fim de jogo!\n");
    wprintf(L"Você acertou na %dª tentativa\n", tentativa);
    wprintf(L"Total de pontos: %.1f\n", pontos);

    return 0;
}
