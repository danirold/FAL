// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int jugarDigito(int n, int j, int p) {
    if (n < 10 && n % 2 == 0) return (n + 1) * p + j;
    else if (n < 10 && n % 2 == 1) return (n - 1) * p + j;
    else if (n >= 10 && n % 2 == 0) return jugarDigito(n / 10, (n % 10 + 1) * p + j, p * 10);
    else if (n >= 10 && n % 2 == 1) return jugarDigito(n / 10, (n % 10 - 1) * p + j, p * 10);
}

void resuelveCaso() {
    int numero; cin >> numero;
    cout << jugarDigito(numero, 0, 1) << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}