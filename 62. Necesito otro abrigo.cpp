// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int> const& precip, vector<int> const& lluvia_abrigos, int k, vector<int>& sol, vector<int>& marcas, int i) {
    if (lluvia_abrigos[i] < precip[k]) return false;     //El abrigo no soporta la lluvia
    if (k > 0 && sol[k] == sol[k - 1]) return false;     //No repito el mismo abrigo dos dias
    if (marcas[i] > 2 + k / 3) return false;             //No me pongo un abrigo muchos mas dias que otro
    else return true;
}

int variaciones(vector<int> const& precip, vector<int> const& lluvia_abrigos, int k, vector<int> & sol, vector<int> & marcas) {
    int num_soluciones = 0;
    for (int i = 0; i < lluvia_abrigos.size(); ++i) {
        sol[k] = i; 
        ++marcas[i];
        if (esValida(precip, lluvia_abrigos, k, sol, marcas, i)) {
            if (k == precip.size() - 1) {
                if (sol[0] != sol[k]) num_soluciones++;
            }
            else num_soluciones+= variaciones(precip, lluvia_abrigos, k + 1, sol, marcas);
        }
        --marcas[i];
    }
    return num_soluciones;
}

bool resuelveCaso() {
    int num_dias; int num_abrigos;
    cin >> num_dias >> num_abrigos;

    if (num_dias == 0 && num_abrigos == 0)
        return false;

    vector<int> precip(num_dias);
    for (int i = 0; i < num_dias; ++i) cin >> precip[i];
    vector<int> lluvia_abrigos(num_abrigos);
    for (int i = 0; i < num_abrigos; ++i) cin >> lluvia_abrigos[i];

    vector<int> sol(num_dias);
    vector<int> marcas(num_abrigos);
    int solucion = variaciones(precip, lluvia_abrigos, 0, sol, marcas);
    if (solucion == 0) cout << "Lo puedes comprar\n";
    else cout << solucion << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}