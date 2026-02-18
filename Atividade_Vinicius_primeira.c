#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetor(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = n - i;
}

int main() {
    int tamanhos[] = {100, 1000, 10000};
    
    printf("Algoritmo\tTamanho\tTempo (ms)\tComparacoes\tMovimentacoes\n");

    for (int i = 0; i < 3; i++) {
        int n = tamanhos[i];
        int *v = (int*)malloc(n * sizeof(int));
        long long comps = 0, movs = 0;
        clock_t inicio, fim;

        // Bubble Sort
        gerarVetor(v, n);
        inicio = clock();
        for (int a = 0; a < n - 1; a++) {
            for (int b = 0; b < n - a - 1; b++) {
                comps++;
                if (v[b] > v[b + 1]) {
                    int temp = v[b];
                    v[b] = v[b + 1];
                    v[b + 1] = temp;
                    movs++;
                }
            }
        }
        fim = clock();
        printf("Bubble Sort\t%d\t%.2f\t\t%lld\t\t%lld\n", n, (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC, comps, movs);

        // Selection Sort
        gerarVetor(v, n);
        comps = 0; movs = 0;
        inicio = clock();
        for (int a = 0; a < n - 1; a++) {
            int min = a;
            for (int b = a + 1; b < n; b++) {
                comps++;
                if (v[b] < v[min]) min = b;
            }
            if (min != a) {
                int temp = v[a];
                v[a] = v[min];
                v[min] = temp;
                movs++;
            }
        }
        fim = clock();
        printf("Selection Sort\t%d\t%.2f\t\t%lld\t\t%lld\n", n, (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC, comps, movs);

        free(v);
    }
    return 0;
}