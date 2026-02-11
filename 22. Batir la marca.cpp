// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int>& v1) {
    int longAct = 0; int longMax = 0; int max = v1[0]; int posicion_comienzo = 0;
    for (int i = 1; i < v1.size(); ++i) {
        if (v1[i] <= max) {
            longAct++;
            if (longMax <= longAct) {
                longMax = longAct;
                posicion_comienzo = i - longAct + 1;
            }
        }
        else {
            max = v1[i];
            longAct = 0;
        }
    }
    if (longMax == 0) longMax = v1.size();
    cout << longMax << ' ' << posicion_comienzo << '\n';
}

bool resuelveCaso() {
    int num_pruebas; cin >> num_pruebas;

    if (num_pruebas == 0)
        return false;

    vector<int> pruebas(num_pruebas);

    for (int i = 0; i < pruebas.size(); ++i) cin >> pruebas[i];

    resolver(pruebas);

    return true;
}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}