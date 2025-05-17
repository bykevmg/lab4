#include <stdio.h>
#include <string.h>
#define MAX 1000  //maximo de palabras para evitar el stack overflow

//verificar si la palabra es un palindromo
int esPalindromo(char palabra[]) {
    int inicio = 0;
    int fin = 0;

    while (palabra[fin] != '\0') {
        fin++;
    }
    fin--;

    while (inicio < fin) {
        if (palabra[inicio] != palabra[fin]) {
            return 0; // si no es palindromo
        }
        inicio++;
        fin--;
    }
    return 1; // es palindromo
}

void RevisarPalabra(char palabra[]) {
    int i = 0, j = 0;
    while (palabra[i] != '\0') {
        if ((palabra[i] >= 'a' && palabra[i] <= 'z') || (palabra[i] >= 'A' && palabra[i] <= 'Z') || (palabra[i] >= '0' && palabra[i] <= '9')) {
            if (palabra[i] >= 'A' && palabra[i] <= 'Z') {
                palabra[i] = palabra[i] + 32;  // convertir a minuscula
            }
            palabra[j++] = palabra[i];
        }
        i++;
    }
    palabra[j] = '\0';
}

int main() {
    FILE *archivo;
    char palabra[MAX], PalabraLarga[MAX];
    int maximalongitud = 0;

    archivo = fopen("input.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fscanf(archivo, "%s", palabra) != EOF) {
        RevisarPalabra(palabra); 

        //verificar que sea palindromo
        if (esPalindromo(palabra) && strlen(palabra) > maximalongitud) {
            maximalongitud = strlen(palabra);
            strcpy(PalabraLarga, palabra);  //guardar la palabra mas larga
        }
    }

    fclose(archivo);

    //mostrar el palindromo mas largo
    if (maximalongitud > 0) {
        printf("La palabra palindroma mas larga es: %s\n", PalabraLarga);
    } else {
        printf("No se encontro ningun palindromo en el archivo.\n");
    }

    return 0;
}
