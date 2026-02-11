// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v1, vector<int> const& v2, vector<int>& vectorFinal) {
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            vectorFinal.push_back(v1[i]);
            ++i;
        }

        else if (v1[i] > v2[j]) {
            vectorFinal.push_back(v2[j]);
            ++j;
        }

        else {
            ++i; ++j;
        }
    }

    while (i < v1.size()) {
        vectorFinal.push_back(v1[i]);
        ++i;
    }

    while (j < v2.size()) {
        vectorFinal.push_back(v2[j]);
        ++j;
    }
}

void resuelveCaso() {

    vector<int> vector1;
    vector<int> vector2;
    int valor_vector; cin >> valor_vector;
    while (valor_vector != 0) {
        vector1.push_back(valor_vector);
        cin >> valor_vector;
    }
    cin >> valor_vector;
    while (valor_vector != 0) {
        vector2.push_back(valor_vector);
        cin >> valor_vector;
    }
    vector<int> vectorFinal;
    resolver(vector1, vector2, vectorFinal);
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