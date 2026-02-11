// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int> const& v, int ini, int fin) {
    if (ini + 1 == fin) return v[ini];
    else if (ini + 2 == fin) {
        if (v[ini] < v[ini + 1]) return v[ini];
        else return v[ini + 1];
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] < v[mitad - 1] && v[mitad + 1] > v[mitad]) return v[mitad];
        else if (v[mitad] < v[mitad - 1] && v[mitad + 1] < v[mitad]) return resolver(v, mitad + 1, fin);
        else return resolver(v, ini, mitad + 1);
    }
}

bool resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;

    if (!std::cin)
        return false;

    vector<int> v(tamano_vector);
    for (int i = 0; i < tamano_vector; ++i) cin >> v[i];
    cout << resolver(v, 0, tamano_vector) << '\n';

    return true;

}

int main() {
    while (resuelveCaso());
    return 0;
}