#include <iostream>
#include <omp.h>

// Constantes de precompilación
const int N = 1000;
const int chunk = 100;
const int mostrar = 10;

// Prototipo de función
void imprimeArreglo(int* arreglo);

int main() {
    // Declarar arreglos
    int a[N], b[N], c[N];
    int i;

    // Asignar valores a los arreglos a y b
    for (int i = 0; i < N; i++) {
        a[i] = i * 3;
        b[i] = (i + 5);
    }

    // Suma paralela de los arreglos
#pragma omp parallel for schedule(static, chunk) shared(a, b, c)
    for (i = 0; i < N; i++) {  
        c[i] = a[i] + b[i];
    }

    // Imprimir parte de los arreglos
    std::cout << "Arreglo a: ";
    imprimeArreglo(a);
    std::cout << "Arreglo b: ";
    imprimeArreglo(b);
    std::cout << "Arreglo c (suma de a y b): ";
    imprimeArreglo(c);

    return 0;
}

// Implementación de la función imprimeArreglo
void imprimeArreglo(int* arreglo) {
    for (int i = 0; i < mostrar; i++) {
        std::cout << arreglo[i] << " - ";
    }
    std::cout << std::endl;
}

