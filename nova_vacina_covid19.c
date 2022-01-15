//LUCAS MARCEL SILVA CRUZ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define valor_matriz 20
#define sequencia 5

int main() {
    int i, j, k, l, celulas[valor_matriz][valor_matriz], soma_celulas = 0, valores_adjacentes[
            sequencia + 1], aux = 0, aux2 = 0, maior_n_celulas = 0, valores_adjacentes_at[sequencia + 1],
            soma_celulas_at, resp, indice[sequencia * 2], indice_final[sequencia * 2], escrever_indice[2];
    char resp2 = 'S';

    srand(time(NULL));
    setlocale(LC_ALL, "");

    //GERAR VALORES DE CÉLULAS PARA OS OVOS:
    for (i = 0; i < valor_matriz; i++) {
        for (j = 0; j < valor_matriz; j++) {
            celulas[i][j] = rand() % 99;
        }
    }

    //MOSTRAR OS VALORES DE CÉLULAS (GERAL):
    for (i = 0; i < valor_matriz; i++) {
        for (j = 0; j < valor_matriz; j++) {
            if (celulas[i][j] < 10)
                printf("0");
            printf("%d ", celulas[i][j]);
        }
        printf("\n");
    }

    //ENCONTRAR MELHORES OVOS:
    for (i = 0; i < valor_matriz; i++) {
        for (j = 0, k = 1; j < valor_matriz; j++, k++) {
            soma_celulas += celulas[i][j];
            valores_adjacentes[aux] = celulas[i][j];
            aux++;
            indice[aux2] = i;
            aux2++;
            indice[aux2] = j;
            aux2++;
            if (k % sequencia == 0) {
                valores_adjacentes[aux] = soma_celulas;
                if (soma_celulas > maior_n_celulas) {
                    maior_n_celulas = soma_celulas;
                    for (l = 0; l < sequencia + 1; l++) {
                        valores_adjacentes_at[l] = valores_adjacentes[l];
                    }
                    for (l = 0; l < sequencia * 2; l++) {
                        indice_final[l] = indice[l];
                    }
                }
                soma_celulas = 0;
                for (l = 0; l < sequencia + 1; l++) {
                    valores_adjacentes[0] = 0;
                }
                aux = 0;
                aux2 = 0;
            }
        }
    }

    soma_celulas_at = maior_n_celulas;

    for (i = 0; i < valor_matriz; i++) {
        for (j = 0, k = 1; j < valor_matriz; j++, k++) {
            if (i == j) {
                soma_celulas += celulas[i][j];
                valores_adjacentes[aux] = celulas[i][j];
                aux++;
                indice[aux2] = i;
                aux2++;
                indice[aux2] = j;
                aux2++;
                if (k % sequencia == 0) {
                    valores_adjacentes[aux] = soma_celulas;
                    if (soma_celulas > maior_n_celulas) {
                        maior_n_celulas = soma_celulas;
                        for (l = 0; l < sequencia + 1; l++) {
                            valores_adjacentes_at[l] = valores_adjacentes[l];
                        }
                        for (l = 0; l < sequencia * 2; l++) {
                            indice_final[l] = indice[l];
                        }
                    }
                    soma_celulas = 0;
                    for (l = 0; l < sequencia + 1; l++) {
                        valores_adjacentes[0] = 0;
                    }
                    aux = 0;
                    aux2 = 0;
                }
            }
        }
    }

    if (maior_n_celulas > soma_celulas_at)
        soma_celulas_at = maior_n_celulas;

    for (i = 0, k = 1; i < valor_matriz; i++, k++) {
        for (j = 0; j < valor_matriz; j++) {
            if (j == valor_matriz - 1 - i) {
                soma_celulas += celulas[i][j];
                valores_adjacentes[aux] = celulas[i][j];
                aux++;
                indice[aux2] = i;
                aux2++;
                indice[aux2] = j;
                aux2++;
                if (k % sequencia == 0) {
                    valores_adjacentes[aux] = soma_celulas;
                    if (soma_celulas > maior_n_celulas) {
                        maior_n_celulas = soma_celulas;
                        for (l = 0; l < sequencia + 1; l++) {
                            valores_adjacentes_at[l] = valores_adjacentes[l];
                        }
                        for (l = 0; l < sequencia * 2; l++) {
                            indice_final[l] = indice[l];
                        }
                    }
                    soma_celulas = 0;
                    for (l = 0; l < sequencia + 1; l++) {
                        valores_adjacentes[0] = 0;
                    }
                    aux = 0;
                    aux2 = 0;
                }
            }
        }
    }

    if (maior_n_celulas > soma_celulas_at)
        soma_celulas_at = maior_n_celulas;

    for (j = 0; j < valor_matriz; j++) {
        for (i = 0, k = 1; i < valor_matriz; i++, k++) {
            soma_celulas += celulas[i][j];
            valores_adjacentes[aux] = celulas[i][j];
            aux++;
            indice[aux2] = i;
            aux2++;
            indice[aux2] = j;
            aux2++;
            if (k % sequencia == 0) {
                valores_adjacentes[aux] = soma_celulas;
                if (soma_celulas > maior_n_celulas) {
                    maior_n_celulas = soma_celulas;
                    for (l = 0; l < sequencia + 1; l++) {
                        valores_adjacentes_at[l] = valores_adjacentes[l];
                    }
                    for (l = 0; l < sequencia * 2; l++) {
                        indice_final[l] = indice[l];
                    }
                }
                soma_celulas = 0;
                for (l = 0; l < sequencia + 1; l++) {
                    valores_adjacentes[0] = 0;
                }
                aux = 0;
                aux2 = 0;
            }
        }
    }

    if (maior_n_celulas > soma_celulas_at)
        soma_celulas_at = maior_n_celulas;

    printf("\nPROCURAR VALORES DE CÉLULAS [1] ");
    printf("\nMOSTRAR MELHORES OVOS [2] \n");
    scanf("%d", &resp);
    if (resp == 1) {
        //MOSTRAR OS VALORES DE CÉLULAS (INDIVIDUAL):
        printf("Digite a posição do ovo: \n");
        printf("Linha: ");
        scanf("%d", &escrever_indice[0]);
        printf("Coluna: ");
        scanf("%d", &escrever_indice[1]);
        printf("\nOvo número %d", celulas[escrever_indice[0]][escrever_indice[1]]);
    }
    if (resp == 2) {
        printf("\nOs melhores ovos encontrados foram: ");
        for (i = 0; i < sequencia; i++) {
            printf("%d ", valores_adjacentes_at[i]);
        }
        printf("nas posições ");
        for (i = 0; i < sequencia * 2; i++) {
            printf("%d ", indice_final[i]);
        }
        printf("\nE o valor total de suas células é de: %d", soma_celulas_at);
    }

    return 0;
}

