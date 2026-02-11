// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v, const int longitud_tramo) {
    int sumaMin = v.size() + 1; int sumaAct = 0;
    vector<int> vector_aux;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) vector_aux.push_back(i);
    }

    if (longitud_tramo <= vector_aux.size()) {
        sumaAct = vector_aux[longitud_tramo - 1] - vector_aux[0] + 1;
        if (sumaAct < sumaMin) sumaMin = sumaAct;
        for (int i = longitud_tramo; i < vector_aux.size(); ++i) {
            sumaAct = vector_aux[i] - vector_aux[i - longitud_tramo + 1] + 1;
            if (sumaAct < sumaMin) sumaMin = sumaAct;

        }
    }

    cout << sumaMin << '\n';
}

bool resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;

    if (tamano_vector == -1)
        return false;

    vector<int> booleanos(tamano_vector);
    for (int i = 0; i < booleanos.size(); ++i) cin >> booleanos[i];

    int valor_secuencia_minima; cin >> valor_secuencia_minima;

    resolver(booleanos, valor_secuencia_minima);

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}