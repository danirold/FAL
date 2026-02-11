// Nombre del alumno: DANIEL ROLDAN SERRANO
// Usuario del Juez: DG25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void resolver(vector<int>& v, int peso_mediano, int peso_grande) {
    int i = 0; int j = v.size() - 1; int k = 0;
    while (k <= j) {
        if (v[k] >= peso_mediano && v[k] < peso_grande) ++k;
        else if (v[k] < peso_mediano) {
            swap(v[k], v[i]);
            ++k;
            ++i;
        }
        else {
            swap(v[k], v[j]);
            --j;
        }
    }
    sort(v.begin(), v.end());
    for (int r = 0; r < i; ++r) cout << v[r] << ' ';
    cout << '\n';
    for (int s = i; s < k; ++s) cout << v[s] << ' ';
    cout << '\n';
    for (int t = k; t < v.size(); ++t) cout << v[t] << ' ';
    cout << "\n---\n";
}

bool resuelveCaso() {
    int num_paquetes; cin >> num_paquetes;

    if (!std::cin)
        return false;

    int peso_mediano; cin >> peso_mediano;
    int peso_grande; cin >> peso_grande;
    vector<int> vector1(num_paquetes);
    for (int i = 0; i < vector1.size(); ++i) cin >> vector1[i];

    resolver(vector1, peso_mediano, peso_grande);

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}