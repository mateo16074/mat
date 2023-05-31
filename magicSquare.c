#include <stdio.h>
#include "magicSquare.h"

int cuadradoMagico(int filas, int columnas, int cuadrado[filas][columnas]) {

    int c = calcularConstanteMagica(filas, columnas, cuadrado[filas][columnas]);

  

    // Verificar las sumas de filas y columnas
    for (int i = 0; i < filas; i++) {
        int sumaFila = 0;
        int sumaColumna = 0;
        for (int j = 0; j < columnas; j++) {
            sumaFila += cuadrado[i][j];
            sumaColumna += cuadrado[j][i];
        }
        if (sumaFila != c || sumaColumna != c) {
            return 0;  // No es un cuadrado mágico
        }
    }

    // Verificar la suma de la diagonal principal
    int sumaDiagonalPrincipal = 0;
    for (int i = 0; i <filas; i++) {
        sumaDiagonalPrincipal += cuadrado[i][i];
    }
    if (sumaDiagonalPrincipal != c) {
        return 0;  // No es un cuadrado mágico
    }

    // Verificar la suma de la diagonal secundaria
    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < filas; i++) {
        sumaDiagonalSecundaria +=cuadrado[i][filas - i - 1];
    }
    if (sumaDiagonalSecundaria != c) {
        return 0;  // No es un cuadrado mágico
    }

    // Es un cuadrado mágico
    return 1;
}


int calcularConstanteMagica(int filas, int columnas, int cuadrado[filas][columnas]) {

    int suma = 0; 
    for (int i = 0; i < filas; i++)
    {
       suma += cuadrado[i][0];
    }  
    return suma;

}

void imprimirCuadrado(int filas, int columnas, int cuadrado[filas][columnas]) {

     for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", cuadrado[i][j]);
        }
        printf("\n");
    }
    
}

