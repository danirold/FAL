// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int> & sol, int k, vector<string> const& tipos_juguete) {
    bool dev = true;
    if ((k % 2 == 1) && (tipos_juguete[sol[k]] == tipos_juguete[sol[k - 1]])) dev = false;
    else if ((k % 2 == 1) && sol[k - 1] > sol[k]) dev = false;
    return dev;
}

void escribirSolucion(vector<int> const& sol) {
    for (int i = 0; i < sol.size(); ++i) cout << sol[i] << ' ';
    cout << '\n';
}

int variaciones(vector<string> const& tipos_juguete, vector<int> & sol, int k) {
    int num_soluciones = 0;
    for (int i = 0; i < tipos_juguete.size(); ++i) {
        sol[k] = i;
        if (esValida(sol, k, tipos_juguete)) {
            if (k == sol.size() - 1) {
                num_soluciones++;
                escribirSolucion(sol);
            }
            else num_soluciones += variaciones(tipos_juguete, sol, k + 1);
        }
    }
    return num_soluciones;
}

bool resuelveCaso() {
    int num_tipos_juguete; cin >> num_tipos_juguete;

    if (!std::cin)
        return false;
    int num_ninos; cin >> num_ninos;
    vector<string> tipos_juguete(num_tipos_juguete);
    for (int i = 0; i < num_tipos_juguete; ++i) cin >> tipos_juguete[i];

    vector<int> regalos_ninos(2 * num_ninos);
    int solucion = variaciones(tipos_juguete, regalos_ninos, 0);
    if (solucion == 0) cout << "SIN SOLUCION\n";
    cout << '\n';
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}