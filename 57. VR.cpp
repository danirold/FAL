// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void escribirSolucion(vector<char> const& sol) {
    for (int i = 0; i < sol.size(); ++i) cout << sol[i];
    cout << '\n';
}

void variaciones(int num_letras, int tamano_palabra, int k, vector<char>& sol) {
    for (char i = 'a'; i < 'a' + num_letras; ++i) {
        sol[k] = i;
        if (k == tamano_palabra - 1) { // Es solucion
            escribirSolucion(sol);
        }
        else { // Sigue completando la solucion
            variaciones(num_letras, tamano_palabra, k + 1, sol);
        }
    }
}

bool resuelveCaso() {
    int num_letras; int tamano_palabra;
    cin >> num_letras >> tamano_palabra;

    if (!std::cin)
        return false;

    vector<char> v(tamano_palabra);
    variaciones(num_letras, tamano_palabra, 0, v);
    cout << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}