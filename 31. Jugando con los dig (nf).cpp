// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int jugarDigito(int n) {
    if (n < 10 && n % 2 == 0) return n + 1;
    else if (n < 10 && n % 2 == 1) return n - 1;
    else if (n >= 10 && n % 2 == 0) return jugarDigito(n / 10) * 10 + (n % 10) + 1;
    else if (n >= 10 && n % 2 == 1) return jugarDigito(n / 10) * 10 + (n % 10) - 1;
}

void resuelveCaso() {
    int numero; cin >> numero;
    cout << jugarDigito(numero) << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}