// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int sumaDigitos(int n, int suma) {    //FINAL
    if (n == 0) return suma;
    else return sumaDigitos((n / 10), suma + n % 10);
}

void resuelveCaso() {
    int num_elem; cin >> num_elem;
    int numero; cin >> numero;
    int sumaNumero = sumaDigitos(numero, 0);
    for (int i = 0; i < num_elem; ++i) {
        int a; cin >> a;
        if (sumaNumero == sumaDigitos(a, 0)) cout << a << ' ';
    }
    cout << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}