// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void VA(vector<vector<int>> const& tiempos, vector<int>& sol, int& tiempoMin, int& tiempoAct, int k, vector<bool>& marcas, vector<int> const& acum) {
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
            else {
                if (tiempoAct + acum[k + 1] < tiempoMin) {
                    VA(tiempos, sol, tiempoMin, tiempoAct, k + 1, marcas, acum);
                }
            }
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

    vector<int> acum(n);
    for (int i = 0; i < n; ++i) {
        int aux = tiempos[i][0];
        for (int j = 1; j < n; ++j) {
            if (tiempos[i][j] < aux) {
                aux = tiempos[i][j];
            }
        }
        acum[i] = aux;
    }

    for (int i = n - 1; i > 0; --i) {
        acum[i - 1] += acum[i];
    }

    VA(tiempos, sol, tiempoMin, tiempoAct, 0, marcas, acum);
    cout << tiempoMin << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
