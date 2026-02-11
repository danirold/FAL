// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) {
    if (v1.size() == 1) return v1[0];
    else if (v1[ini] != v2[ini]) return v1[ini];
    else if (v1[fin - 1] != v2[fin - 2]) return v1[fin - 1];
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v1[mitad] < v2[mitad]) return resolver(v1, v2, ini, mitad + 1);
        else return resolver(v1, v2, mitad, fin);
    }
}

void resuelveCaso() {
    int tamano_v1; cin >> tamano_v1;
    vector<int> v1(tamano_v1);
    vector<int> v2(tamano_v1 - 1);

    for (int i = 0; i < v1.size(); ++i) cin >> v1[i];
    for (int i = 0; i < v2.size(); ++i) cin >> v2[i];
    
    cout << resolver(v1, v2, 0, tamano_v1) << '\n';
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}