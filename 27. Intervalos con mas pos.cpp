// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v, int long_pedida) {
    int media = long_pedida / 2;
    int positivos_izq = 0; int positivos_dcha = 0;
    int intervalos_correctos = 0;
        
    for (int i = 0; i < media; ++i) {
        if (v[i] > 0) positivos_izq++;
    }

    for (int i = media; i < long_pedida; ++i) {
        if (v[i] > 0) positivos_dcha++;
    }

    if (positivos_izq >= positivos_dcha) intervalos_correctos++;

    for (int i = long_pedida; i < v.size(); ++i) {
        if (v[i - long_pedida] > 0) positivos_izq--;
        if (v[i] > 0) positivos_dcha++;
        if (v[i - long_pedida + media] > 0) {
            positivos_izq++;
            positivos_dcha--;
        }
        if (positivos_izq >= positivos_dcha) intervalos_correctos++;
    }

    cout << intervalos_correctos << '\n';
}

bool resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;

    if (tamano_vector == 0)
        return false;

    int long_intervalo; cin >> long_intervalo;
    vector<int> v(tamano_vector);
    for (int i = 0; i < v.size(); ++i) cin >> v[i];
    resolver(v, long_intervalo);

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}