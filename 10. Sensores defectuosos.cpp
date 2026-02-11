// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<long long int> & v, int error) {
    int buenos = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != error) {
            v[buenos] = v[i];
            ++buenos;
        }
    }
    v.resize(buenos);
    cout << buenos << "\n";
    for (int i = 0; i < buenos; ++i) cout << v[i] << ' ';
}

void resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;
    int num_error; cin >> num_error;
    vector<long long int> vector(tamano_vector);
    for (int i = 0; i < tamano_vector; ++i) cin >> vector[i];

    resolver(vector, num_error);
    cout << "\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}