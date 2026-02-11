// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int NUM_COLORES = 3;

/*
Tenemos un árbol con altura_torre etapas.
En la primera etapa se coloca la primera pieza, que en este problema tiene que ser roja obligatoriamente, mientras que 
en el anterior problema podría ser de cualquiera de los 3 colores (roja, verde o azul). 
En la segunda etapa, se coloca una pieza de cualquiera de los 3 colores, y en la tercera, en el caso de que la pieza
colocada en la segunda etapa sea verde, no se puede repetir el color verde.
En general, el numero de etapas sera el numero de alturas de la torre de piezas, de
forma que en la etapa i-esima se genera la pieza i-esima de la torre (roja, verde o azul), teniendo en cuenta que 
si la pieza (i - 1)-esima es verde, la pieza i-esima no puede ser verde (en el anterior problema esta restriccion no se 
aplica, por lo que simplemente en la etapa i-esima se genera la pieza i-esima de la torre (roja, verde o azul))
*/

void escribirSolucion(vector <int> const& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) cout << "azul ";
        else if (v[i] == 1) cout << "rojo ";
        else cout << "verde ";
    }
}

bool esValida(vector<int> const& sol, int k) {
    bool devolver = true; 
    if (sol[k] == 2 && sol[k - 1] == 2) devolver = false;   //Dos elementos verdes seguidos
    return devolver;
}

void variaciones(int altura_torre, int k, vector<int>& sol) {
    for (int i = 0; i < NUM_COLORES; ++i) {
        sol[k] = i;
        if (esValida(sol, k)) {
            if (k == altura_torre - 1) { // Es solucion
                escribirSolucion(sol);
                cout << '\n';
            }
            else { // Sigue completando la solucion
                variaciones(altura_torre, k + 1, sol);
            }
        }
    }
}

bool resuelveCaso() {
    int altura_torre; cin >> altura_torre;

    if (altura_torre == 0)
        return false;

    vector<int> sol(altura_torre);
    sol[0] = 1;  //Primer elemento rojo
    if (altura_torre == 1) {
        escribirSolucion(sol);
        cout << '\n';
    }
    else variaciones(altura_torre, 1, sol);
    cout << '\n';

    return true;

}

int main() {
    while (resuelveCaso());
    return 0;
}