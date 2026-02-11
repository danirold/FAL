// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool vectorMenor(vector<int> const& v, int p) {
    bool solucion = true;
    if (p < v.size()) {
        int max_menor = v[0];
        for (int i = 1; i <= p; ++i) {
            if (v[i] > max_menor) max_menor = v[i];
        }
        int i = p + 1;
        int tam = v.size();
        while (i < tam && solucion == true) {
            if (max_menor >= v[i]) solucion = false;
            else ++i;
        }
    }
    return solucion;
}

void resuelveCaso() {
    int elem_vector;
    cin >> elem_vector;
    int separar;
    cin >> separar;

    vector<int> vector(elem_vector);
    for (int i = 0; i < elem_vector; ++i) cin >> vector[i];

    bool solucion = vectorMenor(vector, separar);
    if (solucion == true) cout << "SI\n";
    else cout << "NO\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}