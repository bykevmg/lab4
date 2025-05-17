// uso nn porque no me deja poner la otra letra
#include <stdio.h>
#define MAX 100  // definimos un maximo para no crear un stack overflow

// funcion para llenar la matriz con de la manera que queremos
void LlenarMatriz(int matriz[MAX][MAX], int tamanno) {
    printf("Ingrese los valores de la matriz (solo se permite 0 o 1):\n");
    for (int i = 0; i < tamanno; i++) {
        for (int j = 0; j < tamanno; j++) {
            int valor;
            do {
                printf("Entrada [%d][%d]: ", i, j);
                scanf("%d", &valor);
            } while (valor != 0 && valor != 1);
            *(*(matriz + i) + j) = valor;
        }
    }
}

// funcion para imprimir la matriz
void ImprimirMatriz(int matriz[MAX][MAX], int tamanno) {
    printf("Matriz (%dx%d):\n", tamanno, tamanno);
    for (int i = 0; i < tamanno; i++) {
        for (int j = 0; j < tamanno; j++) {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

// para encontrar la secuencia mas larga de 1
void EncontrarSecuencia(int matriz[MAX][MAX], int tamanno, int *resultado) {
    int maximo = 0, contador = 0;

    for (int i = 0; i < tamanno; i++) {
        for (int j = 0; j < tamanno; j++) {
            if (*(*(matriz + i) + j) == 1) {
                contador++;
                if (contador > maximo)
                    maximo = contador;
            } else {
                contador = 0;
            }
        }
    }

    *resultado = maximo;
}

int main() {
    int tamanno;
    int matriz[MAX][MAX];
    int SecuenciaMasLarga = 0;

    printf("Ingrese el tamanno de la matriz cuadrada: ");
    scanf("%d", &tamanno);

    if (tamanno <= 0 || tamanno > MAX) {
        printf("Tamanno invalido.");
        return 1;
    }

    //rellenar la matiz
    LlenarMatriz(matriz, tamanno);
    // imprimir la matriz
    ImprimirMatriz(matriz, tamanno);
    //encontrar la secuencia mas larga
    EncontrarSecuencia(matriz, tamanno, &SecuenciaMasLarga);
    //resultado
    printf("La secuencia de 1s mas larga es de: %d\n", SecuenciaMasLarga);

    return 0;
}
