// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int buscarIz(vector<int> const& v, int x, int ini, int fin) {
    if (ini == fin) return ini;      //Vector vacio
    else if (ini + 1 == fin) return ini;      //Vector de 1 elemento
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] < x) return buscarIz(v, x, mitad + 1, fin);
        else return buscarIz(v, x, ini, mitad + 1);
    }
}

int buscarDr(vector<int> const& v, int x, int ini, int fin) {
    if (ini == fin) return ini;      //Vector vacio
    else if (ini + 1 == fin) return ini;      //Vector de 1 elemento
    else {
        int mitad = (ini + fin) / 2;
        if (x < v[mitad]) return buscarDr(v, x, ini, mitad);
        else return buscarDr(v, x, mitad, fin);
    }
}

bool resuelveCaso() {

    int num_sospechosos; cin >> num_sospechosos;

    if (!std::cin)
        return false;

    int altura; cin >> altura;
    vector<int> sospechosos(num_sospechosos);
    for (int i = 0; i < sospechosos.size(); ++i) cin >> sospechosos[i];

    int primer_valor = buscarIz(sospechosos, altura, 0, sospechosos.size());
    if (primer_valor == sospechosos.size() || sospechosos[primer_valor] != altura) cout << "NO EXISTE\n";
    else {
        int ultimo_valor = buscarDr(sospechosos, altura, 0, sospechosos.size());
        if (primer_valor == ultimo_valor) cout << primer_valor << '\n';
        else cout << primer_valor << ' ' << ultimo_valor << '\n';
    }

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}