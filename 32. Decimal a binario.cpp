// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

string decimal_a_binario(int n) {
    if (n == 0) return "0";
    else if (n == 1) return "1";
    else return decimal_a_binario(n / 2) + char('0' + n % 2);
}

void resuelveCaso() {
    int numero; cin >> numero;
    cout << decimal_a_binario(numero) << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}