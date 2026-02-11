// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

/*El coste del algoritmo es lineal. El primer bucle da num_etapas vueltas y cada vuelta tiene coste constante 
por tratarse de dos operaciones, una de lectura y otra aritmetica. 
El segundo bucle da num_etapas vueltas y cada vuelta tiene coste constante por tratarse de una operacion aritmetica. 
El terecr bucle da num_preguntas vueltas y cada vuelta tiene coste constante por tratarse de dos operaciones, 
una de lectura y otra de escritura. 
Por tanto, el coste es lineal, del coste del orden O(max(num_etapas, num_preguntas)).
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool resuelveCaso() {
    int num_etapas; cin >> num_etapas;

    if (num_etapas == -1)
        return false;

    vector<int> kilometros(num_etapas);
    long long int suma_kil = 0;

    vector<long long int> kil_acumulados(num_etapas + 1);

    for (int i = 0; i < num_etapas; ++i) {
        cin >> kilometros[i];
        suma_kil += kilometros[i];
    }

    kil_acumulados[0] = suma_kil;
    for (int i = 1; i < num_etapas + 1; ++i) {
        kil_acumulados[i] = kil_acumulados[i - 1] - kilometros[i - 1];
    }


    int num_preguntas; cin >> num_preguntas;
    for (int i = 0; i < num_preguntas; ++i) {
        int dia; cin >> dia;
        cout << kil_acumulados[dia - 1] << '\n';
    }
    cout << "---\n";

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}