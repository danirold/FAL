// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int NUM_COLORES = 3;

void escribirSolucion(vector <int> const& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) cout << "azul ";
        else if (v[i] == 1) cout << "rojo ";
        else cout << "verde ";
    }
}

void variaciones(int altura_torre, int k, vector<int>& sol) {
    for (int i = 0; i < NUM_COLORES; ++i) {
        sol[k] = i;
        if (k == altura_torre - 1) { // Es solucion
            escribirSolucion(sol);
            cout << '\n';
        }
        else { // Sigue completando la solucion
            variaciones(altura_torre, k + 1, sol);
        }
    }
}

bool resuelveCaso() {
    int altura_torre; cin >> altura_torre;

    if (altura_torre == 0)
        return false;

    vector<int> sol(altura_torre);
    variaciones(altura_torre, 0, sol);
    cout << '\n';

    return true;

}

int main() {
    while (resuelveCaso());
    return 0;
}