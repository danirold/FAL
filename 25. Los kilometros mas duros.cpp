// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v, const int longitud) {
    int sumaMax = 0; int sumaAct = 0; int tramo_comienzo = 0; int tramo_final = 0;

    for (int i = 0; i < longitud; ++i) sumaMax += v[i];
    sumaAct = sumaMax;
    for (int i = longitud; i < v.size(); ++i) {
        sumaAct -= v[i - longitud];
        sumaAct += v[i];
        if (sumaMax < sumaAct) {
            sumaMax = sumaAct;
            tramo_comienzo = i - longitud + 1;
            tramo_final = tramo_comienzo;
        }
        else if (sumaMax == sumaAct) tramo_final = i - longitud + 1;
    }

    cout << sumaMax << ' ' << tramo_comienzo << ' ' << tramo_final << '\n';
}

bool resuelveCaso() {
    int num_kilom; cin >> num_kilom;
    int longitud_tramo; cin >> longitud_tramo;

    if (num_kilom == 0 && longitud_tramo == 0)
        return false;

    vector<int> kilometros(num_kilom);
    for (int i = 0; i < kilometros.size(); ++i) cin >> kilometros[i];

    resolver(kilometros, longitud_tramo);

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}