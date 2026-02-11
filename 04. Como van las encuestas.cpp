// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void hacerMedia(vector<int> const& v) {
    long long int media = 0; int num_datos = 0;
    long long int minimo = v[0];
    int num_veces = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (minimo > v[i]) {
            media += minimo * num_veces;
            num_datos += num_veces;
            num_veces = 1;
            minimo = v[i];
        }
        else if (minimo < v[i]) {
            media += v[i];
            num_datos++;
        }
        else if (minimo == v[i]) num_veces++;
    }

    cout << media << ' ' << num_datos << '\n';
}

void resuelveCaso() {
    int elem_vector;
    cin >> elem_vector;

    vector<int> vector(elem_vector);
    for (int i = 0; i < elem_vector; ++i) cin >> vector[i];

    hacerMedia(vector);
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}