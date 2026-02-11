#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void resolver(vector<int> const& dados, int valor_max, vector<int>& vectorFinal) {
    vector<int> aux(valor_max);
    for (int i = 0; i < dados.size(); ++i) {
        ++aux[dados[i] - 1];
    }
    int max = aux[0];
    for (int i = 1; i < aux.size(); ++i) {
        if (aux[i] > max) max = aux[i];
    }
    for (int i = 0; i < valor_max; ++i) {
        if (aux[i] == max) vectorFinal.push_back(i + 1);
    }
}

bool resuelveCaso() {
    int num_tiradas;
    cin >> num_tiradas;

    if (num_tiradas == -1)
        return false;

    int valor_maximo; cin >> valor_maximo;
    vector<int> tiradas(num_tiradas);
    for (int i = 0; i < num_tiradas; ++i) cin >> tiradas[i];

    vector<int> vectorFinal;
    resolver(tiradas, valor_maximo, vectorFinal);

    for (int i = vectorFinal.size() - 1; i >= 0; --i) cout << vectorFinal[i] << ' ';
    cout << "\n";

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}