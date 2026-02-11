// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct tSolucion {
    bool presentado;
    int partidos;
    int ronda;
};

tSolucion resolver(vector<string> const& v, int ronda, int ini, int fin) {
    tSolucion sol;
    if (ini + 2 == fin) {
        if (v[ini] == "NP" && v[fin - 1] == "NP") {
            sol.partidos = 0;
            sol.presentado = false;
            sol.ronda = 1;
        }
        else if (v[ini] == "NP" || v[fin - 1] == "NP") {
            sol.partidos = 0;
            sol.presentado = true;
            sol.ronda = 1;
        }
        else {
            sol.partidos = 1; 
            sol.presentado = true;
            sol.ronda = 1;
        }
        return sol;
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        tSolucion sol_izq = resolver(v, ronda, ini, mitad + 1);
        tSolucion sol_dcha = resolver(v, ronda, mitad + 1, fin);
        sol.ronda = sol_dcha.ronda + 1;
        sol.presentado = sol_izq.presentado || sol_dcha.presentado;
        sol.partidos = sol_izq.partidos + sol_dcha.partidos;
        if (sol.ronda <= ronda) {
            if (sol_izq.presentado && sol_dcha.presentado) {
                sol.partidos++;
            }
        }
        return sol;
    }
}

bool resuelveCaso() {
    int num_jugadores; cin >> num_jugadores;

    if (!std::cin)
        return false;

    int num_ronda; cin >> num_ronda;
    vector<string> v(num_jugadores);
    for (int i = 0; i < num_jugadores; ++i) cin >> v[i];

    cout << resolver(v, num_ronda, 0, num_jugadores).partidos << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}