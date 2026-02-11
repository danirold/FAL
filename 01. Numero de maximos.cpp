// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void resuelveCaso() {
    int maximo;
    int cont = 1;
    int primer_valor;
    cin >> primer_valor;
    maximo = primer_valor;
    int aux;
    cin >> aux;
    while (aux != 0) {
        if (aux > maximo) {
            maximo = aux;
            cont = 1;
        }
        else if (maximo == aux) cont++;
        cin >> aux;
    }
    cout << maximo << ' ' << cont << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}