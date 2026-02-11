// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

/*El coste del algoritmo es lineal. El primer bucle da vagones_robo vueltas y cada vuelta tiene coste constante
por tratarse de una operacion aritmetica.
El segundo bucle da (v.size() - vagones_robo) vueltas y cada vuelta tiene coste constante por tratarse de dos operaciones aritmeticas 
más un condicional, que en el caso de acceder a él, también tiene coste constante pues contiene dos operaciones, una de asignacion y otra aritmetica.
Por tanto, el coste es lineal, del coste del orden O(max(vagones_robo, (v.size() - vagones_robo))).
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v, int vagones_robo) {
    int sumaMax = 0; int sumaAct = 0; int vagon_comienzo = 0;
    
    for (int i = 0; i < vagones_robo; ++i) sumaMax += v[i];
    sumaAct = sumaMax;
    for (int i = vagones_robo; i < v.size(); ++i) {
        sumaAct -= v[i - vagones_robo];
        sumaAct += v[i];
        if (sumaMax <= sumaAct) {
            sumaMax = sumaAct;
            vagon_comienzo = i - vagones_robo + 1;
        }
    }

    cout << vagon_comienzo << ' ' << sumaMax << '\n';
}

void resuelveCaso() {
    int num_vagones; cin >> num_vagones;
    int robados; cin >> robados;

    vector<int> rob(num_vagones);
    for (int i = 0; i < rob.size(); ++i) cin >> rob[i];

    resolver(rob, robados);
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}