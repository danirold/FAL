// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int sumaDigitos(int n) {    //NO FINAL
    if (n < 10) return n;
    else return sumaDigitos(n / 10) + n % 10;
}

void resuelveCaso() {
    int num_elem; cin >> num_elem;
    int numero; cin >> numero;
    int sumaNumero = sumaDigitos(numero);
    for (int i = 0; i < num_elem; ++i) {
        int a; cin >> a;
        if (sumaNumero == sumaDigitos(a)) cout << a << ' ';
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