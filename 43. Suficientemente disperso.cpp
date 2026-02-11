// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool resolver(vector<int> const& v, int valor_dispersion, int ini, int fin) {
    if (ini + 1 == fin) return true;
    if (abs(v[ini] - v[fin - 1]) < valor_dispersion) return false;
    else {
        int mitad = (ini + fin - 1) / 2;
        return (resolver(v, valor_dispersion, ini, mitad + 1) && resolver(v, valor_dispersion, mitad + 1, fin));
    }
}

bool resuelveCaso() {
    int num_tiradas; cin >> num_tiradas;

    if (!std::cin)
        return false;

    int valor_dispersion; cin >> valor_dispersion;
    vector<int> v(num_tiradas);
    for (int i = 0; i < num_tiradas; ++i) cin >> v[i];
    bool solucion = resolver(v, valor_dispersion, 0, num_tiradas);
    if (solucion) cout << "SI\n";
    else cout << "NO\n";

    return true;

}

int main() {
    while (resuelveCaso());
    return 0;
}