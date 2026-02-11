// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int> const& v, int num_cantado, int ini, int fin) {
    if (ini + 1 == fin && num_cantado + ini == v[ini]) return v[ini];
    else if (ini + 1 == fin && num_cantado + ini != v[ini]) return -1;
    else {
        int mitad = (ini + fin - 1) / 2;
        if (num_cantado + mitad == v[mitad]) return v[mitad];
        else if (num_cantado + mitad < v[mitad]) return resolver(v, num_cantado, ini, mitad + 1);
        else return resolver(v, num_cantado, mitad + 1, fin);
    }
}

void resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;
    int num_cantado; cin >> num_cantado;

    vector<int> v(tamano_vector);
    for (int i = 0; i < v.size(); ++i) cin >> v[i];

    int solucion = resolver(v, num_cantado, 0, tamano_vector);
    if (solucion == -1) cout << "NO\n";
    else cout << solucion << '\n';
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}