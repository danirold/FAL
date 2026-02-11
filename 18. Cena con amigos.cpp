// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v) {
    int sumaMax = 0; int comienzo = 0; int longitudMax = 0;
    int sumaAct = 0; int longitudAct = 0;

    for (int i = 0; i < v.size(); ++i) {
        sumaAct += v[i];
        if (sumaAct > 0) {
            longitudAct++;
            if (sumaMax < sumaAct) {
                sumaMax = sumaAct;
                longitudMax = longitudAct;
                comienzo = i - longitudMax + 1;
            }
            else if (sumaMax == sumaAct && longitudAct < longitudMax) {
                longitudMax = longitudAct;
                comienzo = i - longitudMax + 1;
            }
        }
        else {
            sumaAct = 0;
            longitudAct = 0;
        }
    }

    cout << sumaMax << ' ' << comienzo << ' ' << longitudMax << '\n';
}

bool resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;

    if (!std::cin)
        return false;

    vector<int> vector1(tamano_vector);
    for (int i = 0; i < vector1.size(); ++i) cin >> vector1[i];

    resolver(vector1);

    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}