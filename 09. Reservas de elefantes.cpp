// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& elefantes, vector<long long int> & vectorFinal) {
    vectorFinal[0] = 0;
    for (int i = 1; i < vectorFinal.size(); ++i) {
        vectorFinal[i] = vectorFinal[i - 1] + elefantes[i - 1];
    }
}

bool resuelveCaso() {
    int primer_ano; cin >> primer_ano;
    int segundo_ano; cin >> segundo_ano;

    if (primer_ano == 0 && segundo_ano == 0)
        return false;

    int long_vector = segundo_ano - primer_ano + 1;
    vector<int> num_elef(long_vector);
    for (int i = 0; i < long_vector; ++i) cin >> num_elef[i];

    vector<long long int> vectorFinal(num_elef.size() + 1);
    resolver(num_elef, vectorFinal);

    int num_preguntas; cin >> num_preguntas;
    for (int i = 0; i < num_preguntas; ++i) {
        int ano1; int ano2;
        cin >> ano1 >> ano2;
        cout << vectorFinal[ano2 - primer_ano + 1] - vectorFinal[ano1 - primer_ano] << '\n';
    }
    cout << "---\n";

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}