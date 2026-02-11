// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int resolver(vector<int> &v1) {
    sort(v1.begin(), v1.end());
    long long int longMax = 1; long long int longAct = 1; int valorRepetido = v1[0];
    for (long long int i = 1; i < v1.size(); ++i) {
        if (v1[i] == v1[i - 1]) { //Bueno
            longAct++;
            if (longMax < longAct) {
                longMax = longAct;
                valorRepetido = v1[i];
            }
            else if (longMax == longAct && v1[i] < valorRepetido) valorRepetido = v1[i];
        }
        else longAct = 1;
    }
    return valorRepetido;
}

bool resuelveCaso() {
    long long int kilometros; cin >> kilometros;

    if (kilometros == -1)
        return false;

    vector<int> accidentes(kilometros);

    for (long long int i = 0; i < kilometros; ++i) cin >> accidentes[i];

    cout << resolver(accidentes) << '\n';

    return true;
}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}