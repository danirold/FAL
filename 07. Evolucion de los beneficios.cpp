// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<long long int> const& v, int ano, vector<int> &vectorVentas) {
    long long int max = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > max) {
            vectorVentas.push_back(ano + i);
            max = v[i];
        }
    }
}

void resuelveCaso() {
    int primer_ano; cin >> primer_ano;
    int segundo_ano; cin >> segundo_ano;

    int long_vector = segundo_ano - primer_ano + 1;
    vector<long long int> vector1(long_vector);
    for (int i = 0; i < long_vector; ++i) cin >> vector1[i];

    vector<int> vectorFinal;
    resolver(vector1, primer_ano, vectorFinal);
    for (int i = 0; i < vectorFinal.size(); ++i) cout << vectorFinal[i] << ' ';
    cout << '\n';

}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}