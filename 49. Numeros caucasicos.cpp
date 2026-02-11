// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool num_pares (vector<int> const& v, int ini, int fin, int mitad) {
    int pares_izq = 0;
    for (int i = ini; i < mitad + 1; ++i) {
        if (v[i] % 2 == 0) pares_izq++;
    }

    int pares_dcha = 0;
    for (int i = mitad + 1; i < fin; ++i) {
        if (v[i] % 2 == 0) pares_dcha++;
    }

    bool pares_correct = false;
    if (abs(pares_izq - pares_dcha) <= 2) pares_correct = true;
    return pares_correct;
}

bool resolver(vector<int> const& v, int ini, int fin) {
    if (ini + 1 == fin) return true;
    else {
        int mitad = (ini + fin - 1) / 2;
        return num_pares(v, ini, fin, mitad) && resolver(v, ini, mitad + 1) && resolver(v, mitad + 1, fin);
    }
}

bool resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;
    if (tamano_vector == 0)
        return false;

    vector<int> v(tamano_vector);
    for (int i = 0; i < tamano_vector; ++i) cin >> v[i];
    if (resolver(v, 0, tamano_vector)) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}