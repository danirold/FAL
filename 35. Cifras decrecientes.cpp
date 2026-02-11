// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int resolver_no_final(int numero, int maximo) {
    if (numero < 10 && numero >= maximo) return numero;
    else if (numero < 10 && numero < maximo) return 0;
    else {
        if (numero % 10 >= maximo) return resolver_no_final(numero / 10, numero % 10) * 10 + numero % 10;
        else return resolver_no_final(numero / 10, maximo);
    }
}

int resolver_final(int numero, int p, int j, int maximo) {
    if (numero < 10 && numero >= maximo) return numero * p + j;
    else if (numero < 10 && numero < maximo) return j;
    else {
        if (numero % 10 >= maximo) return resolver_final(numero / 10, p * 10, (numero % 10) * p + j, numero % 10);
        else return resolver_final(numero / 10, p, j, maximo);
    }
}

void resuelveCaso() {
    int numero; cin >> numero;
    cout << resolver_no_final(numero, numero % 10) << ' ' << resolver_final(numero, 1, 0, numero % 10) << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
