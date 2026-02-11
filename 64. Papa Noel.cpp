// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void escribirSol(vector<int> const& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

bool esValida(vector<string> const& nombre_jug, vector<int>& sol, vector<int>& satisfacciones, int const& satis_min, int k) {
    if (k % 2 == 1) {
        if (sol[k] < sol[k - 1]) {
            return false;
        }
        if (k == 1 && satisfacciones[0] < satis_min) {
            return false;
        }
        if (k != 1 && satisfacciones[k / 2] < satis_min) {
            return false;
        }
        if (nombre_jug[sol[k]] == nombre_jug[sol[k - 1]]) {
            return false;
        }
        return true;
    }
    return true;
}

int VA(vector<int>& unid_jug, vector<string> const& nombre_jug, vector<vector<int>> const& satis_ninos, vector<int>& sol, vector<int>& satisfacciones, int const& satis_min, int k) {
    int num_soluc = 0;
    for (int i = 0; i < nombre_jug.size(); ++i) {
        if (unid_jug[i] > 0) {
            sol[k] = i;
            unid_jug[i]--;
            if (k % 2 == 0) {
                satisfacciones[k / 2] += satis_ninos[k/2][i];
            }
            else {
                if (k == 1) {
                    satisfacciones[0] += satis_ninos[0][i];
                }
                else {
                    satisfacciones[k / 2] += satis_ninos[k / 2][i];
                }
            }
            if (esValida(nombre_jug, sol, satisfacciones, satis_min, k)) {
                if (k == sol.size() - 1) {
                    num_soluc++;
                    escribirSol(sol);
                }
                else num_soluc += VA(unid_jug, nombre_jug, satis_ninos, sol, satisfacciones, satis_min, k + 1);
            }
            if (k % 2 == 0) {
                satisfacciones[k / 2] -= satis_ninos[k / 2][i];
            }
            else {
                if (k == 1) {
                    satisfacciones[0] -= satis_ninos[0][i];
                }
                else {
                    satisfacciones[k / 2] -= satis_ninos[k / 2][i];
                }
            }
            unid_jug[i]++;
        }
    }
    return num_soluc;
}

bool resuelveCaso() {
    int num_jug, ninos, satis;
    cin >> num_jug >> ninos >> satis;

    if (!std::cin)
        return false;

    vector<int> unid_jug(num_jug);
    for (int i = 0; i < num_jug; ++i) {
        cin >> unid_jug[i];
    }

    vector<string> nombre_jug(num_jug);
    for (int i = 0; i < num_jug; ++i) {
        cin >> nombre_jug[i];
    }

    vector<vector<int>> satis_ninos(ninos, vector<int>(num_jug, 0));
    for (int i = 0; i < ninos; ++i) {
        for (int j = 0; j < num_jug; ++j) {
            cin >> satis_ninos[i][j];
        }
    }

    vector<int> sol(ninos * 2);
    vector<int> satisfacciones(ninos);

    int solucion = VA(unid_jug, nombre_jug, satis_ninos, sol, satisfacciones, satis, 0);
    if (solucion == 0) {
        cout << "SIN SOLUCION\n";
    }

    cout << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}