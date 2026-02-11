// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
    bool correct;
    int suma;
};

tSolucion resolver(vector<int> const& v, int ini, int fin) {
    tSolucion solucion;
    if (ini + 1 >= fin) {
        solucion.correct = true;
        solucion.suma = v[ini];
        return solucion;
    }
    else {
        int m = (ini + fin - 1) / 2;
        tSolucion sol_izq = resolver(v, ini, m + 1);
        tSolucion sol_dcha = resolver(v, m + 1, fin);
        solucion.correct = sol_izq.correct && sol_dcha.correct && sol_izq.suma < sol_dcha.suma;
        solucion.suma = sol_izq.suma + sol_dcha.suma;
        return solucion;
    }
}

bool resuelveCaso() {
    int num_filas; cin >> num_filas;

    if (!std::cin)
        return false;

    int num_cols; cin >> num_cols;
    vector<vector<int>> v(num_filas, vector<int>(num_cols));
    for (int i = 0; i < num_filas; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            cin >> v[i][j];
        }
    }

    int filaAct = 0;
    while (filaAct < num_filas && resolver(v[filaAct], 0, num_cols).correct) filaAct++;

    if (filaAct < num_filas) cout << "NO\n";
    else cout << "SI\n";
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}