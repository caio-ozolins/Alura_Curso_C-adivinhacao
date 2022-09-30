#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("--------------------------------------\n");
    wprintf(L"Bem vindo ao nosso jogo de adivinhação\n");
    printf("--------------------------------------\n");

    int numeroSecreto = 42, chute, tentativa = 1, pontos=1000;

    while (1) {
        wprintf(L"Tentativa %d\n", tentativa);
        wprintf(L"Chute um número positivo: \n");
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
        int pontosPerdidos = (chute - numeroSecreto) / 2;
        pontos -= pontosPerdidos;
    }
    wprintf(L"Fim de jogo!\n");
    wprintf(L"Você acertou na %dª tentativa\n", tentativa);
    wprintf(L"Total de pontos: %d\n", pontos);

    return 0;
}
