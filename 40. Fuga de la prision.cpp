// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

char resolver(vector<char> const& v, int ini, int fin, char primer_char, char ultimo_char) {
    if (v[ini] != primer_char) return primer_char;
    else if (v[fin - 1] != ultimo_char) return ultimo_char;
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] - v[mitad - 1] == 2) return v[mitad - 1] + 1;
        else if (v[mitad + 1] - v[mitad] == 2) return v[mitad] + 1;
        else if (v[mitad] - v[ini] > mitad - ini) return resolver(v, ini, mitad + 1, primer_char, v[mitad]);
        else return resolver(v, mitad, fin, v[mitad], ultimo_char);
    }
}

void resuelveCaso() {
    char primera_letra; cin >> primera_letra;
    char ultima_letra; cin >> ultima_letra;
    int tamano_vector = ultima_letra - primera_letra;

    vector<char> v(tamano_vector);
    for (int i = 0; i < tamano_vector; ++i) cin >> v[i];

    cout << resolver(v, 0, tamano_vector, primera_letra, ultima_letra) << '\n';
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}