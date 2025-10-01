#include <stdio.h>

/*
    Função que calcula a média de 3 leituras
*/
double calcular_media(double leitura1, double leitura2, double leitura3) {
    return (leitura1 + leitura2 + leitura3) / 3.0;
}

/*
    Função que encontra o valor máximo entre 3 leituras
*/
double encontrar_maximo(double leitura1, double leitura2, double leitura3) {
    double max = leitura1;
    if (leitura2 > max) max = leitura2;
    if (leitura3 > max) max = leitura3;
    return max;
}

/*
    Função que encontra o valor mínimo entre 3 leituras
*/
double encontrar_minimo(double leitura1, double leitura2, double leitura3) {
    double min = leitura1;
    if (leitura2 < min) min = leitura2;
    if (leitura3 < min) min = leitura3;
    return min;
}

/*
    Função que calcula e mostra os desvios de cada leitura em relação à média
*/
void calcular_desvio(double leitura1, double leitura2, double leitura3, double media) {
    printf("Desvio leitura 1: %.2f\n", leitura1 - media);
    printf("Desvio leitura 2: %.2f\n", leitura2 - media);
    printf("Desvio leitura 3: %.2f\n", leitura3 - media);
}

/*
    Função que verifica se cada leitura está dentro da faixa segura
*/
void verificar_faixa(double leitura1, double leitura2, double leitura3, double min_aceito, double max_aceito) {
    // Leitura 1
    if (leitura1 < min_aceito) {
        printf("\033[31mLeitura 1: ABAIXO DO LIMITE (%.2f)\033[0m\n", leitura1);
    } else if (leitura1 > max_aceito) {
        printf("\033[31mLeitura 1: ACIMA DO LIMITE (%.2f)\033[0m\n", leitura1);
    } else {
        printf("\033[32mLeitura 1: OK (%.2f)\033[0m\n", leitura1);
    }

    // Leitura 2
    if (leitura2 < min_aceito) {
        printf("\033[31mLeitura 2: ABAIXO DO LIMITE (%.2f)\033[0m\n", leitura2);
    } else if (leitura2 > max_aceito) {
        printf("\033[31mLeitura 2: ACIMA DO LIMITE (%.2f)\033[0m\n", leitura2);
    } else {
        printf("\033[32mLeitura 2: OK (%.2f)\033[0m\n", leitura2);
    }

    // Leitura 3
    if (leitura3 < min_aceito) {
        printf("\033[31mLeitura 3: ABAIXO DO LIMITE (%.2f)\033[0m\n", leitura3);
    } else if (leitura3 > max_aceito) {
        printf("\033[31mLeitura 3: ACIMA DO LIMITE (%.2f)\033[0m\n", leitura3);
    } else {
        printf("\033[32mLeitura 3: OK (%.2f)\033[0m\n", leitura3);
    }
}

/*
    Função que exibe uma barra gráfica proporcional à média
*/
void exibir_barra_grafica(double media) {
    int qtd = (int) media;
    if (qtd > 20) qtd = 20;

    printf("Intensidade média: %.2f\n", media);
    printf("[");
    for (int i = 0; i < qtd; i++) {
        printf("*");
    }
    printf("]\n");
}

/*
    Função que exibe um relatório completo
*/
void exibir_relatorio_completo(double leitura1, double leitura2, double leitura3) {
    double media = calcular_media(leitura1, leitura2, leitura3);
    double max = encontrar_maximo(leitura1, leitura2, leitura3);
    double min = encontrar_minimo(leitura1, leitura2, leitura3);

    printf("=== RELATÓRIO COMPLETO ===\n");
    printf("Média: %.2f\n", media);
    printf("Máximo: %.2f\n", max);
    printf("Mínimo: %.2f\n", min);
    calcular_desvio(leitura1, leitura2, leitura3, media);
    exibir_barra_grafica(media);
    printf("==========================\n");
}

/*
    Função principal
*/
int main() {
    double leitura1, leitura2, leitura3;
    double minimo, maximo;
    int opcao;
    char repetir, novaSimulacao;

    printf("=== SOBSC LITE – SISTEMA DE BORDO ===\n");

    novaSimulacao = 's';
    while (novaSimulacao == 's' || novaSimulacao == 'S') {
        // Entrada das 3 leituras
        printf("Digite a leitura 1: ");
        scanf("%lf", &leitura1);

        printf("Digite a leitura 2: ");
        scanf("%lf", &leitura2);

        printf("Digite a leitura 3: ");
        scanf("%lf", &leitura3);

        repetir = 's';
        while (repetir == 's' || repetir == 'S') {
            // Exibe menu
            printf("\n--- MENU ---\n");
            printf("1 - Média\n");
            printf("2 - Máx/Mín\n");
            printf("3 - Desvios\n");
            printf("4 - Verificação de faixa\n");
            printf("5 - Barra gráfica\n");
            printf("6 - Relatório completo\n");
            printf("0 - Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1: {
                    double media = calcular_media(leitura1, leitura2, leitura3);
                    printf("Média das leituras: %.2f\n", media);
                    break;
                }
                case 2: {
                    double max = encontrar_maximo(leitura1, leitura2, leitura3);
                    double min = encontrar_minimo(leitura1, leitura2, leitura3);
                    printf("Máximo: %.2f\n", max);
                    printf("Mínimo: %.2f\n", min);
                    break;
                }
                case 3: {
                    double media = calcular_media(leitura1, leitura2, leitura3);
                    calcular_desvio(leitura1, leitura2, leitura3, media);
                    break;
                }
                case 4: {
                    printf("Digite o mínimo aceitável: ");
                    scanf("%lf", &minimo);
                    printf("Digite o máximo aceitável: ");
                    scanf("%lf", &maximo);
                    verificar_faixa(leitura1, leitura2, leitura3, minimo, maximo);
                    break;
                }
                case 5: {
                    double media = calcular_media(leitura1, leitura2, leitura3);
                    exibir_barra_grafica(media);
                    break;
                }
                case 6: {
                    exibir_relatorio_completo(leitura1, leitura2, leitura3);
                    break;
                }
                case 0: {
                    printf("Encerrando sistema...\n");
                    return 0;
                }
                default:
                    printf("Opção inválida.\n");
            }

            printf("\nDeseja realizar outra operação? (s/n): ");
            scanf(" %c", &repetir);
        }

        printf("Deseja iniciar nova simulação? (s/n): ");
        scanf(" %c", &novaSimulacao);
    }

    printf("Encerrando sistema...\n");
    return 0;
}
