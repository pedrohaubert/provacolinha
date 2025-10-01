#include <stdio.h>

// Procedimento que imprime os números pares entre 1 e X
void imprimePares(int x) {
    printf("Números pares de 1 até %d:\n", x);
    for (int i = 1; i <= x; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int x;

    for (int i = 0; i < 10; i++) {
        do {
            printf("Digite um número inteiro maior ou igual a 1: ");
            scanf("%d", &x);

            if (x < 1) {
                printf("Valor inválido. Tente novamente.\n");
            }
        } while (x < 1);

        imprimePares(x);
    }

    return 0;
}
