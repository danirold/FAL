// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

/*El coste del algoritmo es lineal. El bucle de la funcion resolver da v1.size vueltas y cada vuelta tiene coste constante
por tratarse de operaciones aritmeticas y asignaciones.
El bucle de la funcion resuelveCaso da num_edificios vueltas y cada vuelta tiene coste constante por tratarse de una operacion de lectura.
Por tanto, el coste es lineal, del coste del orden O(num_edificios), sabiendo que v1.size = num_edificios
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v1, int altura) {
    int longMax = 0; int longAct = 0; int iniMax = 0; int finalMax = 0;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] > altura) { //Bueno
            longAct++;
            if (longMax < longAct) {
                longMax = longAct;
                iniMax = i - longAct + 1;
                finalMax = i;
            }
        }
        else longAct = 0;
    }
    cout << iniMax << ' ' << finalMax << '\n';
}

void resuelveCaso() {
    int num_edificios; cin >> num_edificios;
    int altura; cin >> altura;
    vector<int> vector1(num_edificios);

    for (int i = 0; i < num_edificios; ++i) cin >> vector1[i];

    resolver(vector1, altura);
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}