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

void variaciones(int num_letras, int tamano_palabras, int k, vector<char> & sol, vector<bool> & marcas) {
    for (char i = 'a'; i < 'a' + num_letras; ++i) {
        sol[k] = i;
        if (!marcas[i - 'a']) {
            marcas[i - 'a'] = true;
            if (k == tamano_palabras - 1) { // Es solucion
                escribirSolucion(sol);
            }
            else { // Sigue completando la solucion
                variaciones(num_letras, tamano_palabras, k + 1, sol, marcas);
            }
            marcas[i - 'a'] = false;
        }
    }
}

bool resuelveCaso() {
    int num_letras; int tamano_palabra;
    cin >> num_letras >> tamano_palabra;

    if (!std::cin)
        return false;

    vector<char> sol(tamano_palabra);
    vector<bool> marcas(num_letras);
    for (int i = 0; i < marcas.size(); ++i) marcas[i] = false;
    variaciones(num_letras, tamano_palabra, 0, sol, marcas);
    cout << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}