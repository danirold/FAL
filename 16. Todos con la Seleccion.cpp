// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int GANADO = 0;

void resolver(vector<int>& v) {
    int num_max_ganados = 0;
    int num_veces = 0;
    int num_jugados_racha = 0;
    int longAct = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > GANADO) {
            longAct++;
            if (num_max_ganados < longAct) {
                num_max_ganados = longAct;
                num_veces = 1;
                num_jugados_racha = 0;
            }
            else if (num_max_ganados == longAct) {
                num_veces++;
                num_jugados_racha = 0;
            }
            else if (num_max_ganados > longAct) ++num_jugados_racha;
        }
        else {
            longAct = 0;
            ++num_jugados_racha;
        }
    }
    cout << num_max_ganados << ' ' << num_veces << ' ' << num_jugados_racha;
    cout << '\n';
}

bool resuelveCaso() {
    int num_partidos;
    cin >> num_partidos;

    if (!std::cin)
        return false;

    vector<int> vector1(num_partidos);
    for (int i = 0; i < vector1.size(); ++i) cin >> vector1[i];
    resolver(vector1);

    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}