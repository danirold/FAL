// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& v, const int condicion, vector<int> & solucion) {
    int longAct = 1; int num_superf_encont = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        if (abs(v[i] - v[i + 1]) < 2) {
            longAct++;
            if (condicion <= longAct) {
                solucion[num_superf_encont] = i - longAct + 2;
                num_superf_encont++;
            }
        }
        else longAct = 1;
    }
    solucion.resize(num_superf_encont);
    if (num_superf_encont != 0) {
        int buenos = 1; int repetido = solucion[0];
        for (int i = 1; i < solucion.size(); ++i) {
            if (solucion[i] != repetido) {
                repetido = solucion[i];
                solucion[buenos] = solucion[i];
                ++buenos;
            }
        }
        solucion.resize(buenos);
        num_superf_encont = buenos;
    }

    cout << num_superf_encont << ' ';
    for (int i = 0; i < solucion.size(); ++i) cout << solucion[i] << ' ';
    cout << '\n';
    
}

bool resuelveCaso() {
    int datos_tomados; cin >> datos_tomados;
    int casi_iguales; cin >> casi_iguales;

    if (datos_tomados == 0 && casi_iguales == 0)
        return false;

    vector<int> datos(datos_tomados);
    for (int i = 0; i < datos.size(); ++i) cin >> datos[i];

    vector<int> solucion(datos_tomados);
    resolver(datos, casi_iguales, solucion);

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}