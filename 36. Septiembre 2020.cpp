// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

bool num_interesante(int numero, int suma_dcha, int suma_izq) {
    if (numero < 10 && numero % suma_dcha != 0 && numero % suma_izq != 0) return false;
    else if (numero > 10) {
        if((numero % 10) % suma_dcha -)
    }
}

int suma_recursiva(int numero) {
    if (numero < 10) return numero;
    else return suma_recursiva(numero / 10) + numero % 10;
}

void resuelveCaso() {
    int numero; cin >> numero;
    int suma_total = suma_recursiva(numero);
    if (num_interesante(numero, 0, suma_total)) cout << "SI\n";
    else cout << "NO\n";
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}