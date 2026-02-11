// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v, int k) {
    int longAct = 0; int longMax = 0; int pares_consecutivos = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2 != 0) {
            longAct++;
            pares_consecutivos = 0;
        }
        else if (v[i] % 2 == 0) {
            longAct++;
            pares_consecutivos++;
        }
        if (pares_consecutivos > k) {
            pares_consecutivos = k;
            longAct = k;
        }
        if (longMax < longAct) {
            longMax = longAct;
        }
    }

    cout << longMax << '\n';
}

void resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;
    int k; cin >> k;

    vector<int> v(tamano_vector);

    for (int i = 0; i < v.size(); ++i) cin >> v[i];

    resolver(v, k);
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}