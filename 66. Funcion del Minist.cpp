// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void VA(vector<vector<int>> const& tiempos, vector<int> & sol, int & tiempoMin, int & tiempoAct, int k, vector<bool> & marcas) {
    for (int i = 0; i < sol.size(); ++i) {
        sol[k] = i;
        if (!marcas[i]) {
            marcas[i] = true;
            tiempoAct += tiempos[k][i];
            if (k == sol.size() - 1) {
                if (tiempoAct < tiempoMin) {
                    tiempoMin = tiempoAct;
                }
            }
            else VA(tiempos, sol, tiempoMin, tiempoAct, k + 1, marcas);
            marcas[i] = false;
            tiempoAct -= tiempos[k][i];
        }
    }
}

bool resuelveCaso() {
    int n; cin >> n;

    if (n == 0)
        return false;

    vector<vector<int>> tiempos(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tiempos[i][j];
        }
    }

    vector<int> sol(n);
    int tiempoMin = 0;
    vector<bool> marcas(n, false);

    for (int i = 0; i < n; ++i) {
        tiempoMin += tiempos[i][i];
    }

    int tiempoAct = 0;

    VA(tiempos, sol, tiempoMin, tiempoAct, 0, marcas);
    cout << tiempoMin << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
