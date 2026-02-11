// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int resolver(vector<int> & v, int ini, int fin) {
    if (ini + 1 == fin) return 0;
    else if (ini + 2 == fin) {
        if (v[ini] < v[ini + 1]) return 0;
        else {
            swap(v[ini], v[ini + 1]);
            return 1;
        }
    }
    else {
        int num_unid_tiemp = 0;
        int mitad = (ini + fin) / 2;
        int unid_tiemp_izq = resolver(v, ini, mitad);
        int unid_tiemp_dcha = resolver(v, mitad, fin);
        num_unid_tiemp = unid_tiemp_izq + unid_tiemp_dcha;

        int i = ini; int j = mitad;
        while (j < fin && i < mitad) {
            if (v[j] < v[i]) {
                num_unid_tiemp += mitad - i;
                ++j;
            }
            else ++i;
        }
        vector <int> vector_aux(fin - ini);
        i = ini; j = mitad; int k = 0;
        while (i < mitad || j < fin) {
            if (i == mitad) {
                vector_aux[k] = v[j];
                ++j;
            }
            else if (j == fin) {
                vector_aux[k] = v[i];
                ++i;
            }
            else if (v[i] <= v[j]) {
                vector_aux[k] = v[i];
                ++i;
            }
            else {
                vector_aux[k] = v[j];
                ++j;
            }
            ++k;
        }
        
        for (int i = ini; i < fin; ++i) {
            v[i] = vector_aux[i - ini];
        }

        return num_unid_tiemp;
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