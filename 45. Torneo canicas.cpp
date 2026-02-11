// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {
    string nombre;
    int canicas;
};

tDatos resolver(vector<tDatos> const& v, int ini, int fin) {
    tDatos ganador;
    if (ini + 2 == fin) {
        if (v[ini].canicas >= v[ini + 1].canicas) {
            ganador.nombre = v[ini].nombre;
            ganador.canicas = v[ini].canicas + v[ini + 1].canicas / 2;
        }
        else {
            ganador.nombre = v[ini + 1].nombre;
            ganador.canicas = v[ini + 1].canicas + v[ini].canicas / 2;
        }
        return ganador;
    }
    else {
        int m = (ini + fin - 1) / 2;
        tDatos ganador_izq = resolver(v, ini, m + 1);
        tDatos ganador_dcha = resolver(v, m + 1, fin);
        if (ganador_izq.canicas >= ganador_dcha.canicas) {
            ganador.nombre = ganador_izq.nombre;
            ganador.canicas = ganador_izq.canicas + ganador_dcha.canicas / 2;
        }
        else {
            ganador.nombre = ganador_dcha.nombre;
            ganador.canicas = ganador_dcha.canicas + ganador_izq.canicas / 2;
        }
        return ganador;
    }
}

bool resuelveCaso() {
    int tamano_vector; cin >> tamano_vector;
    if (!std::cin)
        return false;

    vector<tDatos> v(tamano_vector);
    for (int i = 0; i < tamano_vector; ++i) {
        cin >> v[i].nombre >> v[i].canicas;
    }

    tDatos sol = resolver(v, 0, tamano_vector);
    cout << sol.nombre << ' ' << sol.canicas << '\n';
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
