// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool resuelveCaso() {
    long long int numero_anos;
    cin >> numero_anos;

    if (numero_anos == 0)
    return false;
    
    string nacionalidad;
    cin >> nacionalidad;

    vector<string> vector(numero_anos);
    for (int i = 0; i < numero_anos; ++i) {
        cin >> vector[i];
    }

    long long int anos_ganador = 0;
    bool parar = true;

    for (int i = numero_anos - 1; i >= 0 && parar; --i) {
        if (nacionalidad == vector[i]) {
            anos_ganador = numero_anos - i;
            parar = false;
        }
    }

    if (anos_ganador == 0) cout << "NUNCA\n";
    else cout << anos_ganador << '\n';
    return true;
}

int main() {

    while (resuelveCaso())
        ;
    return 0;
}