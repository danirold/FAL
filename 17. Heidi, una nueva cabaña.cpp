// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const & v, vector<int> & solucion, int condicion) {
    int num_max_secuencia = 0; int num_secuencias = 0;
    int longAct = 1; int max_dcha = v[v.size() - 1];

    for (int i = v.size() - 1; i > 0; --i) {
        if(v[i] >= max_dcha) max_dcha = v[i];
        if (v[i] == v[i - 1] && v[i] >= max_dcha) {
            max_dcha = v[i];
            longAct++;
            if (condicion <= longAct) {
                if (num_max_secuencia < longAct) {
                        num_max_secuencia = longAct;
                        solucion[num_secuencias] = i + longAct - 2;
                        num_secuencias++;
                }
                else if (num_max_secuencia >= longAct) {
                        solucion[num_secuencias] = i + longAct - 2;
                        num_secuencias++;
                }
            }
        }
        else longAct = 1;
    }
    solucion.resize(num_secuencias);
    if (num_secuencias != 0) {
        int buenos = 1; int repetido = solucion[0];
        for (int i = 1; i < solucion.size(); ++i) {
            if (solucion[i] != repetido) {
                repetido = solucion[i];
                solucion[buenos] = solucion[i];
                ++buenos;
            }
        }
        solucion.resize(buenos);
        num_secuencias = buenos;
    }

    cout << num_max_secuencia << ' ' << num_secuencias << ' ';
    for (int i = 0; i < solucion.size(); ++i) cout << solucion[i] << ' ';
    cout << '\n';
}

bool resuelveCaso() {
    int num_datos; cin >> num_datos;
    int iguales_necesitan; cin >> iguales_necesitan;

    if (!std::cin)
        return false;

    vector<int> vector1(num_datos);
    for (int i = 0; i < vector1.size(); ++i) cin >> vector1[i];

    vector<int> solucion(num_datos);
    resolver(vector1, solucion, iguales_necesitan);

    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}