// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v, int paginas_leer) {
    int sumaMax = 0; int sumaAct = 0; int pagina_comienzo = 0;

    for (int i = 0; i < paginas_leer; ++i) sumaMax += v[i];
    sumaAct = sumaMax;
    for (int i = paginas_leer; i < v.size(); ++i) {
        sumaAct -= v[i - paginas_leer];
        sumaAct += v[i];
        if (sumaMax <= sumaAct) {
            sumaMax = sumaAct;
            pagina_comienzo = i - paginas_leer + 1;
        }
    }

    cout << pagina_comienzo << '\n';
}

bool resuelveCaso() {
    int num_paginas; cin >> num_paginas;
    int cantidad_leer; cin >> cantidad_leer;

    if (num_paginas == 0 && cantidad_leer == 0)
        return false;

    vector<int> paginas(num_paginas);
    for (int i = 0; i < paginas.size(); ++i) cin >> paginas[i];

    resolver(paginas, cantidad_leer);

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}
