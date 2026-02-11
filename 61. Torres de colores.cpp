// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int M = 3;

void escribirSol(vector<int> const& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) cout << "azul ";
        else if (v[i] == 1) cout << "rojo ";
        else {
            cout << "verde ";
        }
    }
    cout << '\n';
}

bool esValida(vector<int> const& sol, vector<int> const& colores_usados, int k) {
    if (sol[k] == 2 && sol[k - 1] == 2) {
        return false;
    }
    if (colores_usados[2] > colores_usados[0]) {
        return false;
    }
    return true;
}

void VA(int const& n, vector<int>& colores_total, vector<int>& sol, vector<int>& colores_usados, int k, int& num_solu) {
    for (int i = 0; i < M; ++i) {
        if (colores_total[i] > 0) {
            sol[k] = i;
            colores_total[i]--;
            colores_usados[i]++;
            if (esValida(sol, colores_usados, k)) {
                if (k == n - 1) {
                    if (colores_usados[1] > colores_usados[0] + colores_usados[2]) {
                        escribirSol(sol);
                        num_solu++;
                    }
                }
                else VA(n, colores_total, sol, colores_usados, k + 1, num_solu);
            }
            colores_total[i]++;
            colores_usados[i]--;
        }
    }
}

bool resuelveCaso() {
    int n, azules, rojas, verdes;
    cin >> n >> azules >> rojas >> verdes;

    if (n == 0 && azules == 0 && rojas == 0 && verdes == 0)
        return false;

    vector<int> sol(n);
    vector<int> total_colores(M);
    vector<int> colores_usados(M);

    total_colores[0] = azules; total_colores[1] = rojas; total_colores[2] = verdes;

    if (total_colores[1] != 0) {
        sol[0] = 1;
        total_colores[1]--;
        colores_usados[1]++;
    }
    if (n == 1) {
        if (sol.empty()) cout << "SIN SOLUCION\n";
        else escribirSol(sol);
    }
    else {
        if (sol.empty()) cout << "SIN SOLUCION\n";
        else {
            int num_sol = 0;
            VA(n, total_colores, sol, colores_usados, 1, num_sol);
            if (num_sol == 0) {
                cout << "SIN SOLUCION\n";
            }
        }
    }
    cout << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
