// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v) {
    int longMax = 1; int longAct = 1; int suma_creciente = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > v[i - 1]) {
            suma_creciente++;
            if (suma_creciente < 3) {
                longAct++;
                if (longMax < longAct) {
                    longMax = longAct;
                }
            }
            else {    
                suma_creciente = 2;
                longAct = 2;
            }
        }

        else {
            suma_creciente = 1;
            longAct++;
            if (longMax < longAct) {
                longMax = longAct;
            }
        }
    }
    if (v.size() == 0) longMax = 0;
    cout << longMax << '\n';
}

void resuelveCaso() {
    int num_elem; cin >> num_elem;
    vector<int> vector(num_elem);

    for (int i = 0; i < vector.size(); ++i) cin >> vector[i];
    resolver(vector);
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}